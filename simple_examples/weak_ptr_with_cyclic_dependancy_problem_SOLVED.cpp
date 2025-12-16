#include <iostream>   // For std::cout
#include <memory>     // For std::shared_ptr and std::weak_ptr
using namespace std;

/*
    Forward declaration is still required because
    B_in_stack refers to A_in_stack before it is defined.
*/
class A_in_stack;

/*
    Class B_in_stack
*/
class B_in_stack
{
public:
    /*
        weak_ptr<A_in_stack> means:

        1. B_in_stack DOES NOT OWN A_in_stack.
        2. weak_ptr does NOT increase the reference count.
        3. B_in_stack can "observe" A_in_stack,
           but it does NOT keep it alive.

        This is the KEY CHANGE that fixes the cyclic dependency.
    */
    weak_ptr<A_in_stack> observes_heap_address_of_A;

    B_in_stack()
    {
        cout << "B_in_stack object created\n";
    }

    ~B_in_stack()
    {
        /*
            This destructor WILL now be called correctly
            because the ownership cycle is broken.
        */
        cout << "B object destroyed\n";
    }
};

/*
    Class A_in_stack
*/
class A_in_stack
{
public:
    /*
        shared_ptr<B_in_stack> means:

        1. A_in_stack OWNS B_in_stack.
        2. This shared_ptr INCREASES the reference count of B_in_stack.
        3. A_in_stack is responsible for B_in_stack's lifetime.

        IMPORTANT:
        Ownership is now ONE-DIRECTIONAL.
        A owns B, but B does NOT own A.
    */
    shared_ptr<B_in_stack> owns_heap_address_of_B;

    A_in_stack()
    {
        cout << "A_in_stack object created\n";
    }

    ~A_in_stack()
    {
        /*
            This destructor WILL now be called
            because reference count can reach zero.
        */
        cout << "A object destroyed\n";
    }
};

int main()
{
    /*
        make_shared<A_in_stack>() allocates A_in_stack on the HEAP
        and returns a shared_ptr managing it.

        Reference count of A_in_stack = 1
        (owned by A_copy_in_heap)
    */
    shared_ptr<A_in_stack> A_copy_in_heap = make_shared<A_in_stack>();

    /*
        make_shared<B_in_stack>() allocates B_in_stack on the HEAP
        and returns a shared_ptr managing it.

        Reference count of B_in_stack = 1
        (owned by B_copy_in_heap)
    */
    shared_ptr<B_in_stack> B_copy_in_heap = make_shared<B_in_stack>();

    /*
        A_in_stack stores a shared_ptr to B_in_stack.

        EFFECT:
        - Reference count of B_in_stack becomes 2
          (one from B_copy_in_heap, one from A_in_stack)

        OWNERSHIP:
        - A_in_stack OWNS B_in_stack
    */
    A_copy_in_heap->owns_heap_address_of_B = B_copy_in_heap;

    /*
        B_in_stack stores a weak_ptr to A_in_stack.

        EFFECT:
        - Reference count of A_in_stack REMAINS 1
        - weak_ptr does NOT participate in ownership

        CRITICAL POINT:
        - No ownership cycle is created
        - This is why memory leak is avoided
    */
    B_copy_in_heap->observes_heap_address_of_A = A_copy_in_heap;

    /*
        main() is about to exit.

        Destruction sequence:

        1. A_copy_in_heap goes out of scope
           → Reference count of A_in_stack becomes 0
           → A_in_stack is destroyed

        2. A_in_stack destructor releases its shared_ptr<B_in_stack>
           → Reference count of B_in_stack becomes 0
           → B_in_stack is destroyed

        Both destructors are called.
        No memory leak.
    */
    return 0;
}


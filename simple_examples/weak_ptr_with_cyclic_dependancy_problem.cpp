#include <iostream>   // For std::cout
#include <memory>     // For std::shared_ptr
using namespace std;

/*
    Forward declaration of A_in_stack.

    This is required because B_in_stack contains a pointer
    (shared_ptr) to A_in_stack, but A_in_stack is defined later.
*/
class A_in_stack;

/*
    Class B_in_stack
*/
class B_in_stack
{
public:
    /*
        shared_ptr<A_in_stack> means:

        1. B_in_stack CLAIMS OWNERSHIP of an A_in_stack object.
        2. This shared_ptr will INCREASE the reference count of A_in_stack.
        3. B_in_stack believes it is responsible for keeping A_in_stack alive.
    */
    shared_ptr<A_in_stack> owns_heap_address_of_A;

    B_in_stack()
    {
        cout << "B_in_stack object created\n";
    }

    ~B_in_stack()
    {
        /*
            This destructor will NEVER be called in this program
            due to cyclic dependency created by shared_ptr.
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

        1. A_in_stack CLAIMS OWNERSHIP of a B_in_stack object.
        2. This shared_ptr will INCREASE the reference count of B_in_stack.
        3. A_in_stack believes it is responsible for keeping B_in_stack alive.
    */
    shared_ptr<B_in_stack> owns_heap_address_of_B;

    A_in_stack()
    {
        cout << "A_in_stack object created\n";
    }

    ~A_in_stack()
    {
        /*
            This destructor will NEVER be called in this program
            due to cyclic dependency created by shared_ptr.
        */
        cout << "A object destroyed\n";
    }
};

int main()
{
    /*
        make_shared<B_in_stack>() allocates B_in_stack on the HEAP
        and returns a shared_ptr managing it.

        Reference count of B_in_stack = 1
        (owned by B_copy_in_heap)
    */
    shared_ptr<B_in_stack> B_copy_in_heap = make_shared<B_in_stack>();

    /*
        make_shared<A_in_stack>() allocates A_in_stack on the HEAP
        and returns a shared_ptr managing it.

        Reference count of A_in_stack = 1
        (owned by A_copy_in_heap)
    */
    shared_ptr<A_in_stack> A_copy_in_heap = make_shared<A_in_stack>();

    /*
        B_in_stack now stores a shared_ptr to A_in_stack.

        EFFECT:
        - Reference count of A_in_stack becomes 2
          (one from A_copy_in_heap, one from B_in_stack)

        OWNERSHIP:
        - B_in_stack now OWNS A_in_stack
    */
    B_copy_in_heap->owns_heap_address_of_A = A_copy_in_heap;

    /*
        A_in_stack now stores a shared_ptr to B_in_stack.

        EFFECT:
        - Reference count of B_in_stack becomes 2
          (one from B_copy_in_heap, one from A_in_stack)

        OWNERSHIP:
        - A_in_stack now OWNS B_in_stack

   ------------     PROBLEM CREATED HERE --------------------

        A_in_stack owns B_in_stack
        B_in_stack owns A_in_stack

        This creates a CYCLIC DEPENDENCY.
    */
    A_copy_in_heap->owns_heap_address_of_B = B_copy_in_heap;

    /*
        main() is about to exit.

        What happens?
        - B_copy_in_heap goes out of scope → refcount(B) becomes 1
        - A_copy_in_heap goes out of scope → refcount(A) becomes 1

        Since neither reference count reaches ZERO:
        - A_in_stack is NOT destroyed
        - B_in_stack is NOT destroyed

        Destructors are NEVER called.
        MEMORY LEAK occurs.
    */
    return 0;
}


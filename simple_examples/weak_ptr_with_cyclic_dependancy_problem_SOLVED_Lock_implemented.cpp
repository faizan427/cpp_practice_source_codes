#include <iostream>   // for std::cout
#include <memory>     // for std::shared_ptr and std::weak_ptr
using namespace std;

/*
    Forward declaration of A_inside_stack.

    This is required because B_inside_stack
    uses A_inside_stack before it is fully defined.
*/
class A_inside_stack;

/*
    Class B_inside_stack

    This class OWNS an object of type A_inside_stack.
    Ownership is expressed using std::shared_ptr.
*/
class B_inside_stack
{
public:
    /*
        shared_ptr<A_inside_stack> holds_A

        Meaning:
        - B_inside_stack OWNS A_inside_stack
        - This shared_ptr increases the reference count of A_inside_stack
        - As long as B_inside_stack is alive, A_inside_stack will stay alive
    */
    shared_ptr<A_inside_stack> holds_A;

    B_inside_stack()
    {
        cout << "B object Created\n";
    }

    ~B_inside_stack()
    {
        /*
            This destructor WILL be called correctly
            because there is no cyclic dependency.
        */
        cout << "B destroyed\n";
    }
};

/*
    Class A_inside_stack

    This class DOES NOT own B_inside_stack.
    Instead, it only OBSERVES it using std::weak_ptr.
*/
class A_inside_stack
{
public:
    /*
        weak_ptr<B_inside_stack> watches_B

        Meaning:
        - A_inside_stack DOES NOT OWN B_inside_stack
        - weak_ptr does NOT increase reference count
        - This pointer can become EXPIRED if B is destroyed
        - Used specifically to AVOID cyclic dependency
    */
    weak_ptr<B_inside_stack> watches_B;

    A_inside_stack()
    {
        cout << "A object created\n";
    }

    ~A_inside_stack()
    {
        /*
            This destructor WILL be called correctly
            because weak_ptr does not keep B alive.
        */
        cout << "A destroyed\n";
    }

    /*
        Demonstrates SAFE access to B using weak_ptr::lock().
    */
    void now_holds_B()
    {
        /*
            lock() tries to convert weak_ptr into shared_ptr.

            - If B is still alive:
                lock() returns a valid shared_ptr
            - If B is already destroyed:
                lock() returns nullptr

            This prevents use-after-free bugs.
        */
        shared_ptr<B_inside_stack> now_hold_B = watches_B.lock();

        if (now_hold_B != nullptr)
        {
            /*
                SAFE PATH:
                - B is alive
                - now_hold_B temporarily OWNS B
                - B cannot be destroyed while now_hold_B exists
            */
		cout << "address of B in heap is stored in A_inside_heap->now_holds_B() and the object B is alive in heap\n";        
}
        else
        {
            /*
                SAFE PATH:
                - B is already destroyed
                - We DO NOT dereference it
            */
            cout << "B object is destroyed already\n";
        }
    }
};

int main()
{
    /*
        Create A_inside_stack on the HEAP.

        Reference count(A) = 1
        (owned by A_inside_heap)
    */
    shared_ptr<A_inside_stack> A_inside_heap = make_shared<A_inside_stack>();

    /*
        Create B_inside_stack on the HEAP.

        Reference count(B) = 1
        (owned by B_inside_heap)
    */
    shared_ptr<B_inside_stack> B_inside_heap = make_shared<B_inside_stack>();

    /*
        A observes B using weak_ptr.

        EFFECT:
        - Reference count(B) is NOT increased
        - A does NOT control B's lifetime
    */
    A_inside_heap->watches_B = B_inside_heap;

    /*
        B owns A using shared_ptr.

        EFFECT:
        - Reference count(A) becomes 2
        - B now controls A's lifetime
    */
    B_inside_heap->holds_A = A_inside_heap;

    /*
        weak_ptr::use_count()

        IMPORTANT:
        - This shows the number of shared_ptr instances
        - It does NOT mean weak_ptr owns the object
        - Used here ONLY for demonstration
    */
    cout << "watches_B shared use_count = "
         << A_inside_heap->watches_B.use_count() << endl;

    cout << "holds_A shared use_count = "
         << B_inside_heap->holds_A.use_count() << endl;

    /*
        Access B safely while it is alive.
    */
    A_inside_heap->now_holds_B();

    /*
        Destroy B explicitly.

        EFFECT:
        - Reference count(B) becomes 0
        - B_inside_stack is destroyed
        - weak_ptr inside A becomes expired
    */
    B_inside_heap.reset();

    /*
        Attempt to access B again.

        This demonstrates that weak_ptr safely detects
        that the object no longer exists.
    */
    A_inside_heap->now_holds_B();

    /*
        main() ends.

        A_inside_heap goes out of scope:
        - Reference count(A) becomes 0
        - A_inside_stack is destroyed
    */
    return 0;
}



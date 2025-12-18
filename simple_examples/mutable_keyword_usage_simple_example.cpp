#include <iostream>
using namespace std;

/*
    Class: demo

    Purpose:
    - Demonstrates the use of the 'mutable' keyword in C++.

    IMPORTANT CONCEPT:
    - Normally, a const member function is NOT allowed
      to modify any data members of the class.
    - 'mutable' is the ONLY exception to this rule.
*/
class demo
{
public:
    /*
        mutable int x = 0;

        Meaning:
        - 'x' is allowed to be modified EVEN IF:
            1) the object is const
            2) the member function is const

        Why this exists:
        - Supports "logical constness"
        - Allows modification of INTERNAL state
          that does NOT affect the observable behavior
          of the object.

        Typical use cases:
        - Caching
        - Counters
        - Debug / logging state
        - Lazy initialization
    */
    mutable int x = 0;

    /*
        const member function

        Meaning:
        - Promises NOT to modify the logical state of the object.
        - Compiler enforces this promise.

        EXCEPTION:
        - mutable members CAN be modified inside const functions.
    */
    void func() const
    {
        /*
            Allowed because 'x' is declared mutable.

            Without 'mutable':
            ❌ Compilation error:
               "cannot modify member in const function"

            With 'mutable':
            ✅ Compiler allows modification.
        */
        x++;

        cout << "x is incremented to " << x << endl;
    }
};

int main()
{
    /*
        Create a non-const object.
    */
    demo d;

    /*
        Calling a const member function.

        Even though:
        - func() is const
        - x is modified inside func()

        This is LEGAL because x is mutable.
    */
    d.func();

    return 0;
}


#include <iostream>
using namespace std;

/*
    KEYWORD: final (when used with virtual functions)

    When 'final' is applied to a virtual function, it means:
    - This function CANNOT be overridden in any derived class.
    - It represents the FINAL implementation in the inheritance hierarchy.
*/

/*
    Base class
*/
class base
{
public:
    base() = default;
    ~base() = default;

    /*
        virtual void func() final = 0;

        This line has THREE important concepts combined:

        1) virtual
           - Enables dynamic dispatch
           - Allows derived classes to override the function

        2) = 0  (pure virtual function)
           - Makes this class ABSTRACT
           - Forces derived classes to provide an implementation

        3) final
           - PREVENTS derived classes from overriding this function

        🚨 PROBLEM 🚨
        ----------------
        'final' and '= 0' contradict each other:

        - '= 0' says: "Derived classes MUST override this function"
        - 'final' says: "Derived classes MUST NOT override this function"

        This creates a LOGICAL and LANGUAGE ERROR.
    */
    virtual void func() final = 0;
};

/*
    Derived class
*/
class derived : public base
{
public:
    derived() = default;
    ~derived() = default;

    /*
        Attempting to override func()

        ❌ ERROR:
        - func() in base is marked 'final'
        - final virtual functions CANNOT be overridden
        - Even though 'override' keyword is used,
          the compiler will reject this.
    */
    void func() override
    {
        cout << "Overridden" << endl;
    }
};

int main()
{
    /*
        Program will NOT compile due to:
        - Invalid use of 'final' with pure virtual function
        - Illegal override of a final function
    */
    return 0;
}


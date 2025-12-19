#include <iostream>
using namespace std;

/*
    KEYWORD: final   (C++11 and later)

    The 'final' keyword is used to:
    1. Prevent a class from being inherited
    2. Prevent a virtual function from being overridden

    In this example, 'final' is applied to a CLASS.
*/

/*
    Class: base

    The keyword 'final' after the class name means:

    - This class CANNOT be used as a base class
    - No other class is allowed to inherit from it
    - Attempting to derive from it will cause a COMPILE-TIME ERROR

    Use cases:
    - Security (prevent modification through inheritance)
    - Design intent (class is complete)
    - Optimization opportunities for the compiler
*/
class base final
{
public:
    /*
        Default constructor explicitly requested.
        '= default' tells the compiler to generate
        the default implementation.
    */
    base() = default;

    /*
        Default destructor explicitly requested.
    */
    ~base() = default;
};

/*
    Class: derived

    ❌ PROBLEM HERE:

    - 'derived' attempts to inherit from 'base'
    - But 'base' is declared as 'final'
    - Inheriting from a final class is NOT allowed

    This will result in a COMPILATION ERROR.
*/
class derived : public base
{
public:
    derived() = default;
    ~derived() = default;
};

int main()
{
    /*
        Program will NOT compile due to the inheritance error above.
    */
    return 0;
}


#include <iostream>   // Provides std::cout for console output
using namespace std;  // Brings std names into global scope (not recommended in headers)

/*
    C-STYLE ENUM (unscoped enum)

    Characteristics of a normal enum:
    1. Enumerator names (one, two, three) are injected into the enclosing scope.
    2. Enum values implicitly convert to int.
    3. Enum values are NOT strongly typed.
    4. No scope qualification is required to use enumerators.
*/
enum COLORS
{
    /*
        Explicitly assign the first enumerator a value.
        'one' will have the integer value 1.
    */
    one = 1,

    /*
        If a value is not specified, the compiler increments
        the previous value by 1.

        So:
        two   = 2
    */
    two,

    /*
        three = 3
    */
    three
};

int main()
{
    /*
        Declaration of enum variable.

        This works because:
        - 'two' exists in the surrounding (global) scope.
        - The compiler allows implicit conversion from
          enumerator to enum type.

        NOTE:
        With enum class, this would be INVALID.
        You would need: COLORS::two
    */
    COLORS c = two;   // one way of declaration

    /*
        Printing enum variable.

        Because C-style enums implicitly convert to int,
        the value printed is the underlying integer (2).
    */
    cout << c << endl;

    /*
        Accessing enum value using scope resolution.

        This is OPTIONAL for normal enums.
        Both 'three' and 'COLORS::three' refer to the same value.

        This prints 3.
    */
    cout << COLORS::three << endl;   // another way of declaration

    /*
        Assigning another enumerator to the enum variable.
        Again, no scope qualification is required.
    */
    c = three;

    /*
        Implicit conversion from enum to int.

        This is ALLOWED for normal enums,
        but it is considered DANGEROUS because:
        - It bypasses type safety.
        - It can cause subtle bugs.

        With enum class, this would be a COMPILE-TIME ERROR.
    */
    int three = c;   // implicit conversion

    /*
        Prints the integer value stored in 'three'.
        Output will be: 3
    */
    cout << three << endl;

    return 0;
}

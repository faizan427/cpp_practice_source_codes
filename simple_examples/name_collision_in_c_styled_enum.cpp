#include <iostream>
using namespace std;

/*
    C-STYLE ENUM (unscoped enum)

    IMPORTANT PROPERTY:
    - Enumerator names are injected into the surrounding scope.
    - This means 'one', 'two', 'three' become global identifiers.
*/
enum colors
{
    /*
        These enumerators are placed in the GLOBAL scope.
    */
    one = 1,
    two,
    three
};

/*
    Another C-style enum.

    PROBLEM:
    - This enum also declares an enumerator named 'one'.
    - 'one' was already declared above in enum colors.
    - Because both enums are unscoped, their enumerators
      share the SAME namespace.
*/
enum numbers
{
    /*
        ❌ ERROR:
        - 'one' is being redeclared.
        - This causes a name collision.
    */
    one = 1,

    /*
        ❌ ERROR:
        - 'two' is also already declared in enum colors.
    */
    two
};

int main()
{
    /*
        Program never reaches here because compilation fails.

        Typical compiler error:
        "error: redefinition of 'one'"
        "error: redefinition of 'two'"
    */
    return 0;
}

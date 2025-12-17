#include <iostream>
using namespace std;

/*
    ENUM CLASS (Scoped, Strongly Typed Enum)

    Why enum class exists:
    1. Prevents name collisions
    2. Enforces type safety
    3. Disallows implicit conversions
    4. Makes intent explicit in code
*/
enum class Colors
{
    /*
        Enumerators are scoped INSIDE Colors.
        They do NOT leak into the surrounding scope.
    */
    one   = 1,
    two   = 2,
    three = 3
};

/*
    Another enum class with SAME names and SAME values.
    This is COMPLETELY SAFE.
*/
enum class Numbers
{
    one   = 1,
    two   = 2,
    three = 3
};

int main()
{
    /*
    =====================================================
    ✅ CORRECT WAYS TO DECLARE AND USE enum class
    =====================================================
    */

    /*
        Enumerator MUST be qualified with enum name.
        This avoids ambiguity and name collisions.
    */
    Colors c = Colors::two;

    Numbers n = Numbers::one;

    /*
        enum class does NOT implicitly convert to int.
        You MUST explicitly convert using static_cast.
    */
    cout << static_cast<int>(c) << endl;  // prints 2
    cout << static_cast<int>(n) << endl;  // prints 1


    /*
    =====================================================
    ❌ WHAT NOT TO DO (compile-time errors)
    =====================================================
    */

    // Colors c2 = two;
    // ❌ ERROR: 'two' is not in global scope

    // int x = c;
    // ❌ ERROR: no implicit conversion from enum class to int

    // Colors c3 = Numbers::one;
    // ❌ ERROR: different enum class types (type-safe)

    // if (c == 2)
    // ❌ ERROR: cannot compare enum class with int


    /*
    =====================================================
    🔁 EXPLICIT CONVERSION SCENARIOS
    =====================================================
    */

    /*
        Explicit conversion is REQUIRED and INTENTIONAL.
        This makes conversions visible and safe.
    */
    int colorValue = static_cast<int>(Colors::three);
    cout << colorValue << endl;   // prints 3

    /*
        Explicit conversion also allows comparisons.
    */
    if (static_cast<int>(c) == 2)
    {
        cout << "Color is two\n";
    }

    /*
    =====================================================
    🧠 WHY enum class IS BETTER (summary)
    =====================================================

    - No global name pollution
    - No accidental mixing of enums
    - No silent int conversions
    - Bugs become compile-time errors
    */

    return 0;
}

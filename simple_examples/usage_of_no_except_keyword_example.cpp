#include <iostream>
#include <cstdlib>   // for std::terminate
using namespace std;

/*
===========================================================
NOEXCEPT — COMPLETE STUDY NOTES INSIDE CODE
===========================================================

WHAT IS noexcept?
-----------------
noexcept is a function specifier that tells the compiler:

    "This function guarantees that no exception will escape."

IMPORTANT:
----------
- noexcept does NOT mean "no throw inside"
- noexcept means "no exception leaves the function boundary"

If this promise is broken:
--------------------------
- std::terminate() is called immediately
- NO stack unwinding occurs
- NO destructors of local objects are called
- Program ends abruptly

WHY THIS DESIGN?
----------------
- If a noexcept function fails, program invariants are broken
- Continuing execution is unsafe
- Fail-fast is safer than partial cleanup

OS BEHAVIOR:
------------
- Even though destructors are skipped,
  the OPERATING SYSTEM reclaims all memory
- No persistent memory leaks occur after process termination

noexcept IS NOT FOR:
--------------------
- Business logic
- User input validation
- Recoverable errors

noexcept IS FOR:
----------------
- Destructors
- Move constructors
- Cleanup functions
- Low-level infrastructure
- Functions that MUST NOT fail
*/

/*
===========================================================
CASE 1: Safe noexcept function (CORRECT USAGE)
===========================================================

- No exceptions are thrown
- Function keeps its promise
*/
void safeDivide(int a, int b) noexcept
{
    if (b == 0)
    {
        cout << "Error: division by zero\n";
        return;
    }
    cout << "Result = " << a / b << endl;
}

/*
===========================================================
CASE 2: noexcept function that THROWS internally but CATCHES
===========================================================

- Exception is thrown
- Exception is caught inside the function
- No exception escapes
- noexcept contract is NOT violated
*/
void internalCatch(int b) noexcept  // Even if we dont use noexcept here it is ok. As no throw is going outside.
				    // Throw is handled internally here
{
    try
    {
        if (b == 0)
            throw 404;
    }
    catch (int e)
    {
        cout << "Caught error " << e << " internally\n";
    }
}

/*
===========================================================
CASE 3: BROKEN noexcept (DO NOT RUN)
===========================================================

- Exception escapes the function
- std::terminate() is called
- Program ends immediately
- No destructors are called

UNCOMMENT TO SEE TERMINATION
*/
/*
void brokenNoexcept() noexcept
{
    throw 999;   // ❌ violates noexcept
}
*/

int main()
{
    cout << "=== noexcept demonstration ===\n\n";

    /*
        Case 1: Safe noexcept usage
    */
    safeDivide(10, 5);
    safeDivide(10, 0);

    /*
        Case 2: Exception thrown but handled internally
    */
    internalCatch(0);

    /*
        Case 3: Uncommenting this will terminate program
    */
    // brokenNoexcept();

    cout << "\nProgram ended normally\n";
    return 0;
}

/*
===========================================================
FINAL TAKEAWAYS (MEMORIZE THESE)
===========================================================

1. noexcept is a PROMISE, not a suggestion
2. Exceptions may occur inside noexcept, but must NOT escape
3. Violation causes immediate program termination
4. Stack unwinding does NOT occur on violation
5. OS cleans up memory after termination
6. noexcept improves performance and correctness
7. Use noexcept ONLY when failure means program is invalid

ONE-LINE SUMMARY:
-----------------
noexcept enforces fail-fast behavior and enables optimization by
guaranteeing that no exceptions escape a function.
*/


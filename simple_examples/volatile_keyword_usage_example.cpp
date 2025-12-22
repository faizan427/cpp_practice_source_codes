#include <iostream>
using namespace std;

/*
============================================================
VOLATILE — ESSENCE USING A SIMPLE bool FLAG EXAMPLE
============================================================

PROBLEM SETUP:
--------------
We have a boolean flag that is expected to change
"outside" the normal flow of the program.

Example situations:
- Set by an interrupt
- Set by a signal handler
- Set by hardware
- Set asynchronously (not visible to compiler)

The compiler, however, DOES NOT know this unless we tell it.
*/

/*
============================================================
CASE 1: WITHOUT volatile (LOGICALLY CORRECT, BUT BROKEN)
============================================================
*/

bool flag = false;   // normal variable

void setFlag()
{
    // Imagine this function is called asynchronously
    // (interrupt / signal / external event)
    flag = true;
}

void waitWithoutVolatile()
{
    /*
        The compiler sees:
        - flag is never modified inside this function
        - No visible code changes flag

        So it may optimize this loop into:
            while(true) { }

        This causes an INFINITE LOOP.
    */
    while (!flag)
    {
        // waiting...
    }
}

/*
============================================================
CASE 2: WITH volatile (CORRECT BEHAVIOR)
============================================================
*/

volatile bool vflag = false;   // volatile variable

void setVolatileFlag()
{
    // Changed asynchronously
    vflag = true;
}

void waitWithVolatile()
{
    /*
        Because vflag is volatile:
        - Compiler MUST re-read it from memory every time
        - Compiler CANNOT assume it stays false

        So when vflag becomes true externally,
        the loop WILL EXIT correctly.
    */
    while (!vflag)
    {
        // waiting...
    }
}

/*
============================================================
WHAT volatile DOES (IN ONE LINE)
============================================================

volatile tells the compiler:
"Do NOT optimize access to this variable.
 It may change at any time."
*/

/*
============================================================
WHAT volatile DOES NOT DO (VERY IMPORTANT)
============================================================

volatile DOES NOT:
❌ Make code thread-safe
❌ Prevent race conditions
❌ Make operations atomic
❌ Replace mutexes or atomics

volatile is ONLY about compiler behavior.
*/

/*
============================================================
RULE TO REMEMBER (LOCK THIS IN)
============================================================

Use volatile when:
- A variable can change outside the normal program flow

Do NOT use volatile for:
- Thread synchronization
*/

int main()
{
    cout << "Read the comments to understand volatile.\n";
    return 0;
}


/************************************************************
    STUDY NOTES: WHY `inline` FUNCTIONS EXIST IN C++

    This single file explains a MULTI-FILE PROBLEM
    using comments, because linker errors happen
    only when multiple .cpp files are involved.

    ------------------------------------------------
    CONCEPTS COVERED:
    - Translation units
    - One Definition Rule (ODR)
    - Why functions in headers cause linker errors
    - How `inline` fixes the problem
************************************************************/


/*
============================================================
SCENARIO 1: PROBLEM WITHOUT `inline`
============================================================

IMAGINE THIS FILE STRUCTURE:

-----------------------------
header.h
-----------------------------
int add(int a, int b) {
    return a + b;
}

-----------------------------
file1.cpp
-----------------------------
#include "header.h"

-----------------------------
file2.cpp
-----------------------------
#include "header.h"

-------------------------------------------------------------
WHAT ACTUALLY HAPPENS DURING COMPILATION
-------------------------------------------------------------

1) file1.cpp is compiled
   → it includes header.h
   → compiler sees definition of add()
   → object file contains add()

2) file2.cpp is compiled
   → it includes header.h
   → compiler AGAIN sees definition of add()
   → object file AGAIN contains add()

3) Linker tries to combine object files
   → sees TWO definitions of add()
   → violates One Definition Rule (ODR)
   → LINKER ERROR

IMPORTANT RULE (ODR):
--------------------
A non-inline function must have EXACTLY ONE definition
in the entire program.

RESULT:
--------
❌ LINKER ERROR: multiple definition of add
*/


/*
============================================================
SCENARIO 2: WHY THIS IS A PROBLEM
============================================================

The compiler does NOT know about other .cpp files.
Each .cpp file is compiled independently.

The linker is the first stage where all object files
are combined — and THAT is where the error occurs.

This is why:
- The code compiles fine
- But fails at LINK TIME
*/


/*
============================================================
SCENARIO 3: HOW `inline` FIXES THIS
============================================================

Now imagine header.h contains:

inline int add(int a, int b) {
    return a + b;
}

What does `inline` REALLY mean here?

It DOES NOT mean:
❌ "always replace function call with code"

It MEANS:
✅ "This function is allowed to have multiple
   identical definitions across translation units"

So now:

1) file1.cpp defines add()
2) file2.cpp defines add()
3) Linker is told:
      "These definitions all represent the SAME function"

RESULT:
--------
✔ Program links successfully
✔ No ODR violation
*/


/*
============================================================
IMPORTANT CLARIFICATIONS (VERY IMPORTANT)
============================================================

1) `inline` is about LINKAGE, not performance
2) Compiler may inline even without `inline`
3) `inline` is REQUIRED for functions defined in headers
4) Templates do not need `inline`
   (they are implicitly inline)

INLINE IS A LANGUAGE RULE,
NOT AN OPTIMIZATION COMMAND.
*/


/*
============================================================
RULE OF THUMB (MEMORIZE THIS)
============================================================

If a function is DEFINED in a header file,
it must be ONE of the following:

✔ inline
✔ static
✔ template
✔ in an anonymous namespace

Otherwise → linker error
*/


/*
============================================================
ONE-LINE ESSENCE (THIS IS THE CORE)
============================================================

`inline` allows the same function definition to appear
in multiple translation units without violating the
One Definition Rule.
*/


/*
============================================================
DUMMY MAIN (FILE IS SELF-CONTAINED)
============================================================
*/
int main()
{
    return 0;
}


#include <iostream>
using namespace std;

/*
===========================================================
STRUCTURE PADDING — THEORY (READ THIS FIRST)
===========================================================

STRUCTURE PADDING is extra memory added by the compiler
between (or at the end of) structure members.

WHY padding exists:
-------------------
1. CPUs access memory fastest when data is ALIGNED.
2. Each data type has an alignment requirement.
   - char   → 1 byte
   - int    → 4 bytes (typically)
   - double → 8 bytes (typically)
3. Compiler inserts padding to satisfy these requirements.

IMPORTANT RULES:
----------------
1. Members are placed in order.
2. Each member starts at an address aligned for its type.
3. The struct size is padded so ARRAYS of structs are aligned.
4. sizeof(struct) >= sum of member sizes.
*/

/*
===========================================================
BAD PADDING SCENARIO
===========================================================

This struct has POOR member ordering.
It causes EXCESSIVE padding.
*/
struct BadPadding
{
    char c1;   // 1 byte
    int  i;    // 4 bytes (needs 4-byte alignment)
    char c2;   // 1 byte
};

/*
MEMORY LAYOUT (Typical 64-bit system):

Offset:  0   1   2   3   4   5   6   7   8   9  10  11
         +---+---+---+---+---+---+---+---+---+---+---+---+
BadPad  | c1| P | P | P |   i (4 bytes)   | c2| P | P | P |
         +---+---+---+---+---+---+---+---+---+---+---+---+

Explanation:
- c1 uses 1 byte
- 3 bytes padding to align int
- int uses 4 bytes
- c2 uses 1 byte
- 3 bytes padding at end (tail padding)

Total size = 12 bytes
*/

/*
===========================================================
GOOD PADDING SCENARIO
===========================================================

This struct has OPTIMAL member ordering.
Padding is MINIMIZED.
*/
struct GoodPadding
{
    int  i;    // 4 bytes
    char c1;   // 1 byte
    char c2;   // 1 byte
};

/*
MEMORY LAYOUT:

Offset:  0   1   2   3   4   5   6   7
         +---+---+---+---+---+---+---+---+
GoodPad |   i (4 bytes)   | c1| c2| P | P |
         +---+---+---+---+---+---+---+---+

Explanation:
- int placed first (naturally aligned)
- chars grouped together
- only 2 bytes of tail padding

Total size = 8 bytes
*/

/*
===========================================================
WHY GOOD PADDING MATTERS
===========================================================

Imagine 1 MILLION objects:

BadPadding  = 12 bytes × 1,000,000 = 12 MB
GoodPadding =  8 bytes × 1,000,000 =  8 MB

You save 4 MB just by REORDERING MEMBERS.

This affects:
- Memory usage
- Cache performance
- Program speed
*/

/*
===========================================================
TAIL PADDING EXPLANATION
===========================================================

Tail padding ensures that ARRAYS of structs stay aligned.

Example:
- If struct alignment is 4 bytes
- sizeof(struct) must be multiple of 4
*/

/*
===========================================================
HOW TO CHECK ALIGNMENT AND SIZE
===========================================================
*/

int main()
{
    cout << "=== Structure Padding Demonstration ===\n\n";
	
	BadPadding Bad_Pad;
	GoodPadding Good_Pad;

    cout << "Size of BadPadding  : " << sizeof(Bad_Pad) << " bytes\n";

    cout << "Size of GoodPadding : " << sizeof(Good_Pad) << " bytes\n";

    /*
        KEY OBSERVATION:
        - Both structs store the SAME data
        - But GoodPadding uses LESS memory
        - This is purely due to MEMBER ORDER
    */

    return 0;
}

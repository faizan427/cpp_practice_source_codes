#include <iostream>
using namespace std;

/*
    UNION THEORY (Core Concept)

    A union is a special data type in C++ where:
    - All data members SHARE the SAME memory location
    - Only ONE member can hold a valid value at a time
    - Writing to one member OVERWRITES the others

    Memory layout:
    ----------------
    The size of a union is equal to the size of its LARGEST member.

    In this union:
        sizeof(int)   = typically 4 bytes
        sizeof(float) = typically 4 bytes

    So:
        sizeof(Data) = 4 bytes
*/
union Data
{
    /*
        All members start at the SAME memory address.
        They are different "views" of the SAME bytes.
    */
    int i;
    float f;
};

int main()
{
    /*
        Create an instance of the union.

        IMPORTANT:
        - At this point, NO member is active yet.
        - The memory contains garbage until we assign something.
    */
    Data d;

    /*
        Write to member 'i'.

        EFFECT:
        - The 4 bytes of the union now represent an int value (10).
        - 'i' becomes the ACTIVE member.
        - 'f' is now INVALID.
    */
    d.i = 10;       // write int

    /*
        Reading from the ACTIVE member is safe.
    */
    cout << d.i << endl;

    /*
        Write to member 'f'.

        EFFECT:
        - The SAME 4 bytes are now reinterpreted as a float.
        - The previous int value is OVERWRITTEN.
        - 'f' becomes the ACTIVE member.
        - 'i' becomes INVALID.
    */
    d.f = 3.14f;    // overwrite same memory with float

    /*
        Reading from the ACTIVE member is safe.
    */
    cout << d.f << endl;

    /*
        ❌ UNDEFINED BEHAVIOR (VERY IMPORTANT)

        At this point:
        - 'f' is the active member
        - 'i' is NOT active

        Reading 'i' now would interpret float bits as an int,
        which is NOT allowed by the C++ standard.

        This is why the following line is commented out:
    */
    // cout << d.i << endl;  // ❌ undefined behavior

    /*
        WHY THIS IS DANGEROUS:
        - The program may print garbage
        - The program may crash
        - The behavior is compiler- and platform-dependent

        RULE TO REMEMBER:
        -----------------
        ALWAYS read only the last written member of a union.
    */

    return 0;
}

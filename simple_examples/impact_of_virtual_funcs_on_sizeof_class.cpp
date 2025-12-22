#include <iostream>
using namespace std;

/*
===========================================================
STUDY NOTES: EFFECT OF VIRTUAL FUNCTIONS ON CLASS SIZE
===========================================================

CORE IDEA:
---------
When a class (or struct) has AT LEAST ONE virtual function,
the compiler typically adds a hidden pointer called a vptr
(virtual pointer) to each object.

This vptr:
- Points to a vtable (virtual table)
- Enables runtime polymorphism (dynamic dispatch)

IMPORTANT:
----------
- vptr is stored INSIDE EACH OBJECT
- vtable is shared (one per class)
- vptr increases the SIZE of each object
*/

/*
===========================================================
CASE 1: Class WITHOUT virtual functions
===========================================================

- No vptr is needed
- Object size = size of its data members (+ padding)
*/
class NoVirtual
{
    int x;   // 4 bytes (typically)
};

/*
===========================================================
CASE 2: Class WITH a virtual function
===========================================================

- Presence of ANY virtual function introduces a vptr
- vptr is usually:
    8 bytes on 64-bit systems
    4 bytes on 32-bit systems
*/
class WithVirtual
{
    int x;   // 4 bytes
public:
    virtual void func() {}
};

/*
===========================================================
CASE 3: Class with ONLY virtual functions (no data)
===========================================================

- Still needs a vptr
- Even without data members, object is NOT empty
*/
class OnlyVirtual
{
public:
    virtual void run() {}
};

/*
===========================================================
CASE 4: Multiple virtual functions
===========================================================

- Still ONLY ONE vptr per object
- Size does NOT increase per virtual function
*/
class ManyVirtuals
{
public:
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
};

/*
===========================================================
CASE 5: Inheritance with virtual functions
===========================================================

- Derived class inherits the vptr from base
- No additional vptr unless virtual inheritance is used
*/
class Base
{
public:
    virtual void baseFunc() {}
};

class Derived : public Base
{
    int y;   // additional data member
};

int main()
{
    cout << "=== Effect of Virtual Functions on Object Size ===\n\n";

    /*
        sizeof() reports the size of an OBJECT,
        not the size of the class definition (blueprint).
    */

    cout << "Size of NoVirtual        : " << sizeof(NoVirtual) << " bytes\n";
    cout << "Size of WithVirtual      : " << sizeof(WithVirtual) << " bytes\n";
    cout << "Size of OnlyVirtual      : " << sizeof(OnlyVirtual) << " bytes\n";
    cout << "Size of ManyVirtuals     : " << sizeof(ManyVirtuals) << " bytes\n";
    cout << "Size of Base             : " << sizeof(Base) << " bytes\n";
    cout << "Size of Derived          : " << sizeof(Derived) << " bytes\n";

    /*
===========================================================
EXPECTED OBSERVATIONS (Typical 64-bit system)
===========================================================

NoVirtual:
----------
- Contains only an int
- Size ≈ 4 bytes (may be padded to 8)

WithVirtual:
------------
- int (4 bytes)
- vptr (8 bytes)
- padding for alignment
- Size ≈ 16 bytes

OnlyVirtual:
------------
- No data members
- Still has vptr
- Size ≈ 8 bytes

ManyVirtuals:
-------------
- Multiple virtual functions
- Still only ONE vptr
- Size ≈ 8 bytes

Derived:
--------
- Inherits vptr from Base
- Adds int y
- Size ≈ 16 bytes

KEY RULES TO REMEMBER:
---------------------
1. One vptr per object, not per virtual function
2. vptr increases object size
3. struct vs class makes NO difference
4. Virtual functions affect memory layout
5. vtable does NOT affect object size (shared per class)
*/

    return 0;
}


#include <iostream>
using namespace std;

/*
============================================================
DEPENDENCY INVERSION PRINCIPLE (DIP) — THEORY
============================================================

DIP STATES:
-----------
1. High-level modules should NOT depend on low-level modules.
2. Both should depend on abstractions.
3. Abstractions should NOT depend on details.
4. Details should depend on abstractions.

In simple words:
----------------
- Business logic (high-level) must not be tightly coupled
  to specific implementations (low-level).
- Communication must happen via interfaces (abstractions).
*/


/*
============================================================
ABSTRACTION — switchable
============================================================

This class represents an ABSTRACTION.

Why this supports DIP:
---------------------
- It defines WHAT operations are available (ON, OFF)
- It does NOT define HOW they are implemented
- It does NOT depend on any concrete device (TV, fan, etc.)

According to DIP:
-----------------
✔ High-level and low-level modules both depend on this abstraction
✔ Abstractions do not depend on details
*/
class switchable
{
public:
    virtual void ON() = 0;
    virtual void OFF() = 0;

    // Virtual destructor is good practice for polymorphic base classes
    virtual ~switchable() = default;
};


/*
============================================================
LOW-LEVEL MODULE — tv_switch
============================================================

This is a LOW-LEVEL MODULE (detail / implementation).

Why this supports DIP:
---------------------
- It DEPENDS on the abstraction (switchable)
- It does NOT control how it is used
- It only provides device-specific behavior

According to DIP:
-----------------
✔ Details depend on abstractions
✔ Implementation can be replaced without changing high-level code
*/
class tv_switch : public switchable
{
public:
    void ON() override
    {
        cout << "TV turned ON" << endl;
    }

    void OFF() override
    {
        cout << "TV turned OFF" << endl;
    }
};


/*
============================================================
HIGH-LEVEL MODULE — smart_home_system
============================================================

This is the HIGH-LEVEL MODULE.

Its responsibility:
-------------------
- Define system behavior (operations)
- NOT manage concrete device details

DIP SUPPORTING ELEMENT (MOST IMPORTANT):
----------------------------------------
The class depends ONLY on the abstraction 'switchable',
NOT on 'tv_switch' or any other concrete device.
*/
class smart_home_system
{
public:
    /*
        DIP SUPPORT:
        ------------
        - Pointer is of type 'switchable*'
        - High-level module has NO knowledge of concrete classes
    */
    switchable *switch_1;

    /*
        DEPENDENCY INJECTION (Constructor Injection):

        DIP is applied in PRACTICE here:
        --------------------------------
        - The dependency is PROVIDED from outside
        - smart_home_system does NOT create the object
        - This removes tight coupling

        This line is a STRONG indicator of DIP:
    */
    smart_home_system(switchable *my_switch)
        : switch_1(my_switch)
    {}

    /*
        High-level operations use the abstraction.

        DIP SUPPORT:
        ------------
        - Calls are made via interface
        - No type checking
        - No casting
        - No conditional logic based on device type
    */
    void operation_1()
    {
        switch_1->ON();
    }

    void operation_2()
    {
        switch_1->OFF();
    }
};


int main()
{
    /*
        CONCRETE OBJECT CREATION HAPPENS HERE
        ------------------------------------

        This is OUTSIDE the high-level module.

        DIP SUPPORT:
        ------------
        - smart_home_system does NOT know about tv_switch
        - Dependency is injected from outside
        - Changing device does NOT affect system logic
    */
    smart_home_system system_controller_1(new tv_switch);

    system_controller_1.operation_1();
    system_controller_1.operation_2();

    return 0;
}


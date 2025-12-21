#include <iostream>
#include <memory>
using namespace std;

/*
====================================================
A simple class whose lifetime we want to manage
====================================================
*/
class Data
{
public:
    Data()
    {
        cout << "Data object CREATED\n";
    }

    ~Data()
    {
        cout << "Data object DESTROYED\n";
    }

    void show() const
    {
        cout << "Using Data object\n";
    }
};

/*
====================================================
Function that TAKES ownership of a unique_ptr
====================================================

IMPORTANT:
- unique_ptr passed BY VALUE means:
  this function becomes the NEW OWNER.
*/
void process(unique_ptr<Data> ptr)
{
    cout << "process(): now owns Data\n";
    ptr->show();

    // When function ends:
    // ptr goes out of scope
    // Data will be destroyed automatically
}

/*
====================================================
main(): demonstrating ownership clearly
====================================================
*/
int main()
{
    /*
    --------------------------------------------
    STEP 1: Create a unique_ptr (best practice)
    --------------------------------------------

    Ownership:
    - 'p1' OWNS the Data object
    - No raw pointer involved
    */
    unique_ptr<Data> p1 = make_unique<Data>();

    /*
    --------------------------------------------
    STEP 2: Transfer ownership explicitly
    --------------------------------------------

    Ownership transfer:
    - p1 ---> process()
    - p1 becomes EMPTY after std::move
    */
    process(std::move(p1));

    /*
        After this line:
        - Data object is already destroyed
        - p1 == nullptr
    */

    if (!p1)
        cout << "p1 no longer owns anything\n";

    /*
    --------------------------------------------
    STEP 3: Using raw pointer (for learning only)
    --------------------------------------------
    */
    Data* raw = new Data();

    /*
        ❌ THIS DOES NOT COMPILE:

        unique_ptr<Data> p2 = raw;

        WHY?
        ----
        Because unique_ptr's constructor is marked EXPLICIT.

        Inside the standard library (conceptually):

            explicit unique_ptr(Data* ptr);

        'explicit' PREVENTS implicit ownership transfer.
    */

    /*
    --------------------------------------------
    STEP 4: Correct EXPLICIT ownership transfer
    --------------------------------------------
    */
    unique_ptr<Data> p2(raw);

    /*
        Ownership now:
        - p2 OWNS the Data object
        - 'raw' must NEVER be used or deleted again
    */

    /*
    --------------------------------------------
    STEP 5: What would go wrong WITHOUT explicit?
    --------------------------------------------

    If unique_ptr constructor were NOT explicit,
    this would be allowed:

        unique_ptr<Data> p2 = raw;

    DANGERS:
    --------
    - Ownership transfer is INVISIBLE
    - Programmer may still think 'raw' is valid
    - Possible mistakes:
          delete raw;        // 💥 double delete
          raw->show();       // 💥 dangling pointer

    'explicit' EXISTS TO BLOCK THIS.
    */

    /*
    --------------------------------------------
    STEP 6: End of main()
    --------------------------------------------

    - p2 goes out of scope
    - Data object destroyed exactly once
    */
    return 0;
}


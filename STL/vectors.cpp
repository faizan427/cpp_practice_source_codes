#include <iostream>
#include <vector>
using namespace std;

/*
=========================================
            std::vector — THEORY
=========================================

1️⃣ What is std::vector?
-----------------------------------------
- A dynamic array
- Stores elements in CONTIGUOUS memory
- Supports random access (O(1))
- Automatically resizes when capacity is exceeded

Think of it as:
    "array + automatic resizing + STL features"

2️⃣ Memory Layout
-----------------------------------------
- Elements are stored back-to-back in memory
- This gives:
    ✔ Fast iteration
    ✔ Cache friendliness
    ✔ O(1) access via index

But:
    ❌ Insert/erase in middle is expensive (O(n))

3️⃣ size() vs capacity()
-----------------------------------------
size()     → number of elements currently stored
capacity() → total memory allocated

vector grows typically by:
    capacity *= 2   (implementation dependent)

This is why push_back() is:
    ✔ Amortized O(1)
    ❌ Worst-case O(n)

4️⃣ When DOES vector reallocate?
-----------------------------------------
If size() == capacity():
    - New larger memory is allocated
    - Old elements are copied/moved
    - Old memory is freed

⚠️ This INVALIDATES:
    - pointers
    - references
    - iterators

5️⃣ When NOT to use vector?
-----------------------------------------
- Frequent insert/delete at front or middle
- Need stable iterators after insertions

Use list / deque instead.

=========================================
*/
int main()
{
    vector<int> v;

    // Initially empty
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    // push_back(): Amortized O(1)
    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i * 10);
        cout << "After push_back(" << i * 10 << ") ";
        cout << "Size: " << v.size()
             << ", Capacity: " << v.capacity() << endl;
    }
  /*
    Output analysis:
    - Capacity grows in chunks
    - Size grows linearly
    */

    // Random access: O(1)
    cout << "v[2] = " << v[2] << endl;

    // Safe access
    cout << "v.at(2) = " << v.at(2) << endl;

    /*
    Difference:
    v[ ]   → No bounds checking (fast, unsafe)
    at()   → Bounds checking (safe, slower)
    */


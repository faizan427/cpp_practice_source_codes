#include <iostream>
#include <vector>
using namespace std;

/*
=========================================
            std::vector — THEORY
=========================================

1) What is std::vector?
-----------------------------------------
- A dynamic array
- Stores elements in contiguous memory
- Supports random access in O(1)
- Automatically resizes when capacity is exceeded

Think of it as:
    "array + automatic resizing + STL features"

2) Memory Layout
-----------------------------------------
- Elements are stored back-to-back in memory
- This gives:
    - Fast iteration
    - Cache friendliness
    - O(1) access via index

But:
    - Insert or erase in the middle is expensive (O(n))

3) size() vs capacity()
-----------------------------------------
size()     -> number of elements currently stored
capacity() -> total memory allocated

vector usually grows as:
    capacity *= 2   (implementation dependent)

This is why push_back() is:
    - Amortized O(1)
    - Worst-case O(n)

4) When does vector reallocate?
-----------------------------------------
If size() == capacity():
    - New larger memory is allocated
    - Old elements are copied or moved
    - Old memory is freed

This invalidates:
    - pointers
    - references
    - iterators

5) When NOT to use vector?
-----------------------------------------
- Frequent insert or delete at front or middle
- Need stable iterators after insertions

Use list or deque instead.

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
    v[]  -> No bounds checking (fast, unsafe)
    at() -> Bounds checking (safe, slightly slower)
    */

    // Iteration
    cout << "Vector elements: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    /*
    erase() complexity:
    erase(begin() + i) -> O(n)
    because elements must be shifted
    */

    // Remove element at index 1
    v.erase(v.begin() + 1);

    cout << "After erase index 1: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    /*
    reserve():
    - Pre-allocates memory
    - Avoids repeated reallocations
    - Important for performance
    */

    vector<int> fast;
    fast.reserve(1000); // prevents multiple reallocations

    for (int i = 0; i < 1000; i++)
        fast.push_back(i);

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

/*
====================================================================
                    std::vector — COMPLETE THEORY
====================================================================

--------------------------------------------------------------------
1) What is std::vector?
--------------------------------------------------------------------
std::vector is a sequence container provided by the C++ Standard
Template Library (STL).

Key definition:
- It is a dynamic array that manages its own memory.

Why it exists:
- Traditional arrays have a fixed size.
- std::vector solves this by growing and shrinking automatically.

How it works internally:
- Allocates a contiguous block of memory on the heap.
- Tracks three things internally:
    1. pointer to beginning of memory
    2. current size (number of elements)
    3. current capacity (allocated slots)

When to use:
- When you need fast random access.
- When data size can change at runtime.
- When iteration speed matters.

When NOT to use:
- Frequent insertions/deletions in the middle.
- When iterator/pointer stability is required.

--------------------------------------------------------------------
2) Contiguous Memory (VERY IMPORTANT)
--------------------------------------------------------------------
"Contiguous" means:
- Elements are stored next to each other in memory.
- Similar to C-style arrays.

Why this matters:
- v[0], v[1], v[2] are adjacent in RAM.
- CPU caches work efficiently.
- Iteration is extremely fast.

Advantage:
- Best cache locality among STL containers.

Disadvantage:
- If vector grows, memory must be reallocated.
- Reallocation is expensive.

--------------------------------------------------------------------
3) size() vs capacity()
--------------------------------------------------------------------
size():
- Number of elements currently stored.
- Logical size.

capacity():
- Number of elements vector can hold
  WITHOUT allocating more memory.
- Physical size.

Why separation exists:
- To avoid allocating memory on every insertion.
- Improves performance by reducing heap operations.

Example:
If size = 5 and capacity = 8:
- 5 elements are used
- 3 slots are free

--------------------------------------------------------------------
4) push_back() — Amortized Complexity
--------------------------------------------------------------------
push_back():
- Adds element at the end of vector.

Why amortized O(1):
- Most insertions just place element in free slot.
- Occasionally, vector reallocates.

Worst case:
- O(n) when reallocation happens.
- All existing elements are copied/moved.

Amortized analysis:
- Expensive operations are rare.
- Average cost per insertion becomes constant.

--------------------------------------------------------------------
5) Reallocation — What REALLY happens
--------------------------------------------------------------------
Reallocation occurs when:
    size == capacity

Steps:
1. Allocate a new block (usually 2x capacity).
2. Copy or move all old elements.
3. Destroy old elements.
4. Free old memory.
5. Update internal pointers.

Why this is dangerous:
- All pointers become invalid.
- All references become invalid.
- All iterators become invalid.

This is a common source of bugs in interviews.

--------------------------------------------------------------------
6) reserve()
--------------------------------------------------------------------
reserve(n):
- Allocates memory upfront.
- Does NOT change size.
- Prevents multiple reallocations.

Why use it:
- When input size is known.
- Improves performance.
- Prevents iterator invalidation.

When NOT needed:
- When vector size is small.
- When size is unpredictable and small.

--------------------------------------------------------------------
7) operator[] vs at()
--------------------------------------------------------------------
operator[]:
- Fast
- No bounds checking
- Undefined behavior if index is invalid

at():
- Performs bounds checking
- Throws exception if out of range
- Slightly slower

Interview tip:
- Use operator[] when performance matters
- Use at() when safety matters

--------------------------------------------------------------------
8) erase()
--------------------------------------------------------------------
erase(pos):
- Removes element at position.
- Shifts all elements to the left.

Why O(n):
- Every element after pos must move.
- Cost increases with vector size.

Rule:
- Avoid erase in loops if possible.
- Use erase-remove idiom for conditions.

--------------------------------------------------------------------
9) Iteration
--------------------------------------------------------------------
Range-based for loop:
- Clean
- Safe
- Preferred in modern C++

Why fast:
- Sequential memory access
- Cache-friendly

--------------------------------------------------------------------
10) Advantages of std::vector
--------------------------------------------------------------------
- Fast random access
- Cache-friendly
- Easy to use
- STL algorithm compatible
- Minimal memory overhead
- Best default container choice

--------------------------------------------------------------------
11) Disadvantages of std::vector
--------------------------------------------------------------------
- Expensive middle insertions
- Expensive middle deletions
- Iterator invalidation on reallocation
- Not thread-safe
- Requires contiguous memory block

--------------------------------------------------------------------
12) When to choose vector over others
--------------------------------------------------------------------
Choose vector if:
- You need index-based access
- You need fast iteration
- Insertions are mostly at the end

Choose deque if:
- Frequent push/pop at both ends

Choose list if:
- Frequent insertions/deletions anywhere
- Iterator stability is required

====================================================================
*/

int main()
{
    vector<int> v;

    // Initially empty vector
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    // Demonstrating push_back and capacity growth
    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i * 10);
        cout << "After push_back(" << i * 10 << ") ";
        cout << "Size: " << v.size()
             << ", Capacity: " << v.capacity() << endl;
    }

    // Random access using operator[]
    cout << "v[2] = " << v[2] << endl;

    // Safe access using at()
    cout << "v.at(2) = " << v.at(2) << endl;

    // Iteration over vector
    cout << "Vector elements: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Erasing element at index 1
    v.erase(v.begin() + 1);

    cout << "After erase index 1: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Using reserve to improve performance
    vector<int> fast;
    fast.reserve(1000);

    for (int i = 0; i < 1000; i++)
        fast.push_back(i);

    return 0;
}

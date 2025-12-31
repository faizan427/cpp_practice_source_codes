#include <iostream>
#include <deque>
using namespace std;

/*
====================================================================
                    std::deque — COMPLETE THEORY (DEEP)
====================================================================

--------------------------------------------------------------------
1) What is std::deque?
--------------------------------------------------------------------
std::deque stands for "double-ended queue".

Formal definition:
- A sequence container that allows fast insertion and deletion
  at BOTH the front and the back.

Key difference from vector:
- vector is optimized for back insertions only.
- deque is optimized for both front and back.

Why std::deque exists:
- vector cannot efficiently insert at front.
- list allows insertion anywhere but sacrifices cache locality.
- deque provides a middle ground.

--------------------------------------------------------------------
2) Memory Layout (MOST IMPORTANT)
--------------------------------------------------------------------
std::deque does NOT store elements in one contiguous block.

Instead:
- It uses multiple fixed-size contiguous blocks (segments).
- These blocks are managed via an internal array of pointers.

Visualization:
    [ block ] [ block ] [ block ] [ block ]
       ^         ^         ^         ^
      contiguous chunks, but not one large array

Why this design exists:
- Allows growth at both ends without reallocating everything.
- Avoids expensive full-copy reallocation like vector.

Consequence:
- deque elements are NOT globally contiguous.
- &dq[0] and &dq[1] may not be adjacent in memory.

--------------------------------------------------------------------
3) Random Access in deque
--------------------------------------------------------------------
deque supports:
- operator[]
- at()

Complexity:
- O(1) random access (amortized)

How O(1) is achieved:
- Index calculation determines:
    - which block
    - which offset inside the block

Why slightly slower than vector:
- Extra indirection through block table.
- Less cache-friendly than vector.

--------------------------------------------------------------------
4) push_back() and push_front()
--------------------------------------------------------------------
push_back():
- Adds element at the end.
- O(1)

push_front():
- Adds element at the front.
- O(1)

Why both are O(1):
- deque allocates new blocks when needed.
- Existing elements do NOT need to move.

This is the MAIN advantage over vector.

--------------------------------------------------------------------
5) Why vector cannot do this efficiently
--------------------------------------------------------------------
vector push_front():
- Requires shifting all elements.
- O(n)

deque push_front():
- Just adds a new block or uses free space.
- O(1)

This makes deque ideal for:
- Sliding window problems
- Monotonic queues
- BFS level traversal

--------------------------------------------------------------------
6) size() and capacity() in deque
--------------------------------------------------------------------
size():
- Number of elements stored.

capacity():
- NOT exposed for deque.

Why no capacity():
- deque does not manage memory as a single block.
- Capacity is meaningless due to segmented storage.

Interview insight:
- If someone asks about deque capacity,
  answer that it is implementation-dependent and hidden.

--------------------------------------------------------------------
7) Iterator Invalidation Rules (VERY IMPORTANT)
--------------------------------------------------------------------
This is where deque differs from vector.

Operations and effects:

push_back() / push_front():
- May invalidate iterators.
- References may remain valid depending on implementation.

insert() in middle:
- Invalidates all iterators and references.

erase():
- Invalidates iterators to erased elements.

Why rules are complex:
- Block reallocation may occur.
- Internal pointer table may change.

Rule of thumb:
- Do NOT keep iterators across modifications.

--------------------------------------------------------------------
8) operator[] vs at()
--------------------------------------------------------------------
operator[]:
- No bounds checking.
- Undefined behavior if index is invalid.

at():
- Bounds-checked.
- Throws std::out_of_range.

Return type:
- Reference to element.

--------------------------------------------------------------------
9) Why deque is ideal for sliding window
--------------------------------------------------------------------
Sliding window problems require:
- push_back (new elements)
- pop_front (expired elements)

deque supports:
- O(1) insertion and deletion at both ends.
- Efficient front access.

Classic problems:
- Sliding Window Maximum
- Monotonic Queue
- BFS queue

--------------------------------------------------------------------
10) Comparison: vector vs deque vs list
--------------------------------------------------------------------
vector:
- Best cache locality
- Fastest iteration
- Expensive front insertion

deque:
- Fast front and back insertion
- Slightly slower iteration
- Random access supported

list:
- Fast insertion anywhere
- No random access
- Poor cache locality

Interview answer:
- vector is default
- deque when both ends matter
- list only when iterator stability is required

--------------------------------------------------------------------
11) Advantages of std::deque
--------------------------------------------------------------------
- O(1) push_front and push_back
- Random access supported
- No massive reallocation
- Ideal for queue-like behavior
- Used internally by std::queue

--------------------------------------------------------------------
12) Disadvantages of std::deque
--------------------------------------------------------------------
- Not contiguous memory
- Slower iteration than vector
- More complex iterator invalidation rules
- Slightly higher memory overhead

--------------------------------------------------------------------
13) When to use std::deque
--------------------------------------------------------------------
Use deque when:
- Frequent insertions at both ends
- Sliding window algorithms
- BFS traversal
- Queue-like structures with access needs

Avoid deque when:
- Heavy iteration and cache performance matters
- Memory contiguity is required

====================================================================
*/

int main()
{
    deque<int> dq;

    // push_back inserts at the end
    dq.push_back(10);
    dq.push_back(20);

    // push_front inserts at the front
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque elements: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Random access
    cout << "Element at index 2: " << dq[2] << endl;
    cout << "Element at index 2 (safe): " << dq.at(2) << endl;

    // pop operations
    dq.pop_front(); // removes first element
    dq.pop_back();  // removes last element

    cout << "After pop operations: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // size() returns size_t
    cout << "Deque size: " << dq.size() << endl;

    return 0;
}


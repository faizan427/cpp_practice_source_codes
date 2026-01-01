#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
====================================================================
            std::stack and std::queue — COMPLETE THEORY (DEEP)
====================================================================

--------------------------------------------------------------------
1) What are std::stack and std::queue?
--------------------------------------------------------------------
std::stack and std::queue are NOT containers.

They are:
- Container adaptors.

Meaning:
- They do not store data by themselves.
- They wrap an underlying container and expose
  a restricted interface.

Why container adaptors exist:
- To enforce specific data access rules.
- To prevent misuse (e.g., random access).

--------------------------------------------------------------------
2) What is a Container Adaptor?
--------------------------------------------------------------------
A container adaptor:
- Uses another container internally.
- Restricts the operations available to the user.

This provides:
- Strong abstraction
- Logical correctness
- Intent clarity

Default underlying container:
- std::deque

Why deque:
- Supports fast insertion and deletion at both ends.
- Suitable for both stack and queue behavior.

--------------------------------------------------------------------
3) std::stack — LIFO Structure
--------------------------------------------------------------------
LIFO = Last In, First Out

Analogy:
- Stack of plates
- Last plate placed is removed first

Allowed operations:
- push()
- pop()
- top()
- empty()
- size()

Disallowed:
- Random access
- Iteration
- Indexing

Why restrictions exist:
- To preserve stack semantics.
- To prevent logical errors.

--------------------------------------------------------------------
4) How std::stack Works Internally
--------------------------------------------------------------------
Internally:
- stack<T> wraps another container (default deque<T>).

Operations mapping:
- push()     -> underlying_container.push_back()
- pop()      -> underlying_container.pop_back()
- top()      -> underlying_container.back()

Why back() is used:
- O(1) access
- Natural LIFO behavior

--------------------------------------------------------------------
5) std::queue — FIFO Structure
--------------------------------------------------------------------
FIFO = First In, First Out

Analogy:
- Line of people
- First person enters first, leaves first

Allowed operations:
- push()
- pop()
- front()
- back()
- empty()
- size()

Disallowed:
- Random access
- Iteration
- Indexing

Why FIFO matters:
- Scheduling
- BFS traversal
- Resource management

--------------------------------------------------------------------
6) How std::queue Works Internally
--------------------------------------------------------------------
Internally:
- queue<T> wraps another container (default deque<T>).

Operations mapping:
- push()  -> push_back()
- pop()   -> pop_front()
- front() -> front()
- back()  -> back()

Why push_back + pop_front:
- Preserves FIFO order
- O(1) operations using deque

--------------------------------------------------------------------
7) Why vector is NOT ideal internally
--------------------------------------------------------------------
If vector were used:
- pop_front() would be O(n)
- Requires shifting elements

deque avoids this problem.

Hence deque is the default choice.

--------------------------------------------------------------------
8) size() Return Type (IMPORTANT)
--------------------------------------------------------------------
size() returns:
- size_t

Why size_t:
- Represents sizes safely
- Unsigned
- Platform dependent
- Matches memory address width

Common pitfall:
- Comparing size() with signed integers.

--------------------------------------------------------------------
9) Iterator Access (INTENTIONALLY BLOCKED)
--------------------------------------------------------------------
std::stack and std::queue:
- Do NOT expose iterators.

Why this is intentional:
- Prevents violating LIFO/FIFO rules
- Encourages correct usage
- Improves code clarity

If iteration is needed:
- Use deque or vector directly.

--------------------------------------------------------------------
10) Time Complexity Guarantees
--------------------------------------------------------------------
All allowed operations:
- push()  -> O(1)
- pop()   -> O(1)
- top()   -> O(1)
- front() -> O(1)
- back()  -> O(1)

These guarantees exist because:
- Underlying container supports O(1) operations.

--------------------------------------------------------------------
11) Advantages of std::stack
--------------------------------------------------------------------
- Enforces LIFO discipline
- Clean abstraction
- Prevents misuse
- Ideal for recursion simulation
- Used in DFS, undo operations

--------------------------------------------------------------------
12) Disadvantages of std::stack
--------------------------------------------------------------------
- No iteration
- No random access
- Less flexible
- Debugging can be harder

--------------------------------------------------------------------
13) Advantages of std::queue
--------------------------------------------------------------------
- Enforces FIFO discipline
- Ideal for BFS
- Scheduling and buffering
- Simple interface

--------------------------------------------------------------------
14) Disadvantages of std::queue
--------------------------------------------------------------------
- No iteration
- No random access
- Less control over internal storage

--------------------------------------------------------------------
15) When to Use stack vs queue
--------------------------------------------------------------------
Use std::stack when:
- Backtracking
- DFS
- Expression evaluation
- Undo/Redo

Use std::queue when:
- BFS
- Task scheduling
- Producer-consumer models

Avoid both when:
- You need traversal or indexing
- Use deque or vector instead

--------------------------------------------------------------------
16) Custom Underlying Container (Advanced)
--------------------------------------------------------------------
You can specify underlying container explicitly:

Example:
- stack<int, vector<int>>
- queue<int, list<int>>

Constraints:
- Container must support required operations.

Why rarely used:
- Default deque is optimal for most cases.

====================================================================
*/

int main()
{
    // ================== std::stack ==================
    stack<int> st;

    // push elements (LIFO)
    st.push(10);
    st.push(20);
    st.push(30);

    // top() gives last inserted element
    cout << "Stack top: " << st.top() << endl;

    // pop removes top element
    st.pop();

    cout << "Stack top after pop: " << st.top() << endl;

    // size() returns size_t
    cout << "Stack size: " << st.size() << endl;

    // ================== std::queue ==================
    queue<int> q;

    // push elements (FIFO)
    q.push(1);
    q.push(2);
    q.push(3);

    // front() gives first inserted element
    cout << "Queue front: " << q.front() << endl;

    // back() gives last inserted element
    cout << "Queue back: " << q.back() << endl;

    // pop removes front element
    q.pop();

    cout << "Queue front after pop: " << q.front() << endl;

    // size() returns size_t
    cout << "Queue size: " << q.size() << endl;

    return 0;
}


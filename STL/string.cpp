#include <iostream>
#include <string>
using namespace std;

/*
====================================================================
                    std::string — COMPLETE THEORY (DEEP)
====================================================================

--------------------------------------------------------------------
1) What is std::string?
--------------------------------------------------------------------
std::string is a class template specialization designed to represent
and manage sequences of characters.

Internally:
- Manages a dynamically allocated character buffer.
- Keeps track of:
    - current length
    - capacity
    - pointer to storage (or inline buffer for SSO)

Why std::string exists:
- C-style strings (char*) rely on null-termination.
- Operations like strlen() are O(n).
- Manual memory management causes:
    - buffer overflows
    - dangling pointers
    - memory leaks

std::string provides:
- Size tracking
- Automatic resizing
- Bounds-aware operations
- RAII-based memory management

--------------------------------------------------------------------
2) Contiguous Storage Guarantee
--------------------------------------------------------------------
C++ standard guarantees:
- Characters are stored contiguously.
- &s[0] gives pointer to internal buffer (C++11+).

Why this matters:
- Enables efficient iteration.
- Allows interoperability with C APIs via c_str().
- Improves cache locality.

Important caveat:
- Contiguous does NOT imply fixed location.
- Reallocation may occur on modification.

--------------------------------------------------------------------
3) Small String Optimization (SSO)
--------------------------------------------------------------------
SSO is an optimization, not a language feature.

What it does:
- Stores short strings directly inside the std::string object.
- Avoids heap allocation for small sizes.

Why it exists:
- Heap allocation is expensive.
- Most real-world strings are short.

How it works:
- Implementation-dependent.
- Typical inline capacity: 15–23 characters.

When SSO breaks:
- When string exceeds inline capacity.
- Heap allocation occurs.

Performance implication:
- Copying small strings is cheap.
- Copying large strings is expensive.

--------------------------------------------------------------------
4) size() vs length()
--------------------------------------------------------------------
Both return:
- Number of characters in the string.
- Type: size_t

Why both exist:
- size(): STL container consistency
- length(): string semantic clarity

There is:
- No semantic difference
- No performance difference

--------------------------------------------------------------------
5) What is size_t? (IMPORTANT)
--------------------------------------------------------------------
size_t is:
- An unsigned integer type.
- Defined by the standard library.

Purpose:
- Represents sizes and counts.
- Large enough to hold the maximum size of any object.

Why size_t is used:
- Prevents negative sizes.
- Matches memory address space.
- Platform dependent:
    - 32-bit on 32-bit systems
    - 64-bit on 64-bit systems

Why NOT int:
- int may overflow for large containers.
- size_t matches allocator interfaces.

Common pitfall:
- Comparing size_t with signed int causes bugs.

--------------------------------------------------------------------
6) operator[] vs at()
--------------------------------------------------------------------
operator[]:
- No bounds checking.
- Fast.
- Undefined behavior on invalid index.

at():
- Performs bounds checking.
- Throws std::out_of_range exception.
- Slightly slower.

When to use:
- operator[] in performance-critical code
- at() in safety-critical code

--------------------------------------------------------------------
7) substr()
--------------------------------------------------------------------
substr(pos, len):
- Allocates a NEW std::string.
- Copies characters from source.

Complexity:
- O(len)

Why this matters:
- Repeated substr() in loops is expensive.
- Hidden memory allocations.

Better alternative (when applicable):
- Use indices.
- Use std::string_view (C++17).

--------------------------------------------------------------------
8) find()
--------------------------------------------------------------------
find():
- Searches for a character or substring.

Return type:
- size_t

Return values:
- Index of first occurrence if found.
- string::npos if not found.

Complexity:
- Worst case O(n * m)
- No guaranteed advanced algorithm.

--------------------------------------------------------------------
9) What is string::npos? (CRITICAL)
--------------------------------------------------------------------
string::npos is:
- A static constant of type size_t.
- Represents "no position".

Actual value:
- size_t(-1)
- Maximum possible value of size_t.

Why not return -1:
- size_t is unsigned.
- Returning -1 would wrap.

Correct usage:
- Always compare find() result with string::npos.
- Never compare with -1.

--------------------------------------------------------------------
10) append() vs operator+=
--------------------------------------------------------------------
append():
- Explicit function call.
- Clear intent.

operator+=:
- Syntactic sugar.
- Same complexity and behavior.

Internally:
- Both may trigger reallocation.

--------------------------------------------------------------------
11) c_str() — Lifetime and Danger
--------------------------------------------------------------------
c_str():
- Returns const char*
- Null-terminated buffer
- Owned by std::string

Lifetime rules:
- Pointer is valid ONLY until:
    - string is modified
    - string is destroyed

Why dangerous:
- Any modification invalidates pointer.
- Causes dangling pointer bugs.

Correct usage:
- Use immediately.
- Do NOT store pointer long-term.

--------------------------------------------------------------------
12) Copy vs Move Semantics
--------------------------------------------------------------------
Copy:
- Allocates new memory.
- Copies characters.
- O(n)

Move:
- Transfers ownership of buffer.
- O(1)
- Source left in valid but unspecified state.

Triggered by:
- Returning std::string from functions.
- std::move usage.

--------------------------------------------------------------------
13) Advantages of std::string
--------------------------------------------------------------------
- Automatic memory management
- Safe and expressive
- Contiguous storage
- SSO optimization
- STL compatible
- RAII-based lifetime

--------------------------------------------------------------------
14) Disadvantages of std::string
--------------------------------------------------------------------
- substr() creates copies
- Reallocation invalidates pointers
- Hidden allocation costs
- Not thread-safe
- Inefficient for heavy slicing

--------------------------------------------------------------------
15) When to use std::string
--------------------------------------------------------------------
Use when:
- Text manipulation is required
- Safety matters
- DSA problems

Avoid when:
- Zero-copy slicing is required
- Working with raw buffers

====================================================================
*/

int main()
{
    // Creating strings
    string s1 = "Hello";
    string s2("World");

    // size() and length() return size_t
    cout << "s1 size: " << s1.size() << endl;
    cout << "s1 length: " << s1.length() << endl;

    // Concatenation
    s1 += " ";
    s1.append(s2);

    cout << "Concatenated string: " << s1 << endl;

    // Access characters
    cout << "First character: " << s1[0] << endl;
    cout << "Second character (safe): " << s1.at(1) << endl;

    // Substring creation (copy)
    string sub = s1.substr(0, 5);
    cout << "Substring: " << sub << endl;

    // find() returns size_t
    size_t pos = s1.find("World");

    // string::npos means "not found"
    if (pos != string::npos)
        cout << "Found at position: " << pos << endl;

    // c_str() usage
    const char* cstr = s1.c_str();
    cout << "C-style string: " << cstr << endl;

    return 0;
}


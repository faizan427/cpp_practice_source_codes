#include <iostream>
#include <memory>
using namespace std;
class B_in_stack;

class A_in_stack
{
public:
	A_in_stack()
{
	cout << "A created" << endl;
}
	shared_ptr<B_in_stack> holds_B_add_in_heap;

	~A_in_stack()
{
	cout << "A deleted" << endl;
}
};

class B_in_stack
{
public:
	B_in_stack()
{
	cout << "B created" << endl;
}
	shared_ptr<A_in_stack> holds_A_add_in_heap;

	~B_in_stack()
{
	cout << "B deleted" << endl;
}
};


int main()
{
shared_ptr<A_in_stack>A_in_heap(make_share<A_in_stack>());
shared_ptr<B_in_stack>B_in_heap(make_share<B_in_stack>());
A_in_heap->holds_B_add_in_heap = B_in_heap;
B_in_heap->holds_A_add_in_heap = A_in_heap;
cout << "A_in_heap->holds_B_add_in_heap"<< A_in_heap->holds_B_add_in_heap.use_count() << endl;

return 0;
}

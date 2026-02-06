#include <iostream>
#include <memory>
using namespace std;
class A_inside_stack;
class B_inside_stack
{
public:
	B_inside_stack()
{
	cout << "B Created" << endl;
}
	shared_ptr<A_inside_stack> holds_A_in_heap;
	~B_inside_stack()
{
	cout << "B deleted" << endl;
}

};
class A_inside_stack
{
public:
	A_inside_stack()
{
	cout << "A Created" << endl;
}
	weak_ptr<B_inside_stack> watches_B_in_heap;
	~A_inside_stack()
{
	cout << "A deleted" << endl;
}

};
int main()
{
shared_ptr<A_inside_stack> A_in_heap(make_shared<A_inside_stack>());
shared_ptr<B_inside_stack> B_in_heap(make_shared<B_inside_stack>());
A_in_heap->watches_B_in_heap = B_in_heap;
B_in_heap->holds_A_in_heap = A_in_heap;
auto get_hold = A_in_heap->watches_B_in_heap.lock();
cout << get_hold.use_count() << endl;

return 0;
}

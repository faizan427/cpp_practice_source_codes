#include <iostream>
#include <memory>
using namespace std;
class A_inside_stack;
class B_inside_stack
{
public:
	B_inside_stack()
{
	cout << "B created" << endl;
}
	shared_ptr<A_inside_stack> hold_A_in_heap;
	~B_inside_stack()
{
	cout << "B destroyed" << endl;
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
	cout << "A destroyed" << endl;
}

};
int main()
{
shared_ptr<A_inside_stack> A_inside_heap(make_shared< A_inside_stack> ());
shared_ptr<B_inside_stack> B_inside_heap(make_shared< B_inside_stack>());
A_inside_heap->watches_B_in_heap = B_inside_heap;
B_inside_heap->hold_A_in_heap = A_inside_heap;
unique_ptr<int>(new int(5));

return 0;
}

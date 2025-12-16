#include <iostream>
#include <memory>
using namespace std;
class A_in_stack;
class B_in_stack
{
public:
	shared_ptr<A_in_stack> owns_heap_address_of_A;
	B_in_stack()
{
	cout << "B_in_stack object created\n";
}
	~B_in_stack()
{
	cout << "B object destroyed\n";
}
};
class A_in_stack
{
public:
	shared_ptr<B_in_stack> owns_heap_address_of_B;
	A_in_stack()
{
	cout << "A_in_stack object created\n";
}
	~A_in_stack()
{
	cout << "A object destroyed\n";
}
};
int main()
{
shared_ptr<B_in_stack> B_copy_in_heap = make_shared<B_in_stack>();
shared_ptr<A_in_stack> A_copy_in_heap = make_shared<A_in_stack>();
B_copy_in_heap->owns_heap_address_of_A = A_copy_in_heap;
A_copy_in_heap->owns_heap_address_of_B = B_copy_in_heap;

return 0;
}

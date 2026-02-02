#include <iostream>
#include <memory>
using namespace std;
class A_in_stack;
class B_in_stack
{
public:
	shared_ptr<A_in_stack> holding_A_add_in_heap;
	B_in_stack()
{
	cout << "B created " << endl;
}
       ~ B_in_stack()
{ 
        cout << "B destroyed " << endl;
} 
};
class A_in_stack{
public:
	weak_ptr<B_in_stack> watching_B_add_in_heap;
        A_in_stack()
{ 
        cout << "A created " << endl;
} 
       ~ A_in_stack()
{ 
        cout << "A destroyed " << endl;
} 
};
int main()
{
shared_ptr<B_in_stack> b_copy_inside_heap(make_shared<B_in_stack>());
shared_ptr<A_in_stack> a_copy_inside_heap(make_shared<A_in_stack>());
b_copy_inside_heap->holding_A_add_in_heap = a_copy_inside_heap;
a_copy_inside_heap->watching_B_add_in_heap = b_copy_inside_heap;
cout << "holding_A_add_in_heap--->ref_count " << b_copy_inside_heap->holding_A_add_in_heap.use_count() << endl;
cout << "holding_B_add_in_heap--->ref_count " << a_copy_inside_heap->watching_B_add_in_heap.use_count() << endl; 

return 0;
}

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
int main()
{



return 0;
}

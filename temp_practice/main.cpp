#include <iostream>
using namespace std;
class demo
{
public:
	int val;
	int *ptr;

	demo(int val): val(val), ptr(new int(val))
{
	cout << "normal constructor called" << endl;
}
	~demo()
{
	delete ptr;
}
	demo(demo &obj)
{
	
	this->val = obj.val;
	
	this->ptr = new int(obj.val);
}
};
int main()
{
demo A(5);
demo B(A);

return 0;
}

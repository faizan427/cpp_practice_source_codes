#include <iostream>
using namespace std;
class demo
{
public:
	int val;
	int *ptr;
	demo(int val): val(val), ptr(new int(this->val)){}
	demo(demo &obj)
{
	cout << "shallow" << endl;
	this->val = obj.val;
	this->ptr = obj.ptr;
}	
	demo(demo obj)
{
	cout << "deep" << endl;

	this->val = obj.val;
	this->ptr = new int(this->val);
}
};
int main()
{
demo D(5);
demo C = D;

return 0;
}

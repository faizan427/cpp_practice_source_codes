#include <iostream>
using namespace std;
class base
{
public:
	int i ;
	base(int i):i(i)
{
	cout << "base constructor called" << endl;
}
};
class derived: public base
{
public:
	int x;
	derived(int x, int v): x(x), base(v){}
};
int main()
{
derived d(2,3);

return 0;
}

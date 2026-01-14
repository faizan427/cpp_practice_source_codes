#include <iostream>
using namespace std;
class demo
{
public:
	int a;
	demo() = default;
	demo(int a): a(a){}
	demo & operator  = (demo &obj)
{
	this->a = obj.a;
	return *this;
}
};
int main()
{
demo d(3);
demo c, e;
c = e= d;
cout << c.a << " " << e.a << endl;


return 0;
}

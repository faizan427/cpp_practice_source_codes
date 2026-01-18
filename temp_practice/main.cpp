#include <iostream>
using namespace std;
class base
{
public:
	base()
{
	cout << "base called\n";
}
virtual	~base()
{
	cout << "base destroyed\n";
}
};
class derived: public base
{
public:
	derived()
{
	cout << "derived called\n";
}
	~derived()
{
	cout << "derived destroyed\n";
}
};
int main()
{
base *b = new derived;
delete b;

return 0;
}

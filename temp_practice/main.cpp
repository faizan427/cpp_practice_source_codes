#include <iostream>
using namespace std;
class base
{
public:
	base()
{
	cout << "base created" << endl;
}
virtual	~base()
{
	cout << "base destroyed" << endl;
}
};
class derived: public base
{
public:
	derived()
{
	cout << "derived created" << endl;
}
	~derived()
{
	cout << "derived destroyred" << endl;
}
};
int main()
{
base *b = new derived;
delete b;

return 0;
}

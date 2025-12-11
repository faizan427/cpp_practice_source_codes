#include <iostream>
#include <stdio.h>
using namespace std;
class base
{
public:
	base()
{
	cout << "Base constructor is called\n";
}
	virtual	~base()
{
	cout << "Base Destructor is called\n";
}
};
class derived: public base
{
public:
	derived()
{
	cout << "Derived Constructor is called\n";
}
	~derived()
{
	cout << "Derived Destructor is called\n";
}
};
int main()
{
base *B = new derived;
delete B; // If we do not specify destructor of base class as virtual.
	  // Then only destructor of base class would be called.
	  // And destructor of derived class wont be called at all.


return 0;
}

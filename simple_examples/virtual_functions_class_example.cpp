#include <iostream>
#include <stdio.h>
using namespace std;
class base
{
public:
	base()
{
	cout << "base constructor is called\n";
}
	virtual void func()
{
	cout << "function from base class is called\n";
}
	~base()
{
	cout << "base destructor is called\n";
}
};
class derived: public base
{
public:
	derived()
{
	cout << "derived constructor is called\n";
}
	void func()
{
	cout << "function from derived class is called\n";
}
	~derived()
{
	cout << "destructor of derived class is derived\n";
}
};
int main()
{
base * B;
derived D;
B = &D;
B->func();

return 0;
}

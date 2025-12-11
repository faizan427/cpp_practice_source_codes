#include <iostream>
#include <stdio.h>
using namespace std;
class base
{
public:
	base()
{
	cout << "Base Contructor is called\n";
}
	virtual	void func() = 0;
	~base()
{
	cout << "Base Destructor is called\n";
}
};
class derived:public base
{
public:
	derived()
{
	cout << "Derived Constructor is called\n";
}
	void func() override
{
	cout << "A pure virtual function from derived class is called\n";
}
	~derived()
{
	cout << "Derived Destructor is called\n";
}
};
int main()
{
base *B;
derived D;
B = &D;
B->func();
D.func();



return 0;
}

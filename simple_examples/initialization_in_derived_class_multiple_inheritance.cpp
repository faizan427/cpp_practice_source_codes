#include <iostream>
#include <stdio.h>
using namespace std;
class base_1
{
public:
	int b_1;
	base_1(int a):b_1(a)
{
	cout << "base_1 constructor called\n";
}
	~base_1()
{
	cout << "base_1 destructor called\n";
}
};
class base_2
{
public:
	int b_2;
	base_2(int b): b_2(b)
{
	cout << "base_2 constructor called\n";
}
	~base_2()
{
	cout << "base_2 destructor called\n";
}
};
class derived: public base_1, public base_2
{
public:
	int d_1, d_2;
	derived(int x, int y, int p, int q): base_1(x), base_2(y), d_1(p), d_2(q)
{
	cout << "derived constructor is called\n";
}
	void show()
{
	cout << "b_1 = " << b_1 << " b_2 = " << b_2 << " d_1 = " << d_1 << " d_2 = " << d_2 << endl;
}
	~derived()
{
	cout << "Derived destructor is called\n";
}
};
int main()
{
derived D(1,2,3,4);
D.show();
return 0;
}

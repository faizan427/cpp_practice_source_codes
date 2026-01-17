#include <iostream>
using namespace std;
class empty_
{

};
class with_virtual_function
{
	virtual void func()=0;

	char i ;
	int z;

	char x;
};
class derived : with_virtual_function{};
int main()
{
cout << "empty " << sizeof(empty_) << endl;
cout << "with_virtual_function " << sizeof(with_virtual_function) << endl;
cout << "derived " << sizeof(derived) << endl;
return 0;
}

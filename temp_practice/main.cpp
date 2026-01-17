#include <iostream>
using namespace std;
#include <unistd.h>
int * func(int *&ptr)
{
	ptr = nullptr;
	return ptr;
}
int main()
{
int *ptr = new int(5);
cout << "ptr = " << ptr << " value = " << *ptr << endl;

cout << "func(ptr) = " << func(ptr) << endl; 
sleep(3);
cout <<" value = " << *ptr << endl;


return 0;
}

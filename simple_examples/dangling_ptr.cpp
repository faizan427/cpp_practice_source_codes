#include <iostream>
#include <stdio.h>
using namespace std;
int * dangling_ptr(int *&ptr)
{
	delete ptr;
	return ptr;

}
int main()
{
int *ptr = new int(5);
cout << "ptr = " << ptr << " value = " << *ptr << endl;
int *ntr = dangling_ptr(ptr);
cout << "ptr = " << ptr << endl;
cout << "value = " << *ptr << endl;
return 0;
}

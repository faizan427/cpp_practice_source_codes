#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;
int * leak_memory(int *&ptr)
{
	ptr = nullptr;
	return ptr;
}
int main()
{
int *ptr = new int(5);
cout << "ptr address is " << ptr << " and the value stored inside is " << *ptr << endl;
cout << "ptr address is " << leak_memory(ptr) << endl; 
sleep(3);
cout << " and the value stored inside is " << *(leak_memory(ptr)) << endl;

return 0;
}

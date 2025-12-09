#include <iostream>
#include <stdio.h>
using namespace std;
int max(int a, int b)
{
return a>b?a:b;
}
int min(int a, int b)
{
return a<b?a:b;
}
int main()
{
int (*f_ptr)(int, int);
f_ptr= max;
cout << "max is " <<(*f_ptr)(10,5) << endl;
f_ptr = min;
cout << "min is " << (*f_ptr)(10,5) << endl;
return 0;
}

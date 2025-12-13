#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int a=10;
[a](){cout << "a captured by value = " << a << endl; }();
return 0;
}

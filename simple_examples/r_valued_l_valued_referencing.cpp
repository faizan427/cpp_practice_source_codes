#include <iostream>
#include <stdio.h>
using namespace std;
void func(int &x)
{
	cout << "x = "<< x <<" L-Valued referencing function called\n";
}
void func(int &&x)
{
	cout << "x = "<< x << " R-valued referencing function called\n";
}
int main()
{
int a=10;
func(a); // L-valued will be called //
func(20); // R-valued will be called //
func(a+30); // R-valued will be called //
return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
T max_o_3_nums(T a, T b, T c)
{
	return a>b&&a>c?a:b>c?b:c; 
}
int main()
{
cout << "enter 3 integers\n";
int a,b,c;
cin >> a >>b >>c;
cout << "max is " << max_o_3_nums(a,b,c) << endl;
cout << "enter 3 floating points\n";
float x,y,z;
cin >> x >>y >>z;
cout << "max is " << max_o_3_nums(x,y,z) << endl;

return 0;
}

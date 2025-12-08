#include <iostream>
#include <stdio.h>
using namespace std;
int &l_valued_func(int &val)
{
	return val;
}
int main()
{
int val;
l_valued_func(val)=2;
cout << l_valued_func(val) << endl;


return 0;
}

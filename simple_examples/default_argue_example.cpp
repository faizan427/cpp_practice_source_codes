#include <iostream>
#include <stdio.h>
using namespace std;
int max(int a , int b=3)
{
	return a>b?a:b;
}
int main()
{
cout << "max is " << max(4) << endl;

}

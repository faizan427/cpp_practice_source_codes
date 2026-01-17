#include <iostream>
using namespace std;
int max(int &&a, int &&b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}
int main()
{
int (*fptr)(&&int,&&int);
fptr = max;
cout << (*fptr)(2,3) << endl;
return 0;
}

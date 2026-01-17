#include <iostream>
using namespace std;
int func(int a , int b) noexcept
{
	if(b==0)
{
	throw 404;
}
	else 
{
	return a%b;
}
}
int main()
{
try 
{
	int z = func(4,0);	
}
catch(int e)
{
	cout << e << endl;
}

return 0;
}

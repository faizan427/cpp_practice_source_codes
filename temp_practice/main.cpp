#include <iostream>
using namespace std;
void func(int a , int b)
{
if(b==0)
{
	throw 404;
}
else
{
	cout << "Division = "  << a/b << endl;
}
}
int main()
{
try 
{
	func(8,0);
}
catch(int e)
{
	cout << "Error " << e << "found" << endl;
}

return 0;
}

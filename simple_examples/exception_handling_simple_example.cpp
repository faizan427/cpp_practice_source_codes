#include <iostream>
using namespace std;
int division(int a, int b)
{
	if(b==0)
{
	throw 1;
}
	else 
{
	return a%b;	
}

}
int main()
{
cout << "enter two integers\n";
int a,b;
cin >> a >> b;
try 
{
	cout << "Remainder = " << division(a,b) << endl;
}

catch(int e)
{
	cout << "Error ! " << e << endl;
}
return 0;
}

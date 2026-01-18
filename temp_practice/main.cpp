#include <iostream>
#include <string>
using namespace std;
int main()
{
string str("");
cin >> str;
for(auto itr = str.begin(); itr < str.end(); itr++)
{
	if((*itr)>= 97 &&(*itr)<=122)
{
//	cout << (*itr)<<" " ;

	(*itr)-=32;
}
	else
{
//	cout << (*itr)<<" " ;
	(*itr)+=32;
}
}
cout << str << endl;

return 0;
}

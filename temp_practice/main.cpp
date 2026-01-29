#include <iostream>
#include <string>
using namespace std;
int main()
{
string str("HeLo");
for(auto itr = str.begin(); itr!= str.end(); itr++)
{
	cout << (*itr) << " " ;
	if(*itr >= 97 && *itr <= 122)
{
	*itr= *itr-32;
}
	else
{
	*itr =*itr +32;
}
}
cout << str << endl;
return 0;
}

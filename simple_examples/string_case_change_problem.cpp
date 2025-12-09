#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string to_upper_case_changer(string &str)
{
	
	string::iterator itr;
	for(itr = str.begin(); itr != str.end(); itr++)
{
	if(*(itr)>= 97 && *itr <=122)
{
	 (*itr) = *(itr)-32;
}
}
return str;
}
int main()
{
cout << "Enter your string here\n";
string str ="";
cin >> str;
cout << to_upper_case_changer(str);

}

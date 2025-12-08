#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
cout << "enter number \n";
int number;
cin>> number;
switch(number)
{
case 12 : cout << "number entered is " << number << endl;
break;
case 10 : cout << "number entered is " << number << endl;
break;
default: cout << "number entered is something else " << endl;
}
return 0;
}

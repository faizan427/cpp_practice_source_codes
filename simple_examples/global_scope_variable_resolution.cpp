#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string var = "global scope variable";
int main()
{
string var = "local scope variable";
cout << var << endl;
cout << ::var << endl;

}

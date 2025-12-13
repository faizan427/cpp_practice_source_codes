#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
cout << [](int a , int b){return a+b;}(2,3) << endl;
return 0;
}

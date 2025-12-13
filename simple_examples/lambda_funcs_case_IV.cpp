#include <iostream>
using namespace std;
int main()
{
int a = 20;
auto func = [a](){cout << "variable captured by value = " << a << endl; };
func();
return 0;
}

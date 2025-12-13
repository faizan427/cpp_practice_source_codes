#include <iostream>
using namespace std;
int main()
{
int a = 3;
auto func = [&a](){cout << "Variable captured by reference = " << a << endl;};
func();
a++;
func();
return 0;
}

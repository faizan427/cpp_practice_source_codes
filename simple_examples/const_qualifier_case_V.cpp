#include <iostream>
using namespace std;
void func() const
{
int a=2;
a++;
}
int main()
{
func();
return 0;
}

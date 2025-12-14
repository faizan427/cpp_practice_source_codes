#include <iostream>
using namespace std;
void func(const int a =2)
{
cout << a++ << endl;
}
int main()
{
func();
}



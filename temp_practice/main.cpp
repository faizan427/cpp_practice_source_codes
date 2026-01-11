#include <iostream>
using namespace std;
void func_1(int &a , int &b)
{
	cout << "l valued called " << a+b << endl;
}
void func_2(int &&a, int &&b)
{
	cout << "r valued called " << a+b << endl;
}
int main()
{
int a =2, b=3;
func_1(2,3);
func_2(2,4);

return 0;
}

#include <iostream>
using namespace std;
union my_union
{
	float z;

long long	int a;
};
int main()
{
my_union x;

x.z = 3;
cout << sizeof(my_union) << endl;
x.a =10;
cout << sizeof(my_union) << endl;
cout << x.z << endl;

return 0;
}

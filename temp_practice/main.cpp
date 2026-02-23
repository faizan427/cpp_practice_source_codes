#include <iostream>
using namespace std;
template <typename T>
auto * func(T *add )
{
	add = nullptr;
	return add;
}
int main()
{
int *ptr = new int[3]();
cout << func<int>(ptr) << endl;
return 0;
}

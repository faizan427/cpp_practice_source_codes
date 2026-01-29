#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
class demo
{
public:
	static T max(T a, T b, T c);
};
template <typename T>
T demo<T>::max(T a, T b, T c)
{
	return a>b&&a>c?a:b>c?b:c;
}
int main()
{
cout << demo<int>::max(3,4,5) << endl;
cout << demo<float>::max(3.4,4.1,-5.0) << endl;

return 0;
}

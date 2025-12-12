#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
class demo
{
private:
	static T a,b,c; 
public:
	demo()=default;
	static T max(T x, T y, T z);
};
template <typename T>
T demo<T>::a =0;
template <typename T>
T demo<T>::b =0;
template <typename T>
T demo<T>::c =0;
template <typename T>
T demo<T>::max(T x, T y, T z)
{
	a = x;
	b = y;
	c = z;
	return a>b&&a>c?a:b>c?b:c;
}
int main()
{
cout << demo<int>::max(5,3,0) << endl;
cout << demo<float>::max(3.33,33.3,0.33) << endl;
return 0;
}

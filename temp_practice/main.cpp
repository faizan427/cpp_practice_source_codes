#include <iostream>
using namespace std;
template <typename T>
class maxi
{
public:
	static T a,b,c;
	static T func(T &&a, T &&b, T &&c);
};
template <typename T>
T maxi<T>::func(T &&a, T &&b, T &&c)
{
	return a>b&&a>c?a:b>c?b:c;
}
int main()
{
cout << maxi<int>::func(3,4,5) <<endl;

return 0;
}

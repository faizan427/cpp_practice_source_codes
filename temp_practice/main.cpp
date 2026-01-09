#include <iostream>
using namespace std;
template <typename T>
T max(T a, T b, T c)
{
	return a>b&&a>c?a:b>c?b:c;
}
int main()
{
cout << max(3,4,5) << " " << max(3.14,3.04,3.004) << endl;
return 0;

}


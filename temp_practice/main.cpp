#include <iostream>
using namespace std;
class demo
{
public:
	int var;
	demo() =default;
	demo(int var):var(var){}
	bool operator == (int val)
{
	return this->var == val;
}
};
int main()
{
demo s(2), k(2);
cout << boolalpha << (s==2) << endl;


return 0;
}

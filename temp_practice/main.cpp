#include <iostream>
using namespace std;
class demo
{
public:
mutable int x=1;
	void func() const
{
	cout << x++;	
}
};
int main()
{
demo d;
d.func();

return 0;
}

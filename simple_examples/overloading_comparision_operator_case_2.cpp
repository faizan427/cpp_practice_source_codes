#include <iostream>
using namespace std;
class area
{
private:
	int a;
public:
	area()=default;
	area(int a): a(a){}
	bool operator > (int val)
{
	return this->a > val;
}
	bool operator < (int val)
{
	return this->a < val;
}
};
int main()
{


return 0;
}

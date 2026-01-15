#include <iostream>
using namespace std;
class area
{
private:
	int a;
	area()=default;
	area(int a): a(a){}
	bool operator > (area &obj)
{
	return this->a > obj.a;
}
	bool operator < (area &obj)
{
	return this->a < obj.a;
}

};
int main()
{

return 0;
}

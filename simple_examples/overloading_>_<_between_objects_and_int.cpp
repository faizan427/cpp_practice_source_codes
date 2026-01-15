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
	return  this->a < val;
}
};
int main()
{
area main_land(15);
cout << "(main_land > 20) = " << boolalpha << (main_land > 20) << endl;
cout << "(main_land < 18 ) = " << boolalpha << (main_land < 18) << endl;
return 0;
}

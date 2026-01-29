#include <iostream>
using namespace std;
class area
{
public:
	int val =10;
	area(int val):val(val){}
friend	bool operator > (int val, area &obj);
friend bool operator < (int val, area &obj);
	bool operator > (area &obj)
{
	return this->val > obj.val;
}
	bool operator < (area &obj)
{
	return this->val < obj.val;
}
};
bool operator > (int val, area &obj)
{
	return val > obj.val;
}
bool operator < (int val, area &obj)
{
	return val < obj.val;
}
int main()
{


return 0;
}

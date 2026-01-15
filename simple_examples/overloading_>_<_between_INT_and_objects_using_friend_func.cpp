#include <iostream>
using namespace std;
class area
{
private:
	int a;
public:
	area()=default;
	area(int val): a(val){}
friend	bool operator > (int val, area &obj);
};
bool operator > (int val, area &obj)
{
	return val>obj.a;
}

int main()
{
area ten(10);
cout << "11 > ten(10) " << boolalpha << (11 > ten) << endl;

return 0;
}

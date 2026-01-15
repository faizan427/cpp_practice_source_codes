#include <iostream>
using namespace std;
class area
{
private:
	int a;
public:
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
area one(1), two(2), three(3);
cout << "(one < two) = " <<boolalpha << (one < two) << endl;
cout << " (two > three) =  "<< boolalpha << (two > three) << endl;
return 0;
}

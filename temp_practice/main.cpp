#include <iostream>
using namespace std;
class area
{
public:
	int val;
public:
	area(int i ): val(i){}
	bool operator > (area &obj){ return this->val > obj.val;}
	bool operator < (area &obj){ return this->val < obj.val;}
friend	bool operator < (int val, area &obj);
friend	bool operator > (int val, area &obj);
	area & operator ++ ()
{
	this->val = this->val +1;
	return *this;
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
area two(2), one(1);
cout << boolalpha << (one > two) << endl;
cout << boolalpha << (one < two) << endl;
cout << boolalpha << (10 < two) << endl;
cout << boolalpha << (1 < two) << endl;
area nine(9);
++nine;
cout << nine.val << endl;
return 0;
}

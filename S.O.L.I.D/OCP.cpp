#include <iostream>
using namespace std;
class shape
{
public:
	shape() = default;
	~shape() = default;
virtual	void area(int a , int b) = 0;
};
class square : public shape
{
public:
	void area(int a , int b) override
{
	cout << "Area of square = " << (a*b) << endl;
}
};
class triangle : public shape 
{
public:
	void area(int a , int b) override
{
	cout << "Area of triangle = " << (a*b)/2 << endl;
}
};
int main()
{
square S;
S.area(2,3);
triangle T;
T.area(4,4);

return 0;
}

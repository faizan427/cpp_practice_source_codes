#include <iostream>
using namespace std;
class shape
{
public:
	virtual void info() 
{
	cout << "a generic shape" << endl;
}
};
class circle: public shape
{
public:
	void info() override 
{
	cout << "a circle" << endl;
}
};
class square: public shape
{
public:
	void info() override 
{
	cout << "a square" << endl;
}
};

int main()
{
circle C;
shape &unknown = C;
unknown.info();

return 0;
}

#include <iostream>
using namespace std;
class shape
{
public:
	virtual void func()=0;
};
class square: public shape
{
public:
	void func() override{}
};
class circle: public shape
{
public:
	void func() override{}

};
int main()
{
shape * my_shape = new circle;
auto unknown_shape = static_cast<circle*>(my_shape);
if(unknown_shape)
{
cout << "yes !! i was a " << typeid(unknown_shape).name() << endl;
}
else
{
cout << "oops i was " << typeid(unknown_shape).name() << endl;
}

return 0;
}

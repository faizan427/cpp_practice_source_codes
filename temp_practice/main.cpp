#include <iostream>
using namespace std;
class shape
{
public:
	virtual void say()=0;
};
class square: public shape
{
public:
	void say() override
{
	cout << "i am a square" << endl;
}
};
class circle: public shape{
public:
	void say() override 
{
	cout << "i am a circle" << endl;
}	
};
// RTTI
int main()
{
shape * my_shape = new square;
my_shape->say();
circle *My_sqaure = dynamic_cast<circle*>(my_shape);
if(My_sqaure)
{
	 My_sqaure->say();
}
else
{
cout << "i was never a square" << endl;
cout << typeid(My_sqaure).name();
}
return 0;
}

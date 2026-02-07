#include <iostream>
using namespace std;
class shape
{
public:
	virtual void info()=0;
};
class square: public shape
{
	void info() override
{
	cout << "i am square" <<endl;
}
};
class circle: public shape
{
	void info() override
{
	cout << "i am circle" <<endl;
}
};
int main()
{
shape *my_shape = new circle;
auto *unknown = static_cast<circle*>(my_shape);
if(unknown)
{
cout << "i was a circle" << endl;
}
else 
{
cout << "maybe i was a " << typeid(unknown).name() << endl;
}

return 0;
}

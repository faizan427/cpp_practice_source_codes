#include <iostream>
using namespace std;
class shape
{
public:
	virtual void func() =0;
};
class square: public shape
{
public:
	void func(){}
};
class circle: public shape
{

public:
	void func(){}
};
int main()
{
shape *S = new square;
auto N = dynamic_cast<circle*>(S);
if(N)
{
cout << "casted to " << typeid(N).name() << endl;
}
else
{
cout << "not casted" << endl;
}

return 0;
}

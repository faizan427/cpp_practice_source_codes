#include <iostream>
using namespace std;
class shape
{
public:
	virtual void info() =0;
};
class square: public shape
{
public:
	void info()
{
	cout << "i am square" << endl;
}
};
class circle: public shape
{
public:
	void info()
{
	cout << "i am circle" << endl;
}
};

int main()
{
shape *S = new square;
S->info();
auto unknown = static_cast<circle*>(S);
if(unknown)
{
cout << "i am " <<typeid(unknown).name() << endl;
}
else
{
cout << "i was something else" << endl;
}
return 0;
}

#include <iostream>
using namespace std;
class shape
{
public:
virtual	void S1()
{
	cout << "S1 called shape" << endl;
}	void S2()
{
	cout << "S2 called " << endl;
}
};

class square: public shape
{
public:
	void S1()
{
	cout << "S1 called square" << endl;
}

		void SQ3()
{
	cout << "SQ3 called " << endl;
}		void SQ4()
{
	cout << "SQ4 called " << endl;
}
};
void show(shape S)
{
cout << "taken " << typeid(S).name() << endl;
}
class circle: public shape{};
int main()
{
shape *S = new square;
S->S1() ;
return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex()=default;
	complex(int a , int b):real(a), imag(b)
{
}
	friend ostream & operator << (ostream &o, complex &obj);
};
ostream & operator << (ostream &o, complex &obj)
{
	cout << obj.real << " +i" << obj.imag << endl;
	return o;
}
int main()
{
complex NUM_1={1,2};
cout << NUM_1;
return 0;
}

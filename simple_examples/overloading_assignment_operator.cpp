#include <iostream>
#include <stdio.h>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex()=default;
	complex(int a, int b): real(a), imag(b)
{}
	void show()
{
	cout << real << " +i" << imag << endl;
}
	complex & operator = (complex &obj)
{
	this->real = obj.real;
	this->imag = obj.imag;
	return *this;
}
};
int main()
{
complex num_1(2,3),num_2,num_3;
num_2=num_3=num_1;
num_1.show();
num_2.show();
num_3.show();
return 0;
}

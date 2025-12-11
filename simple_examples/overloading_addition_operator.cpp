#include <iostream>
#include <stdio.h>
using namespace std;
class complex
{
private:
	int real,imag;
public:
	complex()=default;
	complex(int a, int b): real(a), imag(b)
{}
	void show()
{
	cout << real << " +i" << imag << endl;
}
	complex operator + (complex &obj)
{
	complex temp_obj;
	temp_obj.real = this->real + obj.real;
	temp_obj.imag = this->imag + obj.imag;
	return temp_obj;
}
};
int main()
{
complex num_1(2,3);
complex num_2(3,2);
complex num_3 = num_1+num_2;
num_3.show();

return 0;
}

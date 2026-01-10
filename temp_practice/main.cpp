#include <iostream>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex()=default;
	void make_number(int a, int b)
{
	this->real= a;
	this->imag = b;
}
	friend void show_number(complex &number);
	complex operator + (complex &obj)
{
	complex temp;
	temp.real = this->real + obj.real;
	temp.imag = this->imag + obj.imag;
	return temp;
}
};
void show_number(complex &number)
{
	cout << number.real << " +i" << number.imag << endl;
}
int main()
{
complex num_1,num_2;
num_1.make_number(2,3);
num_2.make_number(3,2);
complex num_3;
num_3 = num_1+num_2;
show_number(num_3);


return 0;
}

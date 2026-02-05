#include <iostream>
using namespace std;
class complex_numbers
{
int real, imag;
public:
	complex_numbers() = default;
	complex_numbers(int real, int imag): real(real), imag(imag)
{
	cout << this->real << " +i" << imag << endl;
}
	complex_numbers operator + (complex_numbers &obj)
{
	complex_numbers temp;
	temp.real = this->real+ obj.real;
	temp.imag = this->imag + obj.imag;
	cout << temp.real << " +i" << temp.imag << endl;
	return temp;
}	
	friend istream & operator >> (istream &i, complex_numbers &obj);
};
istream & operator >> (istream &i, complex_numbers &obj)
{
	cout << "enter real part" << endl;
	i >> obj.real;
	cout << "enter imag part" << endl;
	i>> obj.imag;
	cout << obj.real << " +i" << obj.imag << endl;
	return i;
}

int main()
{
complex_numbers N1(2,3) ,N2(3,2);
complex_numbers N3 = N1+N2;
complex_numbers N4;
cin >> N4;

return 0;
}

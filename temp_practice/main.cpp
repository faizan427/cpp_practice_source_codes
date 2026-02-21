#include <iostream>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex() = default;
	complex(int real, int imag): real(real), imag(imag){}
	complex  operator + (complex &obj)
{
	complex temp;
	temp.real = this->real + obj.real;
	temp.imag = this->imag + obj.imag;
	return temp;
}

friend istream & operator >> (istream &i, complex &obj);

friend void show(complex &num);


};
istream & operator >> (istream &i, complex &obj)
{
	cout << "enter real part " << endl;
	cin >> obj.real;
	cout << "enter imag part " << endl;
	cin >> obj.imag;

	return i;
}

void show(complex &num)
{
cout << num.real << " +i" << num.imag << endl;
}
int main()
{
complex num1(2,3);
complex num2(3,2);
complex num3 = num1+num2;
show(num3);
complex num4;
cin>> num4;
show(num4);

return 0;
}

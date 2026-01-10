#include <iostream>
using namespace std;
class complex 
{
private:
	int real,imag;
public:
	complex() =default;
	complex(int a , int b)
{
	this->real = a;
	this->imag = b;
}
	void show()
{
	cout << this->real << " +i" << this ->imag << endl;
}
	complex(complex &&num) noexcept
{
	cout << "move called\n";
	this->real =num.real;
	this->imag = num.imag;
	num.real =0;
	num.imag =0;
	
}


};
int main()
{
complex num_1(3,2);
num_1.show();

complex num_2(std::move(num_1));

num_2.show();
num_1.show();


return 0;
}

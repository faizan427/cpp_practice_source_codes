#include <iostream>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex()= default;
	void make(int a , int b)
{
	this->real = a;
	this->imag = b;

}
	friend void show(complex const &num);
	complex(complex &num)
{
	cout << "copy constr\n";
	this->real = num.real;
	this->imag =num.imag;
}
};
void show(complex const &num)
{
	cout << num.real<< " +i" << num.imag << endl;
}
int main()
{
complex num_1;
num_1.make(2,3);
complex num_2(num_1);
show(num_2);

return 0;
}

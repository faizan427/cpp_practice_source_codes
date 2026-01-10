#include <iostream>
using namespace std;
class complex 
{
private:
	  int real;
	   int imag;
public:
	complex()=default;
	friend istream & operator>> (istream &i, complex &num);
	friend void show(complex &num);
};

istream & operator>> (istream &i, complex &number)
{
	cout << "Enter real part\n";
	i >> number.real;
	cout << "Enter imaginery part\n";
	i >> number.imag;
	cout << "Complex number is generated\n";
	return i;
}
void show(complex &num)
{
	cout << num.real << " +i" << num.imag << endl;
}
int main()
{
complex num_1;
cin >> num_1;
show(num_1);

return 0;
}

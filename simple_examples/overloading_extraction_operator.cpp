#include <iostream>
#include <stdio.h>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex()=default;
	friend istream & operator >> (istream &i, complex &obj);
	friend void show(complex &obj);
};
istream & operator >> (istream &i, complex &obj)
{
	cout << "Enter real and imaginery parts \n";
	cin >> obj.real;
	cin >>  obj.imag;
	return i;
}
void show(complex &obj)
{
cout << obj.real << " +i" << obj.imag << endl;
}
int main()
{
complex NUM_1;
cin >> NUM_1;
show(NUM_1);
return 0;
}

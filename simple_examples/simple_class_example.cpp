#include <iostream>
#include <stdio.h>
using namespace std;
class complex
{
private:
	int real, imag;
public:
	complex()=default;
	complex(int a, int b):real(a), imag(b)
{}
	void show()
{
	cout << this->real << " +i" << this->imag << endl; 
}

	~complex()=default;
};

int main()
{
complex num_1(3,2);
num_1.show();

return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
class complex
{
private:
	T real, imag;
public:
	complex()=default;
	complex(T a, T b):real(a), imag(b)
{
}
	void show()
{
	cout << this->real << " +i" << this->imag << endl;
}
};
int main()
{
complex<float> num_1(1.2,3.5);
num_1.show();

return 0;
}

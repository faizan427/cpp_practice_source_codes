#include <iostream>
using namespace std;
class complex 
{
private:
	int a , b;
public:
	complex() = default;
	complex (int a, int b):a(a), b(b)
{}
	complex & operator = (complex &obj)
{
	this->a = obj.a;
	this->b = obj.b;
	return *this;
}
friend void show(complex &obj);
};
void show(complex &obj)
{
	cout << obj.a << " +i" << obj.b << endl;
}
int main()
{
complex num_1(2,3);
complex num_2, num_3;
num_2 = num_3 = num_1;
show(num_2);
show(num_3);

return 0;
}

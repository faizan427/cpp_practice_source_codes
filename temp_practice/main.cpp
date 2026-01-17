#include <iostream>
using namespace std;
class complex 
{
private:
	int a, b;
public:	
	complex() =default;
	complex(int a, int b):a(a), b(b)
{

}
	complex operator + (complex &obj)
{
	complex temp;
	temp.a = this->a+obj.a;
	temp.b = this->b+obj.b;
	return temp;
}
friend void show(complex &obj);


};
void show(complex &obj)
{
	cout << obj.a << " +i" << obj.b << endl;
}
int main()
{
complex num_1(2,3), num_2(3,2);
complex num_3;
num_3 = num_1+num_2;
show(num_3);

return 0;
}

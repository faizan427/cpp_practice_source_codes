#include <iostream>
using namespace std;
class calculator
{
private:
	int a, b;
public:
	calculator() = default;
int	mutator_add(int a, int b)
{
	this->a = a;
	this->b = b;
	return a+b;
}	
	~calculator() = default;	
};
class printer
{
private:
	int val;
public:
	printer() = default;
void	accessor_print(int val)
{
	this->val = val;
	cout << "PRINTED VALUE = " << this->val << endl;
}
	~printer() = default;
};
int main()
{
calculator CAL;
int val = CAL.mutator_add(2,3);
printer PRINTER;
PRINTER.accessor_print(val);
return 0;
}

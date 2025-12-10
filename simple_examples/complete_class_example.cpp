#include <iostream>
#include <stdio.h>
using namespace std;
// --------------------- All property functions written below ------------------------------//
class complex
{
private:
	int real,imag;
public:
	complex()=default; //Default constructor
	void read_accessor() // Accessor functions of a class which read the private variables.
{
	cout << this->real << " +i" << this->imag << endl;
}
	void write_mutator(int a , int b) // Mutator functions of a class which write the private variables
{
	this->real = a;
	this->imag = b;
}
	void operate_facilitator(int x = 2) // Facilitator functions of a class which operate upon the private variables.
{
	this->real = this->real*x;
	this->imag*=x;
}
	bool is_imag_part_non_zero_enquiry() // Enquiry functions of a class which operate upon private variable return boolean.
{
	return this->imag!=0?true:false;
}
};
int main()
{
complex num_1;
num_1.write_mutator(2,3);
num_1.read_accessor();
num_1.operate_facilitator();
num_1.read_accessor();
cout << boolalpha << num_1.is_imag_part_non_zero_enquiry()<< endl;
return 0;
}

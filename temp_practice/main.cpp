#include <iostream>
using namespace std;
class my_string
{
private:
	char *ptr;
	int length;
public:
	my_string(char *input)
{
	this->ptr = input;
	length = std::strlen(input);
	ptr = new char[length +1];
	std::strcpy(this->ptr, input);
} 
	void display()
{
	cout << ptr << endl;
}
	char  operator[](int index)
{
	return ptr[index];
}
};
int main()
{
char *c = {"Hello"};
my_string str(c);

cout << str[1];
str.display();
return 0;
}

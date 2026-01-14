#include <iostream>
using namespace std;
class demo
{
public:
	int var;
	demo()=default;
	demo(int var):var(var){} 
	bool operator > (int val)
{
	if(this->var > val)
{
	return true;
}
	else
{
	return false;
} 
}
};
int main()
{
demo a(1), b(2);
cout << boolalpha <<(a>2);

return 0;
}

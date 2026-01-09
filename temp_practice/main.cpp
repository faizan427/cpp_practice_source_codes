#include <iostream>
#include <memory>
using namespace std;
class demo
{
public:	
	demo()
{
	cout << "demo object created\n";
}
	~demo()
{
	cout << "destroyed\n";
}
};
int main()
{
demo *d = new demo();
cout << d << endl;

unique_ptr<demo> D(std::move(d));
	cout << d << endl;

return 0;
}

#include <iostream>
#include <mutex>
using namespace std;
class singelton
{
private:
	static singelton *ptr;
	singelton()
{
	cout << "invoked" << endl;
}
public:
	static singelton * create_instance();

};

singelton * singelton::ptr = nullptr;
singelton * singelton::create_instance()
{
	if(ptr == nullptr)
{
	ptr = new singelton();
}
	return ptr;
}
int main()
{
singelton *one = singelton::create_instance();
singelton *two = singelton::create_instance();
mutex mtx;


return 0;
}

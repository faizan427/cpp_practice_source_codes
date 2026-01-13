#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class singelton
{
private:
	static singelton *ptr;
	static mutex m;
	singelton() 
{
	cout << "invoked\n";
}
public:
	static singelton * create_instance();


};
mutex singelton::m;
singelton * singelton::ptr = nullptr;
singelton * singelton::create_instance()
{
	m.lock();
	if(ptr == nullptr)
{
	ptr = new singelton;
}
	m.unlock();
	return ptr;
}

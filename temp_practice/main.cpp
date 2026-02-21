#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class singelton
{
private:
static	singelton *ptr ;
static mutex mtx;
	singelton()
{
	cout << "instance created" << endl;
} 
public:
static singelton * create_instance();
singelton(singelton &obj) = delete;
singelton(singelton &&obj) noexcept = delete;
singelton operator = (singelton &obj) = delete;
};
singelton * singelton::ptr = nullptr;
mutex singelton::mtx;
singelton *singelton::create_instance()
{
	lock_guard<mutex> my_lock(mtx);	
	if(ptr == nullptr)
{
	ptr = new singelton;
}
	return ptr;
}
int main()
{
auto func_1 = [=](){singelton *ins_1 =  singelton::create_instance();};
auto func_2 = [=](){singelton *ins_2 =  singelton::create_instance();};
thread t1(func_1);
thread t2(func_2);
t1.join();
t2.join();

return 0;
}

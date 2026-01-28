#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class singelton
{
private:
	static mutex mtx;
	static singelton *ptr;
	singelton()
{
	cout << "instance is created " << endl;
} 
public:
	static singelton * create_instance();
	singelton(singelton &obj)
{
	cout << "copy called" << endl;
}
	singelton & operator = (singelton &obj)
{
	cout << "copy assingment called" << endl;
	return *this;
} 
	singelton & operator = (singelton &&obj) noexcept
{
	cout << "move assignemtn called" <<endl;
		return *this;

}
	singelton(singelton &&obj) noexcept
{

	cout << "move assignemnet called" << endl;
}
};

singelton * singelton::ptr = nullptr;
mutex singelton::mtx;
singelton * singelton::create_instance()
{
	lock_guard<mutex> my_lock(mtx);
	if(ptr == nullptr)
{
	ptr = new singelton;
}
	return ptr;
}
void func_1()
{
singelton * one_instance = singelton::create_instance();

}
void func_2()
{
singelton * two_instance = singelton::create_instance();

}
int main()
{
thread t1(func_1);
thread t2(func_2);
t1.join();
t2.join();
return 0;
}

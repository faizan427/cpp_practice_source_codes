#include "integrate.hpp"
void run_1()
{
singelton * ptr = singelton::create_instance();
	
}
void run_2()
{
singelton * ptr_1 = singelton::create_instance();

}
int main()
{
thread t1(run_1);
thread t2(run_2);
t1.join();
t2.join();
return 0;
}

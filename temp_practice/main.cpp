#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
int amount =0;
void add_money()
{
	m.lock();
	
	amount++;
	
	m.unlock();
}

int main()
{
thread t1(add_money);
thread t2(add_money);
t1.join();
t2.join();

return 0;
}

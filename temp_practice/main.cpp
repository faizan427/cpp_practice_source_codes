#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
int amount =0;
void add_money()
{
for(int i =1; i <=8 ; i++)
	{
	m.try_lock();
	cout << std::this_thread::get_id() << endl;	
	amount++;
	
	m.unlock();
}
}

int main()
{
thread t1(add_money);
thread t2(add_money);
t1.join();
t2.join();

return 0;
}

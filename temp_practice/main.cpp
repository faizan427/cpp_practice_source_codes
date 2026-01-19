#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
condition_variable cv;
mutex mtx;
bool t1_turn = true;
void add_money(int id)
{
for(int i =0; i < 3; i++)
{
	unique_lock<mutex>lock(mtx);
	cv.wait(lock,[id]{return (id ==1)? t1_turn:!t1_turn;});
	cout << "Thread t " << id  << "increamented amount " << endl;
	t1_turn = !t1_turn;
	cv.notify_one();
}
}
int main()
{
thread t1(add_money, 1);
thread t2(add_money, 2);
t1.join();
t2.join();


return 0;
}

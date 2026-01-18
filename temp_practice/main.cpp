#include <iostream>
using namespace std;
#include <thread>
#include <chrono>
using namespace chrono;
#include <unistd.h>
volatile bool val = true;
void set_val()
{
	sleep(10);
	val = false;
}
void run()
{
	while(val)
{
	cout << "run " << boolalpha  <<val << endl;
}
}
int main()
{
thread t1(run);
thread t2(set_val);
t1.join();
t2.join();
return 0;
}

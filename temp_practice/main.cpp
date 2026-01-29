#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
volatile bool val = true;
void stop()
{
	val = false;
}
void run()
{
	while(val)
{
cout << "waiting" << endl;
}

}
int main()
{
thread t1(run);
sleep(5);
thread t2(stop);
t1.join();
t2.join();

return 0;
}

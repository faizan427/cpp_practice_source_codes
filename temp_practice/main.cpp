#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;
typedef long long int llm;
llm limit =1900000000;
void even_sum(llm &e_sum)
{
	for (llm i =0; i <=limit; i++)
{
	if(i%2 ==0)
{
	e_sum+=i;
}
}
}
void odd_sum(llm &o_sum)
{
	for(llm i =0; i <=limit; i++)
{
	if(i%2 != 0)
{
	o_sum+=i;
}
}
}
int main()
{
llm e_sum =0;
llm o_sum =0;
auto start = high_resolution_clock::now();
thread t1(even_sum, std::ref(e_sum));
thread t2(odd_sum, std::ref(o_sum));
t1.join();
t2.join();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<seconds>(stop-start);

cout << "e_sum " << e_sum << "  " <<" o_sum " <<o_sum << endl;  
cout << "time taken " << duration.count() << endl;
return 0;
}

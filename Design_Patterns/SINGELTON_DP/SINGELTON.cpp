#include "integrate.hpp"
void func_1()
{
	SINGELTON *ptr_1 = SINGELTON::create_instance(); 	
	cout << "func_1() "<<ptr_1 << endl;
}
void func_2()
{
	SINGELTON *ptr_2 = SINGELTON::create_instance(); 
	cout << "func_2() " << ptr_2 << endl;
}
int main()
{
	thread t1(func_1);
	thread t2(func_2);
	t1.join();
	t2.join();
return 0;
}


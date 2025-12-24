#include <iostream>
using namespace std;
class workable
{
public:
	virtual void do_work() = 0;
};
class manageable
{
public:
	virtual void do_manage() = 0;
};
class worker: public workable
{
public:
	void do_work() override
{
	cout << "Worker is working" << endl;
}
};
class manager: public manageable, public workable
{
public:
	void do_work() override 
{
	cout << "Manager is working" << endl;
}
	void do_manage() override
{
	cout << "Manager is managing" << endl;
}
};
int main()
{


return 0;
}

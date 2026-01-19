#include <iostream>
using namespace std;
class worker
{
public:
	virtual void work()=0;
	virtual void manage()=0;
};
class regular_worker : public worker
{
public:
	void worker () override
{
	cout << "regular is working" << endl;
}
	void manage() override
{
	cout << "regular worker is managing" << endl;
}
};
class manager: public worker
{
public:
	void worker() override
{
	cout << "manager is working" << endl;
}
	void manage () override
{
	cout << "manager is "
}
};
int main()
{


return 0;
}

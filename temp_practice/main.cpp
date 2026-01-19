#include <iostream>
using namespace std;
class subject
{
public:
	virtual add_observer(observer *obs)=0;
	virtual notify_observer() =0;
};
class switch: public subject
{
public:
	observer *obs;
	void add_observer(observer *obs):obs(obs)
{
	
}
	void notify_observer()
{
	
	this->obs->update();
}
	void press_button(bool status)
{
	obs->status = status;
	notify_observer();
}
};
int main()
{


return 0;
}


#include <iostream>
using namespace std;
class observer
{
public:
	bool status = false;
	virtual void update() =0;
};
class observer_1: public observer
{
public:
	void update() override
{
	cout << "Status = " << status << endl;
}
};
class subject
{
public:
	observer * obser;
	virtual void add_observer(observer *obs)=0;
	virtual void notify_observer() =0;

};
class button: public subject
{
public:
	void add_observer(observer *obs) override
{
	obser= obs;
}
	void press_button(bool status) 
{
	obser->status = status;
	cout << "button pressed " << endl;
}
	void notify_observer() override
{
	obser->update();
}
};
int main()
{

return 0;
}

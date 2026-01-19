#include <iostream>
using namespace std;

class observer
{
public:
	bool status = false;
	virtual void update()=0;
};
class light:public observer
{
public:
	void update()
{
	cout << "light has been turned  " << status << endl;
}
};
class subject
{
public:
	virtual void add_observer(observer *obs)=0;
	virtual void notify_observer() =0;
	virtual void press_button(bool status)=0;

};
class switch_: public subject
{
public:
	observer *obs;
	void add_observer(observer *obs)
{
	this->obs = obs;	
}
	void notify_observer()
{
	
	obs->update();
}
	void press_button(bool status)
{
	cout << "swicth has been pressed" << endl;
	obs->status = status;
	notify_observer();
}
};
int main()
{
subject *corner_switch = new switch_();
observer *corner_light = new light;
corner_switch->add_observer(corner_light);
corner_switch->press_button(bool(true));
corner_light->update();


return 0;
}


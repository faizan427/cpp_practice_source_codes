#include <iostream>
using namespace std;
class observer;
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
	cout << "swicth has been pressed" << endl;
	obs->status = status;
	notify_observer();
}
};
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
int main()
{
subject *corner_switch = new switch();
observer *corner_light = new light;
corner_switch->add_observer(corner_light);
corner_switch->press_button(bool(true));
corner_light->update();


return 0;
}


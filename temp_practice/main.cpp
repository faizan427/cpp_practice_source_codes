#include <iostream>
using namespace std;
class observer
{
public:	
	bool status = false;
	virtual void update()=0;
};
class light: public observer
{
public:
	void update() 
{
cout << "Appliance is set to  " << boolalpha << status << endl;
}
};
class subject 
{
public:
	observer *obs;
	virtual void notify()=0;
	virtual void add_observer(observer *obse)=0;
	virtual void turn_on(bool status) =0;
};
class button: public subject 
{
public:
	void add_observer(observer *obse)
{
	obs = obse;
}
	void turn_on(bool status)
{
	obs->status = status;
}
	void notify()
{
	obs->update();
}
};

int main()
{
observer *corner_light = new light;
subject *corner_button = new button;
corner_button->add_observer(corner_light);
corner_button->turn_on(false);
corner_light->update();
return 0;
}

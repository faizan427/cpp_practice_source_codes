#include <iostream>
using namespace std;
class observer
{
public:
	char status[100] = "OFF" ;
	virtual void update() =0;
};
class lamp:public observer
{
	public:
	void update() override
{
	cout << "lamp is turned " <<  status << endl;
}
};
class subject
{
public:
	observer *obsr;
	virtual void add_observer(observer *obs) =0;
	virtual void notify() =0;
	virtual void operate (char ary[100]) = 0;
};
class button: public subject
{
	char arr[100] = "\0";
	public:
	void add_observer(observer *obs) override
{
	obsr = obs;

}
	void notify() override 
{
	obsr->update();

}
	void operate(char ary[100]) override
{
	strcpy(obsr->status,ary);

}
};
int main()
{
observer *corner_light = new light;
subject *corner_button = new button;
corner_button->add_observer(corner_light);
corner_button->operate("ON");
corner_button->notify();

return 0;
}

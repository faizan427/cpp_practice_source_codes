#include <iostream>
using namespace std;

class device
{
public:
virtual	void on()
{
	cout << "DEVICE is turned ON" << endl;
}
};

class tv: public device
{
public:
	void on()
{
	cout << "TV is turned ON" << endl;
}

};

class controller
{
public:
	void turn_on(device *generic_device)
{
	generic_device->on();
}

};

int main()
{

controller *my_controller = new controller;
my_controller->turn_on(new device);
my_controller->turn_on(new tv);

return 0;
}

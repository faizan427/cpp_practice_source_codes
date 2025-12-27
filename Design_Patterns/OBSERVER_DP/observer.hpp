#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>
using namespace std;
class observer
{
public:
	bool status = false;
	virtual void update() = 0; 
};
class lamp: public observer
{
public:
	void update() override
{
	if(status == 1)
{
	cout << "OBSERVER: Lamp is turned ON"  << endl;
}
	else
{
	cout << "OBSERVER: Lamp is turned OFF"  << endl;
	
}
}
};
#endif

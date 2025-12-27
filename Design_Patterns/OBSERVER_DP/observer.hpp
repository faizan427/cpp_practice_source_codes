#include <iostream>
using namespace std;
class observer
{
public:
	bool status = false;
	virual void update(bool status) = 0; 
};
class lamp: public observer
{
public:
	void update() override
{
	cout << "OBSERVER: Lamp is turned " << status << endl;
}
};

#include <iostream>
using namespace std;
class observer
{
public:
	virual void update(bool status) = 0; 
};
class lamp: public observer
{
public:
	void update(bool status) override
{
	cout << "OBSERVERLamp is turned " << status << endl;
}
};

#include <iostream>
using namespace std;
class observer
{
public:
	virual void update() = 0; 
};
class lamp: public observer
{
public:
	void update() override
{
	cout << "OBSERVERLamp is turned ON" << endl;
}
};

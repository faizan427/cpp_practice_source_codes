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
class subject{};
class button: public subject{};
int main()
{


return 0;
}

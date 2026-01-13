#include <iostream>
using namespace std;
class toy
{
public:
	virtual void play() =0;
};
class car: public toy
{
public:
	void play()override
{
	cout << "play with car" << endl;
}
};
class doll: public toy
{
public:
	void play() override
{
	cout << "play with doll"  << endl;
}
};
class factory
{
public:
	virtual toy * make_toy() =0;
};
class car_factory: public factory
{
public:
	toy * make_toy() override
{
	cout << "car ready" << endl;
	return new car();
}
};
class doll_factory:public factory
{
public:
	toy * make_toy() override 
{
	cout << "doll ready " << endl;
	return new doll;
}
};
int main()
{
factory *audi_factory = new car_factory;
toy *audi_car = new car;
audi_car = audi_factory->make_toy();
audi_car->play(); 

return 0;
}

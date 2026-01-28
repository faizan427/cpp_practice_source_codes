#include <iostream>
using namespace std;
class toy
{
public:
	virtual void play()=0;
};
class car: public toy
{
public:
	void play() override
{
	cout << " play with car" << endl;
}	
};
class doll: public toy
{
public:
	void play() override
{
	cout << "play with doll" << endl;
}
};
class toy_factory
{
public:
	virtual toy *  create_toy() =0;
};
class car_factory: public toy_factory
{
public:
	toy * create_toy() override
{
	cout << "car created" << endl;
	return new car;
}
};
class doll_factory: public toy_factory
{
public:
	toy * create_toy() override
{
	cout << "doll is created" << endl;
	return new doll;
}
};


int main()
{
toy_factory *audi_factory = new car_factory();
toy *audi = audi_factory->create_toy();
audi->play();
return 0;
}

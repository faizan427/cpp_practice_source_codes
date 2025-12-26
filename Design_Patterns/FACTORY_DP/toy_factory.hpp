#ifndef TOY_FACTORY_HPP
#define TOY_FACTORY_HPP
#include "toy.hpp"
class toy_factory
{
public:
	toy_factory()
{
	cout << "Order for a TOY is received" << endl;
}
	virtual toy * make_toy() = 0;
};
class car_factory: public toy_factory
{
public:
	car_factory()
{
	cout << "CAR is under preparation" << endl;
}
	toy * make_toy() override
{
	cout << "CAR is ready" << endl;
}
};
class doll_factory: public toy_factory
{
public:
	doll_factory()
{
	cout << "DOLL is under preparation" << endl;
}
	toy * make_toy() override
{
	cout << "DOLL is ready" << endl;
}
};
#endif

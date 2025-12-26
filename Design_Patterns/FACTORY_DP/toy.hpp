#ifndef TOY_HPP
#define TOY_HPP
#include <iostream>
using namespace std;
class toy
{
public:
	toy()=default;
	virtual void play() =0;
};
class car: public toy
{
public:
	car() = default;
	void play() override
{
	cout << "Play with CAR" << endl;
}
};
class doll: public toy
{
public:	
	doll() = default;
	void play() override
{
	cout << "Play with DOLL" << endl;
}
};
#endif

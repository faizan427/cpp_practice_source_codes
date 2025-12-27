#include "observer.hpp"
class subject
{
public:
	virtual void add_observer(observer &obser) = 0;
	virtual void notify_observer() = 0;

};

class switch : public subject
{
public:
	observer *obs;
	bool status = false;
	void add_observer(observer *obser) override
{
	obs = obser;
}
	void notify_observer() override
{
	obs->status = this->status;
	obs->update();
}
	void press_button(bool status)
{
	this->status = status;
	cout << "SUBJECT: Button is pressed\n" << endl;
	notify_observer();
}
};

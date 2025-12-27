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
	void add_observer(observer *obser) override
{
	obs = obser;
}
	void notify_observer() override
{
	obs->update();
}
	void press_button
{
	cout << "SUBJECT: Button is pressed\n" << endl;
	notify_observer();
}
};

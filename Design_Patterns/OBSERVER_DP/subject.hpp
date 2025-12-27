#include "observer.hpp"
class subject
{
public:
	virtual void add_observer(observer &obs) = 0;
	virtual void notify_observer() = 0;

};

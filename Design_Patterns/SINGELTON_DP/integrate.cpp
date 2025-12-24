#include "integrate.hpp"
SINGELTON * SINGELTON::ptr = nullptr;
mutex SINGELTON::mtx;
SINGELTON::SINGELTON()
{
	cout << "SINGELTON instance invoked" << endl;
}
SINGELTON * SINGELTON::create_instance()
{
	mtx.lock();
	if(ptr == nullptr)
{
	ptr = new SINGELTON;
}
	else 
{
	cout << "SINGELTON instance already created" << endl;
}
	mtx.unlock();
	return ptr;
}

#ifndef INTEGRATE_HPP
#define INTEGRATE_HPP
#include <mutex>
#include <iostream>
#include <thread>
using namespace std;
class SINGELTON
{
private:
	static SINGELTON *ptr;
	static mutex mtx;
	SINGELTON() = default;
public:
	static * SINGELTON create_instance();
	
};
#endif

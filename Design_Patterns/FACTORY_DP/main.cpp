#include "toy_factory.hpp"
int main()
{
toy_factory * car_makers = new car_factory();
toy * audi_car = car_makers->make_toy();
audi_car->play();

return 0;
}

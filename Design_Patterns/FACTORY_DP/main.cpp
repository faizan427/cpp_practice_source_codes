#include "toy_factory.hpp"
int main()
{
toy_factory * car_makers = new car_factory();
toy * audi_car = car_makers->make_toy();
audi_car->play();

toy_factory * doll_makers = new doll_factory();
toy * barbie_doll = doll_makers->make_toy();
barbie_doll->play();

return 0;
}

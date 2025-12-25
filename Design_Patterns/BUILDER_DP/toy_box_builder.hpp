#include "toy_box.hpp"
class toy_box_builder
{
public:
	toy_box * my_custom_box;
	toy_box_builder()
{
	my_custom_box = new toy_box;
}
	toy_box_builder * add_car(string car_name)
{
	my_custom_box->car = car_name;
	return this;
}
	toy_box_builder * add_doll(string doll_name)
{
	my_custom_box->doll = doll_name;
	return this;
}
	toy_box_builder * add_stickers(bool stickers)
{
	my_custom_box->stickers = stickers;
	return this;
}
	toy_box_builder * add_gift_wrap(bool gift_wrap)
{
	my_custom_box->gift_wrapped = gift_wrap;
	return this;
}
	toy_box * build()
{
	cout << "Toy Box Build complete" << endl;
	return my_custom_box;	
}
};

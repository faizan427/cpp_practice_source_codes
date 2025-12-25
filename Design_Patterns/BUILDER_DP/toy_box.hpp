#ifndef TOY_BOX_HPP
#define TOY_BOX_HPP
#include <iostream>
#include <string>
using namespace std;
class toy_box
{
private:
	string car = "";
	string doll = "";
	bool stickers = false;
	bool gift_wrapped = false;
	void show()
{
	cout << Toy Box contains << car << " car and " << doll << " doll " << endl;
	if(stickers)
{
	cout << "\n Toy Box has stickers included\n";
}
	if(gift_wrapped)
{
	cout << "\n Toy Box is gift wrapped as well\n";
}
}
};
#endif

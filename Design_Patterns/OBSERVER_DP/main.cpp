#include "subject.hpp"
int main()
{
lamp table_lamp;
room_switch table_lamp_switch;
table_lamp_switch.add_observer(&table_lamp);
bool status = false;
cout << "Press Switch 1 or 0" << endl;
cin >> status;
table_lamp_switch.press_button(status);
return 0;
}

#include "subject.hpp"
int main()
{
lamp table_lamp;
switch table_lamp_switch;
table_lamp_switch.add_observer(&table_lamp);
table_lamp_switch.press_button(true);
return 0;
}

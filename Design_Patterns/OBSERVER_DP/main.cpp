#include "subject.hpp"
int main()
{
lamp table_lamp;
switch table_lamp_switch;
switch.add_observer(&table_lamp);
switch.press_button(true);
return 0;
}

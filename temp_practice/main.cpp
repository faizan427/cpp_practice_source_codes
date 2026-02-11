#include <iostream>
using namespace std;
class base 
{
public:

//virtual void func(); 
};
class derived_1 : public base{};
class derived_2 : public base{};
 
int main()
{ 
base b;
derived_1 d;
b = d;

return 0;
}

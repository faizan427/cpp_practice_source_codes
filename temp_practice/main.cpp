#include <iostream>
using namespace std;
int main()
{
int b ;
const int &a =b;
auto z = *const_cast<int *>(&a);
z++;
return 0;
}

#include <iostream>
using namespace std;
int main()
{
int * const ptr = new int(3);
ptr = nullptr;
return 0;
}

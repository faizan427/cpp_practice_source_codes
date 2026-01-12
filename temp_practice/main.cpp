#include <iostream>
using namespace std;
int main()
{
typedef struct a{char i, v; int z;} my_struct;
cout <<  sizeof(a) << endl;
typedef struct b{char x; int k; char z;} my_struct_2;
cout << sizeof(b) << endl;
return 0;
}

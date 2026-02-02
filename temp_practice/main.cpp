#include <iostream>
using namespace std;
int main()
{

const int val =3;
int *val_2 = const_cast<int*>(&val);
cout << (*val_2)++ << endl;
return 0;
}

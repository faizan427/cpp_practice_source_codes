#include <iostream>
using namespace std;
int main()
{
const int var =3;

cout << var++ << endl; // The program throw a compile time error.
		      // A variable declared constant is getting modified. 			
return 0;
}

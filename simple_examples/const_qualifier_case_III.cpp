#include <iostream>
using namespace std;
int main()
{
int x=3;                //This is the case II of const_qualifier usage.
int const *ptr = &x;    //Here const keyword is placed at such a position wherein 
(*ptr)++;               //The meaning could be interpreted as:
return 0;               //The ptr (a pointer) value can be modified.
}                       //But the variable it is pointing to. Cannot be modified
                        //Means ptr = NULL is allowed.
                        //*(ptr)++ is never allowed

//      Also the declaration    //
// const int *ptr // and // int const *ptr //
// means the same that pointer can be modified but the value it is pointing to cannot. //

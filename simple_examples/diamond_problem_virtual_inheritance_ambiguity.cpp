#include <iostream>
#include <stdio.h>
using namespace std;
class A
{
public:
	int value =3;
};
class B: virtual public A{};
class C: virtual public A{};
class D: public B, public C{};
int main()
{
D d_object;
//----------------- THIS IS A CASE OF DIAMOND INHERITANCE PROBLEM---------------//
//------------------THERE IS PATH AMBIGUITY TO ACCESS A VARIABLE INHERITED FROM A UNIQUE SOURCE 'CLASS-A'-----------//
//------------------COMPILER GETS CONFUSED FROM WHICH PATH VARIABLE 'value' SHOULD BE ACCESSED---------------------//
//------------------AS THERE ARE APPARENTLY TWO COPIES OF VARIABLE 'value' COMMING FROM BOTH 'CLASS-B AND CLASS-C TO CLASS-D'------//

cout << d_object.C::value << endl; //-----PATH DEFINITION THROUGH CLASS INHERITANCE FROM 'CLASS-C'
cout << d_object.D::value << endl; //-----PATH DEFINITION THROUGH CLASS INHERITANCE FROM 'CLASS-D'

//----------------- IN ORDER TO RESOLVE THE AMBIGUITY----------------//
//----------------- ONE CAN DECLARE THE INHERITED CLASSES AS 'VIRTUAL'---------//
//----------------- AND WITHOUT SPECIFYING THE PATH. COMPILER CAN NEVER GET CONFUSED WHILE RESOLVING VARIABLE 'value'-----//

cout << d_object.value << endl;

return 0;
}

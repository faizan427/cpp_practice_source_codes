#include <iostream>
#include <stdio.h>
using namespace std;
class shallow_copy
{
private:
	int val,*ptr;
public:
	shallow_copy(int val): val(val)
{
	ptr = new int(val);
}
template <typename T>
friend void show(T &obj);
/*	~shallow_copy() // ENABLE THIS DESTRUCTOR and THEN ONE CAN REALISE THE REPERCUSSIONS OF SHALLOW COPYING.
{			// DUE TO THIS DESTRUCTOR THE DELETION OF A SAME MEMORY WILL HAPPEN TWICE
	delete ptr;	// SINCE A COPY OF 'S' IS CREATED AS 'C'. THEREFORE POINTER INSIDE C AND C SHARE SAME HEAP MEMORY ADDRESS. 
}			// ONCE THE DESTRUCTOR IS CALLED FOR 'S'. THE MEMORY IS FREED. 
*/			// THE MOMENT DESTRUCTOR OF 'C' IS CALLED. IT TRIES TO FREE THE MEMORY. HOWEVER THE MEMORY IS NO MORE THERE.
};			// DOUBLE DELETION OF A SAME HEAP MEMORY CAUSE PROGRAM TO CRASH
			// THIS IS THE NEGATIVE SIGNIFICANCE OF USING SHALLOW_COPY.
class deep_copy		
{
private:
	int val,*ptr;
public:
	deep_copy(int val):val(val)
{
	ptr = new int(this->val);
}
	deep_copy(deep_copy &obj)
{
	this->val = obj.val;
	this->ptr = new int(this->val);
}

template <typename T>
friend void show(T &obj);
	~deep_copy()       // EVEN AFTER DELETING THE MEMORY. DOUBLE DELETION WONT OCCUR
{			// AS NOW THE POINTER IS POINTING TO DIFFERENT MEMORY ADDRESSESS EVEN AFTER MAKING A COPY OF OBJECT
	delete ptr;	// PROGRAM WONT CRASH NOW
}
};
template <class T>
void show(T &obj)
{
	cout << "address stored = " << obj.ptr << " value = " << *(obj.ptr) << endl;
}
int main()
{
//------------------------ SHALLOW COPY SECTION -----------------------------------------------
shallow_copy S(2);
show<shallow_copy>(S);
shallow_copy C(S);
show<shallow_copy>(C);
//------------------------ SHALLOW COPY SECTION -----------------------------------------------

//------------------------ DEEP COPY SECTION -----------------------------------------------
deep_copy D(3);
show<deep_copy>(D);
deep_copy E(D);
show<deep_copy>(E);
//------------------------ DEEP COPY SECTION -----------------------------------------------

return 0;
}

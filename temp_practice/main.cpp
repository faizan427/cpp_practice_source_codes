#include <iostream>
using namespace std;
class shallow
{
private:
	int val;
	int *ptr;
public:
	shallow(int val): val(val)
{
	ptr = new int (val);
}
template <typename T>
friend void show(T &obj);
	~shallow()
{	delete ptr;
}
};
class deep
{
private:
	int val;
	int *ptr;
public:
	deep(int val):val(val)
{
	ptr = new int (val);
}
	deep(deep & obj)
{
	cout << "deep copy invoked\n";
	this->val = obj.val;
	this->ptr = new int (val);
} 
template <typename T>
friend void show(T &obj);

	~deep()
{
	delete ptr;
}
};
template <typename T>
void show( T &obj)
{
	cout << "ptr address = " <<obj.ptr << "  and value = "<<*(obj.ptr) << endl;
}
int main()
{
shallow one(5);
show<shallow>(one);
shallow two(one);
show<shallow>(two);
deep three (3);
show<deep>(three);
deep four(three);
show<deep>(four);
return 0;
}

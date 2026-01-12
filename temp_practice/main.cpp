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


return 0;
}

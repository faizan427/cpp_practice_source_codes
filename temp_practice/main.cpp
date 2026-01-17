#include <iostream>
using namespace std;
class demo
{
private:
	int *ptr ;
public:
	demo(int *ptr): ptr(ptr){}
	demo(demo &&obj) noexcept
{
	cout << "move called \n";
	this->ptr = obj.ptr;
	obj.ptr = nullptr;

}
friend void show(demo &obj);

};
void show(demo &obj)
{
cout << "obj.ptr =\t" << obj.ptr << "\t*obj.ptr =\t" << *(obj.ptr) << endl; 
}
int main()
{
demo D(new int(5));
show(D); 
demo E(std::move(D));
show(E);
show(D);
return 0;
}

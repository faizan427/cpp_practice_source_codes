#include <iostream>
using namespace std;
class demo
{
public:
	int *ptr;
	int val;
	demo()=default;
	~demo()=default;
	demo(demo &&obj) noexcept
{
	this->ptr = obj.ptr;
	this->val = obj.val;
	obj.ptr = nullptr;
	obj.val =0;
}
};

int main()
{
demo D;
int variable=10;
D.val = variable;
D.ptr = new int(D.val);
cout << "Object created is D and pointer address of ptr inside D = " << D.ptr << " and value to which ptr is pointer = " << *(D.ptr) << endl;
demo C(std::move(D)); 
cout << "Object created is C and data has been moved from D to C object. Now pointer address of ptr inside C = " << C.ptr << " and value to which ptr is pointer = " << *(C.ptr) << endl;
cout << "Still verifying if move is successful !. pointer address of ptr inside D = " << D.ptr << " and value to which ptr is pointer = " << *(D.ptr) << endl;

return 0;
}

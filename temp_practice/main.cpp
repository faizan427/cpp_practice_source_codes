#include <iostream>
using namespace std;
class demo
{
public:
	int val;
	int *ptr;
	demo(int val): val(val), ptr(new int(this->val)){}
	

};
int main()
{


return 0;
}

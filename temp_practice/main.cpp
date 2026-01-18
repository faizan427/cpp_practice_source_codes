#include <iostream>
using namespace std;
int main()
{
int *ptr = new int(5);
ptr = nullptr;
if(ptr !=nullptr && (*ptr)>0)
{
	cout << *ptr << endl;
}

return 0;
}

#include <iostream>
using namespace std;
namespace one 
{
void func()
{
	cout << "from one" << endl;
}
}
namespace two
{
void func()
{
	cout << "from two" << endl;
}

}

int main()
{
one::func();
two::func();

return 0;
}

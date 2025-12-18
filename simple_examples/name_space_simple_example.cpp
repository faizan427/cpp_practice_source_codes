#include<iostream>
using namespace std;
namespace one
{
void same_func()
{
	cout << "hello from same_func using namespace one" << endl;
}

}

namespace two
{
void same_func()
{
	cout << "hello from same_func using namespace two" << endl;
}
}
int main()
{
one::same_func();
two::same_func();
return 0;
}

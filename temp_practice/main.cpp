#include <iostream>
using namespace std;
class A
{
public:
	int var = 0;
};
class B: virtual public A{};
class C: virtual public A{};
class D:  public B,  public C{};
int main()
{
D obj;
cout << obj.C::var << endl;

return 0;
}

#include <iostream>
using namespace std;
class demo
{
public:
	int val;
explicit demo(int val):val(val)
{

}
	~demo()=default;
};
int main()
{
//demo D = 3; // NOT ALLOWED
demo D(3); // ALLOWED


return 0;
}

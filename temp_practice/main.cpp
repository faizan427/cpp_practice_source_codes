#include <iostream>
using namespace std;
class area
{
public:
	int val;
	area(int val): val(val)
{}
bool operator> (area &obj)
{
	return this->val > obj.val;
}
friend bool operator> (int val, area &obj);

};
bool operator> (int val, area &obj)
{
	return val > obj.val;
}
int main()
{
area A(1), B(2);
cout << "A(1)> B(2) " << boolalpha<<(A > B) << endl;
cout << "2 > A(1) " << boolalpha <<(2 > A) << endl;

return 0;
}

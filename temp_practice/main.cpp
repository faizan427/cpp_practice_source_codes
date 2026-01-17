#include <iostream>
using namespace std;
class ptr 
{
public:
	int *pt = nullptr;
	ptr() = default;
	ptr(int *pt):pt(pt)
{
	cout << "pt = " << pt <<endl;
}
};
int main()
{
ptr p = new int(5);
unique_ptr<int> p1(std::move(p.pt));
cout << p.pt << endl;

return 0;
}

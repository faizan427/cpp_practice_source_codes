#include <iostream>
using namespace std;
int main()
{
unique_ptr<int>ptr_1(new int(5));
cout << ptr_1 << "\t" << *(ptr_1) << endl;
unique_ptr<int>ptr_2;
ptr_2 = std::move(ptr_1); 
cout << ptr_2 << "\t" << *(ptr_2) << endl;

return 0;
}

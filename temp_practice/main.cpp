#include <iostream>
#include <memory>
using namespace std;
int main()
{
unique_ptr<int> ptr_1(make_unique<int>(3));
cout << "ptr_1 " << ptr_1 << endl;
unique_ptr<int> ptr_2(std::move(ptr_1));
cout << "ptr_1 " << ptr_1 << endl;
cout << "ptr_2 " << ptr_2 << endl;
shared_ptr<int> ptr_3(new int (4));
cout << "ptr_3 " << ptr_3 << endl;
cout << "ptr_3.use_count " << ptr_3.use_count() << endl;
weak_ptr<int> ptr_4 = ptr_3;

auto ptr_5 = ptr_4.lock();
cout << "ptr_5 " << ptr_5 << endl;
cout << "ptr_5.use_count() " << ptr_5.use_count() << endl;

return 0;
}

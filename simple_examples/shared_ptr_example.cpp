#include <iostream>
using namespace std;
int main()
{
shared_ptr<int>ptr_1(new int(5));
cout << " ptr_1 " << ptr_1 << "\t" << *(ptr_1) << endl;
shared_ptr<int>ptr_2;
ptr_2=ptr_1;
cout << " ptr_2 "  << ptr_2 << "\t" << *(ptr_2) << endl;
cout << "use_count ptr_1 " << ptr_1.use_count() << endl;
cout << "use_count ptr_2 " << ptr_2.use_count() << endl;
return 0;
}

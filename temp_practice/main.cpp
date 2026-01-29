#include <iostream>
using namespace std;
int main()
{
int *ptr = new int[5]();
ptr = nullptr;
if(ptr !=nullptr && *ptr == 5)
{
cout << "in " << endl;
}

}

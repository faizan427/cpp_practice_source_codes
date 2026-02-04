#include <iostream>
using namespace std;
void func(char *str)
{
cout << std::strlen(str) << endl;
}
int main()
{
char *arr[] = {"Hello"};
func(arr);

return 0;
}

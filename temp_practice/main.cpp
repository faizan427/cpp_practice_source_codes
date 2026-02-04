#include <iostream>
using namespace std;
void func(char *str)
{
cout << std::strlen(str) << endl;
int s = std::strlen(str);

int l = s-1;
cout << l << endl;

int f = 0;
char temp= '\0';
while(!(l<=f))
{
temp = str[f];
str[f] = str[l];
str[l] = temp;
f++;
l--;
}
}
int main()
{
char arr[100]= {"Hello"};
func(arr);
cout << arr << endl;
return 0;
}

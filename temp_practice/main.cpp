#include <iostream>
using namespace std;
int main()
{
int arr[] ={2,3,4,6,8,10,15,16,17};
int l =0;
int h = 9;
int key =3;
int mid =0;
while(arr[mid]!=key)
{
mid = (l+h)/2;
if(arr[mid]>key)
{
h = mid-1;
}
if(arr[mid]<key)
{
l = mid+1;
}
}
cout << "element found" << arr[mid] << endl;

return 0;
}

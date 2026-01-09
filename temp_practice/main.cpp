#include <iostream>
using namespace std;
int main()
{
int arr[10]={2,4,6,8,9,10,13,23,45,56};
int l =0;
int h = 9;
int key = 10;

int mid = 0;
while(l<=h)
{
mid = (l+h)/2;

if(arr[mid]>key)
{
	h = mid-1; 
}
if(arr[mid] < key)
{
	l = mid +1;
}
if (arr[mid] ==  key)
{

cout << "Number found at index = "<< mid<<"\n" ;
break;
}
else 
{
	cout << "Number not found\n";
	
}
}

return 0;
}

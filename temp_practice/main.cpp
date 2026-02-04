#include <iostream>
using namespace std;
int main()
{
int key = 9;
int arr[]{2,5,6,8,9,18,33,35};
int low = 0;
int high = ((sizeof(arr))/(sizeof(arr[0])));
cout << high << endl;
while(!(high <= low))
{
int mid = (low+high)/2;
if(arr[mid] > arr[low])
{
low = mid +1;
}

if(arr[mid] < arr[high])
{
high = mid-1;
}
if(arr[mid] == key)
{
cout << key << " found  at " << mid << endl; 
}
else
{
cout << "no such num" << endl;
}
}

return 0;
}

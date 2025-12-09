#include <iostream>
#include <stdio.h>
using namespace std;
bool binary_search(int *arr, int key, int no_o_ele)
{
bool status =false;
int low =0; 
int high =0; 
int mid = 0;
while(low<=high)
{
mid = (low+high)/2;
if(arr[mid] == key)
{
	status = true;
	break;
}
else if(arr[mid]>key)
{
	high = mid-1;
}
else if
(arr[mid]<key)
{
	low = mid+1;
}
}
return status;
}
int main()
{
int arr[] = {3, 5, 7, 8, 12, 14, 17, 19, 21, 24, 28, 33, 37};
int key=0;
int total_size = sizeof(arr);
int single_size = sizeof(arr[0]);
int no_o_ele = int(total_size/single_size);
cin >> key;
cout << "Found = " << boolalpha <<bool(binary_search(arr,key,no_o_ele)) << endl; 
return 0;

}

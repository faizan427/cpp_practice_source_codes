#include <iostream>
#include <stdio.h>
using namespace std;
bool linear_search(int *arr, int &val, int &no_o_ele )
{
	bool status=false;	
	for(int i =0; i<no_o_ele; i++)
{
	switch (arr[i]==val)
{
	case 1: status = true;
	goto END;
	
	default: status = false;
}
}
END:
return status;
}
int main()
{
int arr[]={12,3,5,64,6,7,8,23,4,9,8,32,100,10};
int total_size = sizeof(arr);
int single_size = sizeof(arr[0]);
int no_o_ele = total_size/single_size;
int val =0 ;
cin >> val;
cout << static_cast<bool>(linear_search(arr,val,no_o_ele))<< endl;


return 0;
}

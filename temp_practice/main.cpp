#include <iostream>
using namespace std;
int main()
{
string str = {"hello my name is Hell"};
cout << str.size() << endl;
int num_o_w_s =0;
for(int i =0; i < str.size(); i ++)
{
	if(str[i] == ' ')
{
	num_o_w_s = i;
}
}
cout << str.size() - num_o_w_s-1 << endl;
return 0;
}

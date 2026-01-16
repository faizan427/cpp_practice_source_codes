'#include <iostream>
#include <vector>
using namespace std;
int main()
{
vector<pair<int,double>>v= {{1,100},{2,106},{3,104},{4,96},{5,101},{6,94}};
int sum=0; 
for(int i=1; i <=3; i++)
{
sum+=v[i].second;
}
cout << sum/3 << endl;
return 0;
}

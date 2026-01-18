#include <iostream>
using namespace std;
class area
{
public:
	int a;
	area(int a):a(a)
{}
	bool operator > (area &obj)
{
	return this->a>obj.a;
}
	bool operator < (area &obj)
{
	return this->a<obj.a;
}
friend  	bool operator > (int val,area &obj);
friend 		bool operator < (int val,area &obj);


};
 	bool operator > (int val,area &obj)
{
	return val>obj.a;
}
 	bool operator < (int val,area &obj)
{
	return val< obj.a;
}
int main()
{
area a(2), b(3);
cout << "(a(2) > b(3)) "<< boolalpha <<(a > b) <<endl; 
cout << "(a(2) < b(3)) "<< boolalpha <<(a < b) <<endl; 
cout << "(4 < b(3)) "<< boolalpha <<(4 < b) <<endl;
cout << "(6 > b(3)) "<< boolalpha <<(6 > b) <<endl; 
 

return 0;
}

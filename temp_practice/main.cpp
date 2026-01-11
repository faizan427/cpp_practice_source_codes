#include <iostream>
using namespace std;
enum class numbers{one =1, two =2};
enum class colors{one =1, two=2};
int main()
{
colors C;
C= colors::two;
int x = (int)C;
cout << x << endl;


return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
string str("heLLo");
for(auto i: str)
{
if((int)i> 97-32 && i < 122-32  )
{cout << static_cast<char>(i+32) << " ";
}
else
{
cout << static_cast<char>(i-32) << " ";
}
}

return 0;
}

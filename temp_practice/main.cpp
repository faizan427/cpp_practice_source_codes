#include <iostream>
using namespace std;
class complex
{
private:
	int a,b;
public:
	complex() = default;
friend istream & operator >> (istream &i, complex &obj);
friend ostream & operator << (ostream &o, complex &obj);
};
istream & operator >> (istream &i, complex &obj)
{
	cout << "Enter numbers " << endl;
	i >> obj.a;
	i >> obj.b;
	return i;

}
ostream & operator << (ostream &o, complex &obj)
{
	o << obj.a << " +i" << obj.b << endl;
	return o;
}
int main()
{
complex num_1;
cin >> num_1;
cout << num_1;

return 0;
}

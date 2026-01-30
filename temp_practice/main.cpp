{
	ptr = new int(val);
}
	shallow_copy(shallow_copy &obj)
{
	cout << "shallow copy_const invoked" << endl;
}
	~shallow_copy()
{
	delete ptr;
}
};
class deep_copy
{
public:
	int *ptr;
	int val;
	deep_copy(int val ):val(val)
{
	ptr = new int(val);
}
	deep_copy(deep_copy &obj)
{
	cout << "deep_copy copy_const invoked" << endl;
	this->val = obj.val;
	this->ptr = new int(this->val);
}
	~deep_copy()
{
	delete ptr;
}
};
int main()
{
shallow_copy one(5);
shallow_copy two = one;
deep_copy three(3);
deep_copy four = three;
return 0;
}

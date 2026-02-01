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

#include <iostream>
using namespace std;
class model
{
public:
	int value =0;
	model()=default;
	void increament()
{
	this->value++;
}
	int get_value()
{
	return value;
}
};
class view
{
public:
	void display(int value)
{
	cout << "value " << value << endl;
}
};
class controller
{
public:
	model my_model; 
	view my_view;
	controller(model my_model, view my_view): my_model(my_model), my_view(my_view){}
	void on_increament()
{
	my_model.increament();
	my_view.display(my_model.get_value());
}

};
int main()
{

model my_model;
view my_view;
controller my_controller(my_model, my_view);
my_controller.on_increament();

return 0;
}

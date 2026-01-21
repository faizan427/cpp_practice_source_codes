	string str{};
	virtual void update()=0;
};
class light: public observer
{
	void update() override
{
	cout << "Turned " << str << endl;
}
};
class subject
{
public:
	observer *obser;
	virtual void notify()=0;
	virtual void operate_button(string str) =0;
	virtual void add_observer(observer *obs)=0;
};
class button: public subject
{
	void add_observer(observer *obs) override
{
	obser = obs;
}
	void operate_button(string str) override
{
	obser->str = str;
}
	void notify() override
{
	obser->update();
}
};

int main()
{
observer *corner_light = new light;
subject *corner_button = new button;
corner_button->add_observer(corner_light);
corner_button->operate_button("OFF");
corner_button->notify();

return 0;
}

class Context;

class State {
public:
	enum INPUT{ON=0,OFF=1,DESTROY=2};

	State(){context = 0;}
	State(Context* context){this->context = context;}

	virtual void on() = 0;
	virtual void off() = 0;
	virtual void destroy() = 0;
	virtual void status() = 0;
	virtual ~State(){};

	Context* context;
};

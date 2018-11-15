class stack
{
public:
	int push(int a);
	int pop();
	void clear();
	stack();
	~stack();
	void display();
private:
	int top;
	int *dane;
	int capacity;};


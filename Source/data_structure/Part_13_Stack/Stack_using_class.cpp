#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class Stack
{
private:
	Node* top;
public:
	Stack() :top{ nullptr } {};
	~Stack();
	void push(int val);
	int pop();
	int isEmpty();
	void display();
	int getTop();
	int peek(int posi);
};

void Stack::push(int val) {
	Node* t = new Node;
	if (t==nullptr)
	{
		cout << "Stack is overfolow" << endl;
	}
	t->data = val;
	t->next = top;
	t->prev = nullptr;
	if (top!=nullptr)
	{
		top->prev = t;
	}
	top = t;
}

int Stack::isEmpty() {
	return top == nullptr;
}

int Stack::getTop() {
	if (isEmpty())
	{
		return -1;
	}
	return top->data;
}

int Stack::pop() {
	if (isEmpty())
		return -1;
	
	Node* temp = top;
	int x = top->data;
	top = top->next;
	delete temp;
	return x;
}

void Stack::display() {
	Node* temp = top;
	while (temp!=nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int Stack::peek(int posi) {
	for (size_t i = 0; i < posi-1; i++)
	{
		top = top->next;
	}
	return top->data;
}

Stack::~Stack()
{
	Node* temp = nullptr;
	while (top!=nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

int main() {
	Stack st1;
	st1.push(10);
	st1.push(20);
	st1.push(30);
	st1.push(40);
	st1.push(50);
	st1.display();
	cout << st1.peek(1) << endl;
	cout << st1.pop() << endl;
	cout << st1.pop() << endl;
	st1.display();
	cout << st1.getTop() << endl;

	return 0;
}
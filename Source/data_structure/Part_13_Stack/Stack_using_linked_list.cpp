#include <iostream>
using namespace std;

//template <typename T>
struct Node
{
	int data;
	Node* next;
};

void push(Node**top, int val) {
	Node* t = new Node;
	if (t==nullptr)
	{
		cout << "Stack overflow" << endl;
	}
	else
	{
		t->data = val;
		t->next = *top;
		*top = t;
	}
}

void pop(Node** top) {
	Node* q = nullptr;
	Node* p = *top;
	if (*top==nullptr)
	{
		cout << "Stack is empty\n";
	}
	else
	{
		q = p;
		p = p->next;
		*top = p;
		delete q;
	}
}

void display(Node* top) {
	while (top!=nullptr)
	{
		cout << top->data << " ";
		top = top->next;
	}
	cout << endl;
}

int main() {
	Node* st = nullptr;
	push(&st, 5);
	push(&st, 6);
	push(&st, 7);
	push(&st, 8);
	push(&st, 9);
	display(st);
	pop(&st);
	pop(&st);
	display(st);
	return 0;
}
#include <iostream>
using namespace std;

struct Stack
{
	int size;
	int top;
	int* s;
};

void createStack(Stack** st) {
	(*st) = new Stack;
	cout << "Enter size of stack: ";
	cin >> (*st)->size;
	(*st)->s = new int[(*st)->size];
	(*st)->top = -1;
}

void push(Stack* st, int data) {
	if (st->top==(st->size)-1)
	{
		cout << "Stack is overflow" << endl;
		return;
	}
	st->top++;
	st->s[st->top] = data;
}

int pop(Stack* st) {
	if (st->top==-1)
	{
	cout << "Stack is underflow";
	return -1;
	}
	int x = st->s[st->top];
	st->top--;
	return x;
}

void display(Stack* st) {
	for (int i = st->top; i >=0; i--)
	{
		cout << st->s[i] << " ";
	}
	cout << endl;
}

int main() {
	Stack* st1 = nullptr;
	createStack(&st1);
	push(st1, 10);
	push(st1, 11);
	push(st1, 12);
	display(st1);
	return 0;
}
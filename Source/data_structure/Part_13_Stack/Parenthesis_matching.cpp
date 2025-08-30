#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

struct Node
{
	char data;
	Node* next;
	Node* prev;
};

void push(Node** top, char val) {
	Node* t = new Node;
	if (t == nullptr)
	{
		cout << "Stack overflow" << endl;
	}
	else
	{
		t->data = val;
		t->next = *top;
		t->prev = nullptr;
		if (*top != nullptr)
		{
			(*top)->prev = t;
		}
		*top = t;
	}
}

int pop(Node** top) {
	Node* q = nullptr;
	Node* p = *top;
	if (*top == nullptr)
	{
		cout << "Stack is empty\n";
	}
	else
	{
		q = p;
		int x = p->data;
		p = p->next;
		*top = p;
		delete q;
		return x;
	}
}

int isEmpty(Node* top) {
	return top == nullptr;
}

int isFull(Node* top) {
	Node* temp = new Node;
	if (temp==nullptr)
	{
		return 1;
	}
	delete temp;
	return 0;
}

int checkTop(Node* top) {
	if (isEmpty(top)) return -1;
	return top->data;
}

void display(Node* top) {
	while (top != nullptr)
	{
		cout << top->data << " ";
		top = top->next;
	}
	cout << endl;
}

void displayFromFist(Node* top) {
	while (top->next != nullptr)
	{
		top = top->next;
	}
	while (top!=nullptr)
	{
		cout << top->data << " ";
		top = top->prev;
	}
	cout << endl;
}

int checkBalance(char exp[]) {
	Node* st = nullptr;
	for (size_t i = 0; exp[i]!=NULL; i++)
	{
		if (exp[i]=='('|| exp[i] == '{'|| exp[i] == '[')
		{
			push(&st, exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (isEmpty(st))
			{
				return 0;
			}
			pop(&st);
		}
	}
	if (isEmpty(st))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int priority(const char& c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
	return 0;
}

// Kiểm tra toán tử có phải right-associative (ví dụ: ^)
bool isRightAssociative(char c) {
	return (c == '^');
}

Node* convert_infix_to_postfix(char* infix) {
	Node* opstack = nullptr;
	Node* output = nullptr;
	for (size_t i = 0; infix[i] != '\0'; i++)
	{
		char c = infix[i];
		if (isalpha(c))
		{
			push(&output, c);
		}
		else if (c == '(') {
			push(&opstack, c);
		}
		else if (c == ')') {
			while (!isEmpty(opstack) && checkTop(opstack) != '(') {
				push(&output, pop(&opstack));
			}
			if (!isEmpty(opstack) && checkTop(opstack) == '(') {
				pop(&opstack); // bỏ dấu '('
			}
		}
		else
		{
			while (!isEmpty(opstack) &&
				((isRightAssociative(c) && priority(checkTop(opstack)) > priority(c)) ||
					(!isRightAssociative(c) && priority(checkTop(opstack)) >= priority(c))))
			{
				push(&output, pop(&opstack));
			}
			push(&opstack, c);
		}
	}
	while (!isEmpty(opstack))
	{
		push(&output, pop(&opstack));
	}
	return output;
}

int Eval(char* postfix) {
	Node* opStack = nullptr;
	int x1, x2, result;
	for (size_t i = 0; postfix[i]!='\0'; i++)
	{
		char c = postfix[i];
		if (isalnum(c))
		{
			push(&opStack, c - '0');
		}
		else
		{
			x2 = pop(&opStack); x1 = pop(&opStack);
			switch (c)
			{
			case '+': result = x1 + x2; 
				break;
			case '-': result = x1 - x2;
				break;
			case '*': result = x1 * x2;
				break;
			case '/': result = x1 / x2;
			}
			push(&opStack, result);
		}
	}
	return pop(&opStack);
}

int main() {
	/*Node* st = nullptr;
	push(&st, 5);
	push(&st, 6);
	push(&st, 7);
	push(&st, 8);
	push(&st, 9);
	display(st);
	pop(&st);
	pop(&st);
	display(st);*/

	char exp[] = "{{[(a+b)*(a-c)]*2}+100]]}}";
	cout << checkBalance(exp) << endl;

	char infix[] = "A+B*(C+D)/F+D*E";
	Node* ptr = convert_infix_to_postfix(infix);
	displayFromFist(ptr);

	char postfix[]= "234*+82/-";
	cout << Eval(postfix);

	return 0;
}
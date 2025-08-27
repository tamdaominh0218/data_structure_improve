#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int data;
	Node* next;
};

void insertHead(Node** head, int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->prev = nullptr;
	newNode->next = *head;
	if (*head!=nullptr)
	{
		(*head)->prev = newNode;
	}
	*head = newNode;
}

void insertEnd(Node** head, int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr; 
	newNode->prev = nullptr;

	if (*head==nullptr)
	{
		*head = newNode;
		return;
	}

	Node* temp = *head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void displayforward(Node* head) {
	while (head!=nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void displaybackward(Node* head) {
	while (head->next!=nullptr)
	{
		head = head->next;
	}
	while (head!=nullptr)
	{
		cout << head->data << " ";
		head = head->prev;
	}
	cout << endl;
}

void deleteNode(Node** head, int posi) {
	if (*head==nullptr)
	{
		cout << "Linked list is empty" << endl;
	}
	Node* p = *head;
	Node* q = nullptr;
	if (posi == 1)
	{
		q = p;
		p = p->next;
		*head = p;
		p->prev = nullptr;
		delete q;
	}
	else if (posi > 1)
	{
		for (size_t i = 0; i < posi-1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		p->next->prev = q;
		delete p;
	}
}

void reverse(Node** head) {
	Node* right = *head;
	Node* mid = nullptr;
	Node* left = nullptr;
	while (right!=nullptr)
	{
		left = mid;
		mid = right;
		right = right->next;
		mid->next = left;
		mid->prev = right;
	}
	*head = mid;
}

int main() {
	Node* n1 = nullptr;
	insertEnd(&n1, 5);
	insertEnd(&n1, 10);
	insertEnd(&n1, 15);
	insertEnd(&n1, 20);
	insertEnd(&n1, 25);
	displayforward(n1);
	displaybackward(n1);

	//Node* n2 = nullptr;
	//insertHead(&n2, 1);
	//insertHead(&n2, 2);
	//insertHead(&n2, 3);
	//insertHead(&n2, 4);
	//insertHead(&n2, 5);
	//displayforward(n2);
	//displaybackward(n2);

	//deleteNode(&n1, 3);
	//displayforward(n1);
	//displaybackward(n1);

	reverse(&n1);
	displayforward(n1);
	//displaybackward(n1);

	return 0;
}
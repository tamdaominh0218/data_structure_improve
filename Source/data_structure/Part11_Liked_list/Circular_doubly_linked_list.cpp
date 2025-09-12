#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int data;
	Node* next;
};

void insertEnd(Node** head, int val) {
	Node* newNode = new Node;
	newNode->data = val;
	if (*head==nullptr)
	{
		*head = newNode;
		newNode->next = *head;
		newNode->prev = *head;
		return;
	}

	Node* temp = *head;
	while (temp->next!=*head)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = *head;
	(*head)->prev = newNode;
}

void display(Node* head) {
	Node* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp!=head);
	cout << endl;
}

int main() {
	Node* n1 = nullptr;
	insertEnd(&n1, 5);
	insertEnd(&n1, 6);
	insertEnd(&n1, 7);
	insertEnd(&n1, 8);
	insertEnd(&n1, 9);
	insertEnd(&n1, 10);
	display(n1);

	return 0;
}
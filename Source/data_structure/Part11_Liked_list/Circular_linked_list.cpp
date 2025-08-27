#include <iostream>
using namespace std;

struct Node
{
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
		return;
	}

	Node* temp = *head;
	while (temp->next!=*head)
	{
		temp = temp->next;
	}
	temp->next = newNode; 
	newNode->next = *head;
}

void deleteNode(Node** head, int posi) {
	int countNode = 0;
	Node* p = *head;
	Node* q = nullptr;
	do
	{
		countNode++;
		p = p->next;
	}while (p != *head);
	
	p = *head;
	if (posi==1)
	{
		Node* last = *head;
		do
		{
			last = last->next;
		} while (last->next!= *head);
		q = p;
		last->next = p->next;
		*head = last->next;
		delete q;
	}
	else if (posi>1 && posi<= countNode)
	{
		for (size_t i = 0; i < posi-1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
}

void display(Node* head) {
	if (head==nullptr)
	{
		cout << "Linked list empty\n";
		return;
	}
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
	insertEnd(&n1, 10);
	insertEnd(&n1, 20);
	insertEnd(&n1, 30);
	display(n1);
	deleteNode(&n1, 3);
	display(n1);
	return 0;
}
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

	if (*head == nullptr)
	{
		*head = newNode;
		newNode->next = *head;
		newNode->prev = *head;
		return;
	}

	Node* temp = *head;
	while (temp->next!= *head)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = *head;
	(*head)->prev = newNode;
}

void displayFoward(Node* head) {
	Node* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}

int findMidElemant(Node* head) {
	int k = 0;
	Node* temp = head;
	do
	{
		k++;
		temp = temp->next;
	} while (temp!=head);

	if (k%2!=0)
	{
		for (size_t i = 0; i <= k/2; i++)
		{
			temp = temp->prev;
		}
		return temp->data;
	}
	else
	{
		return -1;
	}
}

Node* findIntersecting(Node* head1, Node* head2) {
	int k1, k2;
	k1 = k2 = 0;
	Node* temp1 = head1;
	Node* temp2 = head2;
	do
	{
		k1++;
		temp1 = temp1->next;
	} while (temp1 != head1);
	do
	{
		k2++;
		temp2 = temp2->next;
	} while (temp2 != head2);
	temp1 = head1;
	temp2 = head2;

	Node* backup = nullptr;
	for (size_t i = 0; i < k1; i++)
	{
		for (size_t j = 0; j < k2; j++)
		{
			if (temp1->data==temp2->data)
			{
				insertEnd(&backup, temp1->data);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return backup;
}

void deletePointer(Node** head) {
	Node* p = *head;
	Node* q = nullptr;
	do
	{
		q = p;
		p = p->next;
		delete q;
	} while (p!=*head);
}

int main() {
	Node* n1 = nullptr;
	insertEnd(&n1, 5);
	insertEnd(&n1, 10);
	insertEnd(&n1, 15);
	insertEnd(&n1, 20);
	insertEnd(&n1, 25);
	insertEnd(&n1, 30);
	displayFoward(n1);
	cout << findMidElemant(n1) << endl;

	Node* n2 = nullptr;
	insertEnd(&n2, 7);
	insertEnd(&n2, 9);
	insertEnd(&n2, 10);
	insertEnd(&n2, 12);
	insertEnd(&n2, 15);
	insertEnd(&n2, 18);
	displayFoward(n2);

	Node* n12 = nullptr;
	n12 = findIntersecting(n1, n2);
	displayFoward(n12);

	deletePointer(&n1);
	deletePointer(&n2);
	deletePointer(&n12);
	return 0;
}
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
	newNode->next = nullptr;
	newNode->prev = nullptr;

	Node* temp = *head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}
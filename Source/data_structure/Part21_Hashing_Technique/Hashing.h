#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void insertNode(Node** head, int key) {
	Node* newNode = new Node{ key, nullptr };
	if (!*head)
	{
		*head = newNode; 
		return;
	}

	Node* current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = newNode;
}

int searchNode(Node** head, int key) {
	if (!*head)
	{
		return 0;
	}

	Node* temp = *head;
	while (temp != nullptr)
	{
		if (temp->data == key)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void display(Node* head) {
	Node* current = head;
	while (!current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
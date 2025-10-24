#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr) {};
};

void insertNode(Node** head, int val) {
	Node* newNode = new Node(val);
	if (*head==nullptr)
	{
		*head = newNode;
		return;
	}
	Node* current = *head;
	while (current->next!=nullptr)
	{
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
}

int searchNode(Node** head, int key) {
	if (!*head)
	{
		return 0;
	}

	Node* temp = *head;
	while (temp!=nullptr)
	{
		if (temp->data==key)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

int search(vector<int>& v, int key) {
	int remainderKey = key % 10;

	vector<Node*> hashing(10);
	for (int i = 0; i < v.size(); i++)
	{
		int remainder = v[i] % 10;
		insertNode(&hashing[remainder], v[i]);
	}

	return searchNode(&hashing[remainderKey], key);
}

void printLinked(Node* head) {
	if (!head)
	{
		return;
	}
	while (head!=nullptr)
	{
		std::cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	vector<int> vec = { 16, 27,86,54,32,17,88,95,25 };
	cout << search(vec, 545);
	return 0;
}
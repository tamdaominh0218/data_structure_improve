#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int val) :data{ val }, left{ nullptr }, right{nullptr} {};
};

Node* add(Node* root, int val) {
	Node* newNode = new Node(val);
	if (root == nullptr)
	{
		root = newNode;
		return root;
	}

	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (temp->left==nullptr)
		{
			temp->left = newNode;
			break;
		}
		else
		{
			q.push(temp->left);
		}

		if (temp->right == nullptr)
		{
			temp->right = newNode;
			break;
		}
		else
		{
			q.push(temp->right);
		}
	}
	return root;
}

void displayPre(Node* head) {
	if (head == nullptr) return;
	cout << head->data << " ";
	displayPre(head->left);
	displayPre(head->right);
}

void free(Node* head) {
	if (head == nullptr) return;
	free(head->left);
	free(head->right);
	Node* temp = head;
	delete temp;
}

int main() {
	Node* tree1 = nullptr;
	tree1 = add(tree1, 1);
	tree1 = add(tree1, 2);
	tree1 = add(tree1, 3);
	tree1 = add(tree1, 4);
	tree1 = add(tree1, 5);
	tree1 = add(tree1, 6);
	tree1 = add(tree1, 7);
	displayPre(tree1);
	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class Tree
{
public:
	Tree();
	Tree(int val);
	Node* add(int val);
	void displayPre();
	~Tree();

private:
	Node* root;
	void preOder(Node* node);
	void free(Node* node);
};

Tree::Tree()
{
	root = nullptr;
}

Tree::Tree(int val)
{
	root = new Node(val);
}

Node* Tree::add(int val) {
	if (val > 0)
	{
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
			if (temp->left == nullptr)
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
	}

	return root;
}

void Tree::preOder(Node* node) {
	if (!node) 
		return;
	cout << node->data << " ";
	preOder(node->left);
	preOder(node->right);
}

void Tree::displayPre() {
	preOder(root);
}

void Tree::free(Node* node) {
	if (!node) return;
	free(node->left);
	free(node->right);
	delete node;
}

Tree::~Tree() {
	free(root);
}

int main() {
	Tree tr1;
	tr1.add(1);
	tr1.add(2);
	tr1.add(3);
	tr1.add(4);
	tr1.add(5);
	tr1.add(6);
	tr1.add(7);
	tr1.displayPre();
	return 0;
}
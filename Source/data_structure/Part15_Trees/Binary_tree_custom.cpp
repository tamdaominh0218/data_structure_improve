#include <iostream>
#include <queue>
#include <vector>
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
	void createfromArray(const vector<int>& v);
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

void Tree::createfromArray(const vector<int>& v) {
	if (v.size() == 0)
	{
		cout << "Tree empty!" << endl;
		return;
	}

	Node* newNode = new Node(v[0]);
	root = newNode;
	queue<Node*> q;
	q.push(root);

	int i = 1;
	while (!q.empty() && i<v.size())
	{
		Node* temp = q.front();
		q.pop();
		if (v[i]!=-1 && i < v.size())
		{
			temp->left = new Node(v[i]);
			q.push(temp->left);
		}
		i++;

		if (v[i] != -1 && i < v.size())
		{
			temp->right = new Node(v[i]);
			q.push(temp->right);
		}
		i++;
	}
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
	vector<int> values = { 1, 2, 3, -1, 5, -1, 7 };
	tr1.createfromArray(values);
	cout << "Preorder: ";
	tr1.displayPre();
	cout << endl;
	return 0;
}
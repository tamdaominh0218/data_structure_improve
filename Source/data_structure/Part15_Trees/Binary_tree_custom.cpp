#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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
	void displayPreUsingStack();
	void displayIn();
	void displayInUsingStack();
	void displayPost();
	void displayPostUsingStack();
	~Tree();

private:
	Node* root;
	void preOder(Node* node);
	void inOder(Node* node);
	void postOder(Node* node);
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
		root = nullptr;
		return;
	}
	// nếu phần tử đầu tiên là - 1 thì cây rỗng
	if (v[0] == -1) {
		root = nullptr;
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

		// gán con trái
		if (v[i]!=-1)
		{
			temp->left = new Node(v[i]);
			q.push(temp->left);
		}
		i++;

		// gán con phải
		if (v[i] != -1 && i < v.size())
		{
			temp->right = new Node(v[i]);
			q.push(temp->right);
		}
		i++;
	}
}

//Preoder Tree traversal
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

// using stack
void Tree::displayPreUsingStack() {
	if (root == nullptr)
	{
		return;
	}
	stack<Node*> st;
	st.push(root);
	while (!st.empty())
	{
		Node* temp = st.top();
		st.pop();
		cout << temp->data << " ";

		if (temp->right)
		{
			st.push(temp->right);
		}
		if (temp->left)
		{
			st.push(temp->left);
		}
	}
}

//Inoder Tree traversal
void Tree::inOder(Node* node) {
	if (!node)
		return;
	inOder(node->left);
	cout << node->data << " ";
	inOder(node->right);
}

void Tree::displayIn() {
	inOder(root);
}

// using stack
void Tree::displayInUsingStack() {
	if (!root)
	{
		return;
	}
	stack<Node*> st;
	Node* temp = root;
	while (!st.empty()||temp!=nullptr)
	{
		//đi hết nhánh trái
		while (temp!=nullptr)
		{
			st.push(temp);
			temp = temp->left;
		}
		//Xử lý node
		temp = st.top();  st.pop();
		cout << temp->data << " "; //root
		//Đi nhánh phải
		temp = temp->right;
	}
}

//Postoder Tree traversal
void Tree::postOder(Node* node) {
	if (!node)
		return;
	postOder(node->left);
	postOder(node->right);
	cout << node->data << " ";
}

void Tree::displayPost() {
	postOder(root);
}

// using stack
void Tree::displayPostUsingStack() {
	if (!root)
	{
		return;
	}
	stack<Node*> st1,st2;
	Node* temp = root;
	st1.push(root);
	while (!st1.empty())
	{
		temp = st1.top(); st1.pop();
		st2.push(temp);
		if (temp->left)
		{
			st1.push(temp->left);
		}
		
		if (temp->right)
		{
			st1.push(temp->right);
		}
	}

	while (!st2.empty())
	{
		temp = st2.top(); st2.pop();
		cout << temp->data << " ";
	}
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
	vector<int> values = { 1, 2, 3, 4, 5, 6, 7 };
	tr1.createfromArray(values);
	cout << "Preorder: ";
	tr1.displayPre();
	cout << endl;

	cout << "Inorder: ";
	tr1.displayIn();
	cout << endl;

	cout << "Postorder: ";
	tr1.displayPost();
	cout << endl;

	cout << "Preorder using stack: ";
	tr1.displayPreUsingStack();
	cout << endl;

	cout << "Inorder using stack: ";
	tr1.displayInUsingStack();
	cout << endl;

	cout << "Postorder using stack: ";
	tr1.displayPostUsingStack();
	cout << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <stack>
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
	Node* root;
	int heightRHelper(Node* node);
	int heightHelper(Node* node);
public:
	void insertFromVec(vector<int>& vec);
	void displayUsingStack();
	void displayUsingInorderStack();
	void displayUsingPostorderStack();
	int heightR();
	int height();
	Tree();
	~Tree();
};

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
}

void Tree::insertFromVec(vector<int>& vec) {
	if (vec.size()==0 || vec[0] == -1)
	{
		cout << "Tree is empty!" << endl;
		root = nullptr;
		return;
	}

	Node* newNode = new Node(vec[0]);
	if (!root)
	{
		root = newNode;
	}

	queue<Node*> q;
	q.push(root);
	int i = 1;
	while (i<vec.size() && !q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (vec[i]!=-1)
		{
			temp->left = new Node(vec[i]);
			q.push(temp->left);
		}
		i++;
		if (vec[i] != -1 && !q.empty())
		{
			temp->right = new Node(vec[i]);
			q.push(temp->right);
		}
		i++;
	}
}

void Tree::displayUsingStack() {
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
	cout << endl;
}

void Tree::displayUsingInorderStack() {
	if (!root)
	{
		cout << "Empty!" << endl;
		return;
	}
	stack<Node*> st;
	Node* temp = root;

	//Lặp nếu st trống hoặc temp!=nullptr
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
		cout << temp->data << " ";
		//đi nhánh phải
		temp = temp->right;
	}
	cout << endl;
}

void Tree::displayUsingPostorderStack() {
	//st1 xử lý node, st2 lưu thứ tự root
	stack<Node*> st1, st2;
	Node* temp = root;
	st1.push(root);
	while (!st1.empty())
	{
		temp = st1.top(); st1.pop();
		//push node root sang st2
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

	//in root
	while (!st2.empty())
	{
		cout << st2.top()->data << " ";
		st2.pop();
	}
	cout << endl;
}

int Tree::heightRHelper(Node* node) {
	if (!node)
	{
		return 0;
	}

	int lheight = heightRHelper(node->left);
	int rheight = heightRHelper(node->right);
	return max(lheight, rheight) + 1;
}

int Tree::heightR() {
	return heightRHelper(root);
}

int Tree::heightHelper(Node* node) {
	if (!node)
	{
		return 0;
	}

	Node* temp1 = node;
	Node* temp2 = node;
	int hL = 0;
	int hR = 0;
	while (temp1->left!=nullptr)
	{
		if (temp1->left)
		{
			hL++;
			temp1 = temp1->left;
		}
	}

	while (temp2->right != nullptr)
	{
		if (temp2->right)
		{
			hR++;
			temp2 = temp2->right;
		}
	}

	return hL>hR ? hL+1 : hR+1;
}

int Tree::height() {
	return heightHelper(root);
}

int main() {
	vector<int> v = { 1,2,3,4,5,6,7 };
	Tree tr1;
	tr1.insertFromVec(v);
	tr1.displayUsingStack();
	tr1.displayUsingInorderStack();
	tr1.displayUsingPostorderStack();
	cout << tr1.heightR() << endl;;
	cout << tr1.height();
	return 0;
}
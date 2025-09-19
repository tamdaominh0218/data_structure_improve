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
public:
	void insertFromVec(vector<int>& vec);
	void displayUsingStack();
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
}

int main() {
	vector<int> v = { 1,2,3,4,5,6,7 };
	Tree tr1;
	tr1.insertFromVec(v);
	tr1.displayUsingStack();
	return 0;
}
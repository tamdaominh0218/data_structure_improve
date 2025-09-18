#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class BST
{
public:
	BST();
	~BST();
	void insertNode(int val);
	int search(int val);
	void displayPre();
	void displayPreUsingStack();
	void displayIn();
	void displayInUsingStack();
	void displayPost();
	void displayPostUsingStack();
	void deleteNode(int val);

private:
	Node* root;
	void free(Node* node);
	void preOder(Node* node);
	void inOder(Node* node);
	void postOder(Node* node);
};

BST::BST()
{
	root = nullptr;
}

void BST::insertNode(int val) {
	Node* newNode = new Node(val);
	if (root==nullptr)
	{
		root = newNode;
		return;
	}
	Node* r = nullptr;
	Node* temp = root;
	while (temp!=nullptr)
	{
		if (val<temp->data)
		{
			r = temp;
			temp = temp->left;
		}
		else
		{
			r = temp;
			temp = temp->right;
		}
	}
	if (val<r->data)
	{
		r->left = newNode;
	}
	else
	{
		r->right = newNode;
	}
}

int BST::search(int val) {
	if (!root)
	{
		return 0;
	}
	Node* r = nullptr;
	Node* temp = root;
	while (temp!=nullptr && val!=temp->data)
	{
		if (val<temp->data)
		{
			r = temp;
			temp = temp->left;
			if (temp==nullptr)
			{
				break;
			}
		}
		if(val > temp->data)
		{
			r = temp;
			temp = temp->right;
		}
		
	}
	if (temp == nullptr)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	return 0;

}

void BST::preOder(Node* node) {
	if (!node)
	{
		return;
	}
	cout << node->data << " ";
	preOder(node->left);
	preOder(node->right);
}

void BST::displayPre() {
	preOder(root);
}

void BST::displayPreUsingStack() {
	if (!root)
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
		if (temp->right != nullptr)
		{
			st.push(temp->right);
		}
		if (temp->left != nullptr)
		{
			st.push(temp->left);
		}
	}
}

void BST::inOder(Node* node) {
	if (!node)
	{
		return;
	}
	inOder(node->left);
	cout << node->data << " ";
	inOder(node->right);
}

void BST::displayIn() {
	inOder(root);
}

void BST::displayInUsingStack() {
	Node* temp = root;
	stack<Node*> st;

	while (!st.empty() || temp!=nullptr)
	{
		while (temp!=nullptr)
		{
			st.push(temp);
			temp = temp->left;
		}
		temp = st.top(); st.pop();
		cout << temp->data << " ";

		temp = temp->right;
	}
}

void BST::postOder(Node* node) {
	if (!node)
	{
		return;
	}
	postOder(node->left);
	postOder(node->right);
	cout << node->data << " ";
}

void BST::displayPost() {
	postOder(root);
}

void BST::displayPostUsingStack() {
	stack<Node*> st1, st2;
	st1.push(root);
	while (!st1.empty())
	{
		Node* curr = st1.top(); st1.pop();
		st2.push(curr);

		if (curr->left)
		{
			st1.push(curr->left);
		}
		if (curr->right)
		{
			st1.push(curr->right);
		}
	}
	while (!st2.empty())
	{
		cout << st2.top()->data << " ";
		st2.pop();
	}
}

void BST::free(Node* node) {
	if (!node) return;
	free(node->left);
	free(node->right);
	delete node;
}

BST::~BST()
{
	free(root);
}

void BST::deleteNode(int val) {
	if (!root)
	{
		return;
	}
	Node* curr = root;
	Node* parrent = nullptr;
	//Tìm node cần xóa và cha của nó
	while (curr->data!=val)
	{
		parrent = curr;
		if (val<curr->data)
		{
			curr = curr->left;
		}
		else if (val>curr->data)
		{
			curr = curr->right;
		}
	}

	if (curr->left && curr->right)
	{
		//Tìm successor và cha của nó
		Node* successor = curr;
		Node* succParrent = nullptr;

		if (successor->right)
		{
			successor = successor->right;
			while (successor->left != nullptr)
			{
				succParrent = successor;
				successor = successor->left;
			}
		}
		else if (!successor->right)
		{
			successor = successor->left;
			while (successor->right != nullptr)
			{
				succParrent = successor;
				successor = successor->right;
			}
		}
		//copy giá trị successor lên curr
		curr->data = successor->data;

		//chuẩn bị xóa successor
		curr = successor;
		parrent = succParrent;

		if (succParrent->left == successor)
		{
			//tiến hành xóa successor
			Node* chill = nullptr;
			if (successor->left)
			{
				chill = successor->left;
				parrent->left = chill;
				delete curr;
			}
			else if (successor->right)
			{
				chill = successor->right;
				parrent->left = chill;
				delete curr;
			}
		}
		else if (succParrent->right == successor)
		{
			//tiến hành xóa successor
			Node* chill = nullptr;
			if (successor->left)
			{
				chill = successor->left;
				parrent->right = chill;
				delete curr;
			}
			else if (successor->right)
			{
				chill = successor->right;
				parrent->right = chill;
				delete curr;
			}
		}
	}
	else if (curr->left==nullptr && curr->right==nullptr)
	{
		if (parrent->left)
		{
			parrent->left = nullptr;
			delete curr;
		}
		else if (parrent->right)
		{
			parrent->left = nullptr;
			delete curr;
		}
	}
	else if(curr->right)
	{
		Node* chill = nullptr;
		if (parrent->left)
		{
			chill = curr->right;
			parrent->left = chill;
			delete curr;
		}
		else if (parrent->right)
		{
			chill = curr->right;
			parrent->right = chill;
			delete curr;
		}
	}
	else if (curr->left)
	{
		Node* chill = nullptr;
		if (parrent->left)
		{
			chill = curr->left;
			parrent->left = chill;
			delete curr;
		}
		else if (parrent->right)
		{
			chill = curr->left;
			parrent->right = chill;
			delete curr;
		}
	}
}

int main() {
	BST tr1;
	tr1.insertNode(9);
	tr1.insertNode(15);
	tr1.insertNode(5);
	tr1.insertNode(20);
	tr1.insertNode(16);
	tr1.insertNode(8);
	tr1.insertNode(12);
	tr1.insertNode(3);
	tr1.insertNode(6);
	tr1.insertNode(13);
	tr1.insertNode(17);
	
	tr1.displayPre();
	cout << endl;
	tr1.displayPreUsingStack();
	cout << endl;

	/*tr1.displayIn();
	cout << endl;
	tr1.displayInUsingStack();
	cout << endl;

	tr1.displayPost();
	cout << endl;
	tr1.displayPostUsingStack();
	cout << endl;*/

	//Delete BST
	tr1.deleteNode(15);
	tr1.displayPreUsingStack();
	
	return 0;
}
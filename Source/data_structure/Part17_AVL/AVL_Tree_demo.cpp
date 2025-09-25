#include <iostream>
#include <memory>
#include <stack>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	int height;
	Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {};
};

class AVL
{
	Node* root;
	Node* insertAVL_Helper(Node* node, int key);
	int heightNodeHelper(Node* node);
	void free(Node* node);
	Node* minNodeRight(Node* node);
	Node* deleteNodeAVL_Helper(Node* node, int val);
public:
	void insertAVL(int key);
	int heightTree();
	int AVLBalance(Node* node);
	Node* LLrotation(Node* node);
	Node* RRrotation(Node* node);
	Node* LRrotation(Node* node);
	Node* RLrotation(Node* node);
	void displayPreOrder();
	void deleteNodeAVL(int val);
	AVL();
	~AVL();
};

AVL::AVL()
{
	root = nullptr;
}

void AVL::free(Node* node) {
	if (!node) return;
	free(node->left);
	free(node->right);
	delete node;
}

AVL::~AVL()
{
	free(root);
}

int AVL::AVLBalance(Node* node) {
	if (!node)
	{
		return 0;
	}
	return heightNodeHelper(node->left) - heightNodeHelper(node->right);
}

int AVL::heightNodeHelper(Node* node) {
	if (!node)
	{
		return 0;
	}

	int lHeight = heightNodeHelper(node->left);
	int rHeight = heightNodeHelper(node->right);
	return max(lHeight, rHeight) + 1;
}

int AVL::heightTree() {
	return heightNodeHelper(root);
}

Node* AVL::insertAVL_Helper(Node* node, int key) {
	if (!node)
	{
		node = new Node(key);
		return node;
	}

	if (key< node->data)
	{
		node->left = insertAVL_Helper(node->left, key);
	}
	else if (key > node->data)
	{
		node->right = insertAVL_Helper(node->right, key);
	}
	else
	{
		return node;
	}

	//update height node
	node->height = heightNodeHelper(node);

	//LL rotation case
	if (AVLBalance(node)>=2 && AVLBalance(node->left)>=1)
	{
		return LLrotation(node);
	}

	//RR rotation case
	if (AVLBalance(node) <= -2 && AVLBalance(node->right) <= -1)
	{
		return RRrotation(node);
	}

	//LR rotation case
	if (AVLBalance(node) >= 2 && AVLBalance(node->left) <= -1)
	{
		return LRrotation(node);
	}

	//RL rotation case
	if (AVLBalance(node) <= -2 && AVLBalance(node->right) >= 1)
	{
		return RLrotation(node);
	}

	return node;
}

void AVL::insertAVL(int key) {
	root = insertAVL_Helper(root, key);
}

Node* AVL::LLrotation(Node* node) {
	Node* LP = node->left;
	Node* RLP = LP->right;

	LP->right = node;
	node->left = RLP;
	node->height = heightNodeHelper(node);
	LP->height = heightNodeHelper(LP);

	if (root == node) root = LP;
	return LP;
}

Node* AVL::RRrotation(Node* node) {
	Node* RP = node->right;
	Node* LRP = RP->left;

	RP->left = node;
	node->right = LRP;
	node->height = heightNodeHelper(node);
	RP->height = heightNodeHelper(RP);

	if (root == node) root = RP;
	return RP;
}

Node* AVL::LRrotation(Node* node) {
	node->left = RRrotation(node->left);
	return LLrotation(node);
}

Node* AVL::RLrotation(Node* node) {
	node->right = LLrotation(node->right);
	return RRrotation(node);
}

void AVL::displayPreOrder() {
	if (!root)
	{
		return;
	}
	stack<Node*> st;
	st.push(root);
	while (!st.empty())
	{
		Node* temp = st.top(); st.pop();
		cout << temp->data << " ";
		if (temp->right!=nullptr)
		{
			st.push(temp->right);
		}
		
		if (temp->left != nullptr)
		{
			st.push(temp->left);
		}
	}
	cout << endl;
}

Node* AVL::minNodeRight(Node* node) {
	Node* temp = node->right;
	while (temp->left!=nullptr)
	{
		temp = temp->left;
	}
	return temp;
}

Node* AVL::deleteNodeAVL_Helper(Node* node, int val) {
	if (!node) {
		cout << "AVL tree is empty" << endl;
		return nullptr;
	}

	// Tìm node cần xóa
	Node* curr = node;
	Node* curr_parent = nullptr;
	while (curr != nullptr) {
		if (val < curr->data) {
			curr_parent = curr;
			curr = curr->left;
		}
		else if (val > curr->data) {
			curr_parent = curr;
			curr = curr->right;
		}
		else {
			break;
		}
	}

	// Không tìm thấy
	if (curr == nullptr) {
		cout << "AVL tree has no data to delete\n";
		return node;   // giữ nguyên cây
	}

	// Nếu có 2 con → tìm successor
	if (curr->left && curr->right) {
		Node* successor = curr->right;
		Node* successor_parent = curr;
		while (successor->left != nullptr) {
			successor_parent = successor;
			successor = successor->left;
		}
		curr->data = successor->data;   // copy data
		curr = successor;
		curr_parent = successor_parent;
	}

	// Node có 0 hoặc 1 con
	Node* child = (curr->left) ? curr->left : curr->right;

	if (!curr_parent) {
		node = child;   // root = con
		delete curr;
	}
	else if (curr_parent->left == curr) {
		curr_parent->left = child;
		delete curr;
	}
	else if (curr_parent->right == curr) {
		curr_parent->right = child;
		delete curr;
	}

	if (!node) return node;

	// Cập nhật height
	node->height = heightNodeHelper(node);

	// Cân bằng lại root node
	int balance = AVLBalance(node);

	// LL
	if (balance > 1 && AVLBalance(node->left) >= 0)
		return LLrotation(node);

	// LR
	if (balance > 1 && AVLBalance(node->left) < 0) {
		node->left = RRrotation(node->left);
		return LLrotation(node);
	}

	// RR
	if (balance < -1 && AVLBalance(node->right) <= 0)
		return RRrotation(node);

	// RL
	if (balance < -1 && AVLBalance(node->right) > 0) {
		node->right = LLrotation(node->right);
		return RRrotation(node);
	}

	return node;
}

void AVL::deleteNodeAVL(int val) {
	root = deleteNodeAVL_Helper(root, val);
}

int main() {
	AVL avl1;
	avl1.insertAVL(4);
	avl1.insertAVL(9);
	avl1.insertAVL(18);
	avl1.insertAVL(21);
	avl1.insertAVL(25);
	avl1.deleteNodeAVL(21);
	avl1.displayPreOrder();

	return 0;
}
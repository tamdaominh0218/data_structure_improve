#include "Tree.h"
Tree::Tree() : root(nullptr) {};

void Tree::createfromVector(const vector<int>& vec) {
	if (vec.empty() || vec[0]==-1)
	{
		cout << "Empty tree" << endl;
		root = nullptr;
		return;
	}
	TNode* newNode = new TNode(vec[0]);
	root = newNode;
	Queue q;
	q.push(root);

	int i = 1;
	while (!q.isEmpty() && i<vec.size())
	{
		TNode* temp = q.pop();
		
		if (vec[i]!=-1 && i<vec.size())
		{
			TNode* newNode = new TNode(vec[i]);
			temp->left = newNode;
			q.push(temp->left);
		}
		i++;
		if (vec[i] != -1 && i < vec.size())
		{
			TNode* newNode = new TNode(vec[i]);
			temp->right = newNode;
			q.push(temp->right);
		}
		i++;
	}
}

void Tree::preOder(TNode* head) {
	if (!head)
	{
		return;
	}
	cout << head->data << " ";
	preOder(head->left);
	preOder(head->right);
}

void Tree::displayOder() {
	preOder(root);
}

void Tree::free(TNode* head) {
	TNode* temp = head;
	if (!head)
	{
		return;
	}
	free(temp->left);
	free(temp->right);
	delete temp;
}

Tree::~Tree() {
	free(root);
}
#pragma once
#include "Queue.h"
#include <vector>
using namespace std;
class Tree
{
	TNode* root;
	void preOder(TNode* head);
	void free(TNode* head);
public:
	Tree();
	~Tree();
	void createfromVector(const vector<int>& vec);
	void displayOder();
};


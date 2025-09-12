#pragma once
#include <iostream>

class TNode
{
public:
	int data;
	TNode* left;
	TNode* right;
	TNode(int val) : data(val), left(nullptr), right(nullptr) {};
};

class QNode {
public:
	TNode* data;
	QNode* next;
	QNode() : data(nullptr), next(nullptr) {};
};

class Queue {
	QNode* front;
	QNode* rear;
public:
	Queue() : front(nullptr), rear(nullptr) {};
	~Queue();
	void push(TNode* val);
	TNode* pop();
	int isEmpty();
};

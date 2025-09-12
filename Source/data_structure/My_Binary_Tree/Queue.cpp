#include "Queue.h"
using namespace std;

void Queue::push(TNode* val) {
	QNode* newNode = new QNode;
	newNode->data = val;
	newNode->next = nullptr;
	if (newNode == nullptr)
	{
		cout << "Queue overflow" << endl;
		return;
	}

	if (front==nullptr)
	{
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}

TNode* Queue::pop() {
	if (front==nullptr)
	{
		cout << "Queue is empty" << endl;
		return nullptr;
	}
	QNode* temp = nullptr;
	temp = front;
	TNode* x = front->data;
	front = front->next;
	delete temp;
	return x;
}

int Queue::isEmpty() {
	return front == nullptr;
}

Queue::~Queue() {
	QNode* temp = nullptr;
	while (front->next !=nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	//gán rear về nullptr, tránh rear trỏ lung tung (vì rear vẫn có thể đang giữ 1 con trỏ rác sau vòng lặp ở trên)
	rear = nullptr;
}
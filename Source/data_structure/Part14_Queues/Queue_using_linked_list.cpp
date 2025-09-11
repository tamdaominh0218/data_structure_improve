#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue
{
private:
	Node* front;
	Node* rear;
public:
	Queue() :front{ nullptr }, rear{nullptr} {};
	~Queue();
	void push(int val);
	int pop();
	int isEmpty();
	int isFull();
	void display();
	int getFront();
	int getRear();
	int peek(int posi);
};

void Queue::push(int val) {
	Node* t = new Node{val, nullptr};
	if (t == nullptr)
	{
		cout << "Queue is overfolow" << endl;
	}
	if (isEmpty())
	{
		rear = front = t;
	}
	else
	{
		rear->next = t;
		rear = t;
	}
}

int Queue::isEmpty() {
	return front == nullptr;
}

// Kiểm tra queue đầy (hiếm khi xảy ra, chỉ khi hết bộ nhớ)
int isFull() {
	Node* temp = new(nothrow) Node;
	if (temp == nullptr)
		return true;
	delete temp;
	return false;
}

int Queue::getFront() {
	if (isEmpty())
	{
		return -1;
	}
	return front->data;
}

int Queue::getRear() {
	if (isEmpty())
	{
		return -1;
	}
	return rear->data;
}

int Queue::pop() {
	if (isEmpty())
		return -1;

	Node* temp = front;
	int x = front->data;
	front = front->next;
	delete temp;
	return x;
}

void Queue::display() {
	Node* temp = front;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int Queue::peek(int posi) {
	Node* temp = front;
	int count = 0;
	while (temp !=nullptr)
	{
		count++;
		temp = temp->next;
	}
	temp = front;
	if (isEmpty()||posi>=count||posi<0)
	{
		return -1;
	}

	for (int i = 1; i <= posi; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

Queue::~Queue()
{
	Node* temp = nullptr;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
}

int main() {
	Queue q1;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	q1.push(50);
	q1.display();
	cout << "Peek position 5: " << q1.peek(5) << endl;
	cout << "Pop: " << q1.pop() << endl;
	cout << "Pop: " << q1.pop() << endl;
	q1.display();
	cout << "Front: " << q1.getFront() << ", Rear: " << q1.getRear() << endl;

	return 0;
}
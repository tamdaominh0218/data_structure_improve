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
	Queue() :front{ nullptr }, rear{ nullptr } {};
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
	Node* t = new Node{ val, nullptr };
	if (t == nullptr)
	{
		cout << "Queue is overfolow" << endl;
	}
	if (isEmpty())
	{
		rear = front = t;
		t->next = front;
	}
	else
	{
		rear->next = t;
		rear = t;
		t->next = front;
	}
}

int Queue::isEmpty() {
	return front == nullptr;
}

// Kiểm tra queue đầy (hiếm khi xảy ra, chỉ khi hết bộ nhớ)
int Queue::isFull() {
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
	if (isEmpty()) return -1;

	int x = front->data;
	if (front == rear) { // chỉ 1 phần tử
		delete front;
		front = rear = nullptr;
	}
	else {
		Node* temp = front;
		front = front->next;
		rear->next = front;
		delete temp;
	}
	return x;
}

void Queue::display() {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}

	Node* temp = front;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp!= front);
	cout << endl;
}

int Queue::peek(int posi) {
	if (isEmpty()) return -1;

	// đếm số node
	int count = 0;
	Node* temp = front;
	do {
		count++;
		temp = temp->next;
	} while (temp != front);

	if (posi < 0 || posi >= count) return -1;

	temp = front;
	for (int i = 0; i < posi; i++) {
		temp = temp->next;
	}
	return temp->data;
}

Queue::~Queue()
{
	if (isEmpty()) return;
	Node* temp;
	rear->next = nullptr; // phá vòng tròn để duyệt dễ hơn
	while (front != nullptr) {
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
	cout << "Peek position 1: " << q1.peek(1) << endl;
	cout << "Pop: " << q1.pop() << endl;
	cout << "Pop: " << q1.pop() << endl;
	q1.display();
	cout << "Front: " << q1.getFront() << ", Rear: " << q1.getRear() << endl;

	return 0;
}
#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() : front{ nullptr }, rear{ nullptr } {}

void Queue::push(Node* val) {
    QNode* t = new QNode{ val, nullptr };
    if (t == nullptr) {
        cout << "Queue is overflow" << endl;
        return;
    }
    if (isEmpty()) {
        rear = front = t;
    }
    else {
        rear->next = t;
        rear = t;
    }
}

int Queue::isEmpty() {
    return front == nullptr;
}

int Queue::isFull() {
    QNode* temp = new(nothrow) QNode;
    if (temp == nullptr)
        return true;
    delete temp;
    return false;
}

Node* Queue::pop() {
    if (isEmpty())
        return nullptr;

    QNode* temp = front;
    Node* x = front->data;
    front = front->next;
    delete temp;
    return x;
}

Queue::~Queue() {
    QNode* temp = nullptr;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

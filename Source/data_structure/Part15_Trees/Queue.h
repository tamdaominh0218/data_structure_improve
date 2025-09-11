#pragma once
#include "Node.h"

struct QNode {
    Node* data;
    QNode* next;
};

class Queue {
private:
    QNode* front;
    QNode* rear;
public:
    Queue();
    ~Queue();
    void push(Node* val);
    Node* pop();
    int isEmpty();
    int isFull();
};

#include <iostream>
#include "Queue.h"
using namespace std;

Node* insertTree(Node* root, int val) {
    Node* newNode = new Node(val);
    if (root == nullptr)
        return newNode;

    Queue q;
    q.push(root);

    while (!q.isEmpty()) {
        Node* temp = q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        }
        else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        }
        else {
            q.push(temp->right);
        }
    }
    return root;
}

void display(Node* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    display(head->left);
    display(head->right);
}

int main() {
    Node* tree1 = nullptr;
    tree1 = insertTree(tree1, 1);
    tree1 = insertTree(tree1, 2);
    tree1 = insertTree(tree1, 3);
    tree1 = insertTree(tree1, 4);
    tree1 = insertTree(tree1, 5);
    tree1 = insertTree(tree1, 6);
    tree1 = insertTree(tree1, 7);

    display(tree1);
}

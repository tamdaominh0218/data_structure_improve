#include <iostream>

enum class Color { RED, BLACK };

class RBTree {
private:
    struct Node {
        int data;
        Color color;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val, Color c, Node* p = nullptr)
            : data(val), color(c), left(nullptr), right(nullptr), parent(p) {}
    };

    Node* root;

    // ===== Helper functions =====
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;

        y->parent = x->parent;
        if (!x->parent) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;

        y->parent = x->parent;
        if (!x->parent) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* z) {
        while (z->parent && z->parent->color == Color::RED) {
            Node* parent = z->parent;
            Node* grandparent = parent->parent;
            if (!grandparent) break;

            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;
                if (uncle && uncle->color == Color::RED) {
                    parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    grandparent->color = Color::RED;
                    z = grandparent;
                }
                else {
                    if (z == parent->right) {
                        z = parent;
                        rotateLeft(z);
                    }
                    parent->color = Color::BLACK;
                    grandparent->color = Color::RED;
                    rotateRight(grandparent);
                }
            }
            else {
                Node* uncle = grandparent->left;
                if (uncle && uncle->color == Color::RED) {
                    parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    grandparent->color = Color::RED;
                    z = grandparent;
                }
                else {
                    if (z == parent->left) {
                        z = parent;
                        rotateRight(z);
                    }
                    parent->color = Color::BLACK;
                    grandparent->color = Color::RED;
                    rotateLeft(grandparent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    Node* insertBST(Node* rootNode, int val, Node* parent) {
        if (!rootNode) {
            Node* newNode = new Node(val, Color::RED, parent);
            if (!parent) root = newNode;
            else if (val < parent->data) parent->left = newNode;
            else parent->right = newNode;
            return newNode;
        }

        if (val < rootNode->data)
            return insertBST(rootNode->left, val, rootNode);
        else if (val > rootNode->data)
            return insertBST(rootNode->right, val, rootNode);

        return rootNode; // không chèn trùng
    }

    void inorderHelper(Node* node) const {
        if (!node) return;
        inorderHelper(node->left);
        std::cout << node->data << (node->color == Color::RED ? "(R) " : "(B) ");
        inorderHelper(node->right);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    RBTree() : root(nullptr) {}

    ~RBTree() {
        destroy(root);
    }

    void insert(int val) {
        Node* newNode = insertBST(root, val, nullptr);
        if (newNode) fixInsert(newNode);
    }

    void inorder() const {
        inorderHelper(root);
        std::cout << std::endl;
    }
};

int main() {
    RBTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    std::cout << "Inorder traversal of Red-Black Tree: ";
    tree.inorder();
}

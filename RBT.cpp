#include "RBT.h"

Node::Node(int data) {
    this->data = data;
    color = RED;
    left = right = parent = NULL;
}

RBT::RBT() {
    root = NULL;
}

int RBT::getColor(Node*& node) {
    if (node == NULL)
        return BLACK;
    return node->color;
}

void RBT::setColor(Node*& node, int color) {
    if (node == NULL)
        return;
    node->color = color;
}

Node* RBT::insert_r(Node*& root, Node*& ptr) {
    if (root == NULL)
        return ptr;
    if (ptr->data < root->data) {
        root->left = insert_r(root->left, ptr);
        root->left->parent = root;
    }
    else if (ptr->data > root->data) {
        root->right = insert_r(root->right, ptr);
        root->right->parent = root;
    }
    return root;
}

void RBT::insert(int n) {
    Node* node = new Node(n);
    root = insert_r(root, node);
    fixInsert(node);
}

void RBT::rotateLeft(Node*& ptr) {
    Node* right_child = ptr->right;
    ptr->right = right_child->left;
    if (ptr->right != NULL)
        ptr->right->parent = ptr;
    right_child->parent = ptr->parent;
    if (ptr->parent == NULL)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;
    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBT::rotateRight(Node*& ptr) {
    Node* left_child = ptr->left;
    ptr->left = left_child->right;
    if (ptr->left != NULL)
        ptr->left->parent = ptr;
    left_child->parent = ptr->parent;
    if (ptr->parent == NULL)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;
    left_child->right = ptr;
    ptr->parent = left_child;
}

void RBT::fixInsert(Node*& ptr) {
    Node* parent = NULL;
    Node* grandparent = NULL;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
        else {
            Node* uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}

bool RBT::search(int data) {
    Node* temp = root;
    while (1) {
        if (temp == NULL) {
            return false;
        }
        else if (data < temp->data) {
            temp = temp->left;
        }
        else if (data > temp->data) {
            temp = temp->right;
        }
        else {
            return true;
        }
    }
}

void RBT::inorder_r(Node*& ptr) {
    if (ptr == NULL)
        return;
    inorder_r(ptr->left);
    cout << ptr->data << "\tColor: " << ptr->color << endl;
    inorder_r(ptr->right);
}

void RBT::inorder() {
    cout << "0 is RED, 1 is BLACK\n";
    inorder_r(root);
}
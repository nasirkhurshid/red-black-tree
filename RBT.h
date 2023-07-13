#include <iostream>
using namespace std;

enum Color {RED, BLACK};
struct Node
{
    int data;
    int color;
    Node* left, * right, * parent;
    explicit Node(int);
};

class RBT
{
private:
    Node* root;
protected:
    Node* insert_r(Node*&, Node*&);
    void fixInsert(Node*&);
    void rotateLeft(Node*&);
    void rotateRight(Node*&);
    int getColor(Node*&);
    void setColor(Node*&, int);
    void inorder_r(Node*&);
public:
    RBT();
    void insert(int);
    bool search(int);
    void inorder();
};
#include "RBT.h"
using namespace std;
int main() {
    int n, data;
    RBT rbTree;
    cout << "How many values do you want to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> data;
        rbTree.insert(data);
    }      
    cout << "\nIn-order Tree Traversal:\n";
    rbTree.inorder();       //first digit is value, second is color, 0 for red, 1 for black
    cout << "\nFound 3: " << rbTree.search(3) << endl;
    return 0;
}
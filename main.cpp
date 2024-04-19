#include "bst.h"
#include <iostream>
using namespace std;
int main() {
    BST* tree = new BST();
    node* nodes[100];
    char op;
    int num;
    do {
        cout << "Op: ";
        cin >> op;
        node* n;
        switch (op) {
            case 'i':
                cin >> num;
                nodes[num] = tree->insert(num);
                break;
            case 's':
                cin >> num;
                tree->search(num);
                break;
            case 'd':
                cin >> num;
                tree->remove(num);
                break;
            case 'p':
                tree->print();
                break;

 // Uncomment this for Unit Testing 1
            case 'L':
                cin >> num;
                tree->zigleft(nodes[num]);
                break;
            case 'R':
                cin >> num;
                tree->zigright(nodes[num]);
                break;


/*
	// Uncomment this for Unit Testing 2
            case 'R':
                cin >> num;
                tree->restructure(nodes[num]);
                break;
*/
            case 'x':
                cout << "Exiting";
                break;
            default:
                cout << "Invalid operation";
        }
    } while (op != 'x');
};

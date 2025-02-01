#include "bintree.h"
#include <iostream>

using namespace std;

void buildTree(BinTree &T) {
    // Manually input data instead of reading from a file
    string values[] = {"10", "5", "15", "3", "7", "12", "18", "1", "4", "6", "8", "11", "13", "16", "20"};
    for (const string &val : values) {
        T.insert(val);
    }
}

void printArray(string a[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (!a[i].empty())
            cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
    cout << "Building tree with manual input" << endl;
    BinTree filetree;
    buildTree(filetree);

    cout << "Sideway print: " << endl;
    filetree.displaySideways();

    cout << "Display tree: " << endl;
    filetree.displayTree();

    cout << "Inorder: " << filetree << endl;

    // Test getHeight and retrieve
    cout << "Test retrieve and getHeight" << endl;
    string testnode = "18";
    Node *addr = nullptr;
    bool found = filetree.retrieve(testnode, addr);
    cout << "Retrieve " << testnode << (found ? ": found" : ": not found") << endl;
    if (found)
        cout << "Node address = " << addr << endl;

    cout << "Height of node " << testnode << " is " << filetree.getHeight(testnode) << endl;

    // Copy constructor
    BinTree copytree(filetree);
    cout << "Copy Tree: " << copytree << endl;

    // Assignment operator
    BinTree T = filetree;
    cout << "Assign Tree: " << T << endl;

    cout << "Are they same?  " << ((copytree == T) ? " yes " : " no") << endl;
    cout << "Are they different?  " << ((copytree != T) ? " yes " : " no") << endl;

    cout << "BST to Array" << endl;
    string ndarray[ARRAYSIZE] = {};

    BinTree original(filetree);
    filetree.bstreeToArray(ndarray);
    printArray(ndarray);

    cout << "Array to BST: should balance the tree" << endl;
    filetree.arrayToBSTree(ndarray);
    filetree.displaySideways();
    filetree.displayTree();

    cout << "Compare the original tree and recovered tree" << endl;
    cout << "Are they same?  " << ((original == filetree) ? " yes " : " no") << endl;
    cout << "Are they different?  " << ((original != filetree) ? " yes " : " no") << endl;

    return 0;
}

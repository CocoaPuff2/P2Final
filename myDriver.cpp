#include "bintree.h"
#include <iostream>

using namespace std;

void printArray(string a[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (!a[i].empty())
            cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
    BinTree filetree;
    string values[] = {"10", "5", "15", "3", "7", "12", "18", "1", "4", "6", "8", "11", "13", "16", "20"};

    cout << "Test insert method: " << endl;
    for (const string &val : values) {
        filetree.insert(val);
    }

    // Testing sideway print
    cout << "Test display sideways method: " << endl;
    filetree.displaySideways();

    cout << "Test display of tree structure: " << endl;
    filetree.displayTree();

    cout << "Inorder: " << filetree << endl;

    // Test getHeight and retrieve
    cout << "Test retrieve and getHeight methods" << endl;
    string testnode = "7";
    Node *addr = nullptr;
    bool found = filetree.retrieve(testnode, addr);
    cout << "Retrieve " << testnode << (found ? ": found" : ": not found") << endl;
    if (found)
        cout << "Node address = " << addr << endl;

    cout << "Height of the node " << testnode << " is " << filetree.getHeight(testnode) << endl;

    cout << "Test isEmpty(): " << endl;
    cout << (filetree.isEmpty() ? "Tree is empty" : "Tree is NOT empty") << endl;

    // Copy constructor
    BinTree copytree(filetree);
    cout << "Copy Tree: " << copytree << endl;

    // Assignment operator
    BinTree T = filetree;
    cout << "Assign Tree: " << T << endl;

    cout << "Are they same?  " << ((copytree == T) ? " yes " : " no") << endl;
    cout << "Are they different?  " << ((copytree != T) ? " yes " : " no") << endl;

    cout << "BST to Array" << endl;
    string ndarray[ARRAYSIZE] = {}; // Ensure it's initialized

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

    // Clear the array to avoid potential memory issues
    for (int i = 0; i < ARRAYSIZE; i++) {
        ndarray[i].clear();
    }

    return 0;
}

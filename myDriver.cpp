
#include "bintree.h"
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

/*

void printArray(string a[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (!a[i].empty())
            cout << a[i] << ' ';
    }
    cout << endl;
}


int main() {
    BinTree tree;
    string values[] = {"10", "5", "15", "3", "7", "12", "18", "1", "4", "6", "8", "11", "13", "16", "20"};

    cout << "Test insert method: " << endl;
    for (const string &val : values) {
        tree.insert(val);
    }

    cout << "Test display sideways method: " << endl;
    tree.displaySideways();

    cout << "Test display of tree structure: " << endl;
    tree.displayTree();

    cout << "Test retrievee: " << endl;
    string target = "7";
    Node *addr;
    bool found = tree.retrieve(target, addr);
    cout << "Retrieve " << tree << (found ? ": found" : ": not found")
         << endl;
    if (found)
        cout << "Node address = " << addr << endl;

    cout << "Height of node " << target << " is " << tree.getHeight(target) << endl;

    cout << "Test isEmpty(): " << endl;
    cout << (tree.isEmpty() ? "Tree is empty" : "Tree is NOT empty") << endl;

    BinTree copytree(tree);
    cout << "Copy Tree: " << copytree << endl;

    BinTree T = tree;
    cout << "Assign Tree: " << T << endl;
    cout << "Are they the same?  " << ((copytree == T) ? " yes " : " no") << endl;
    cout << "Are they different?  " << ((copytree != T) ? " yes " : " no") << endl;

    cout << "BST to Array" << endl;
    string ndarray[ARRAYSIZE];
    BinTree original (tree);
    tree.bstreeToArray(ndarray);
    printArray(ndarray);

    cout << "Array to BST: should balance the tree" << endl;
    tree.arrayToBSTree(ndarray);
    tree.displaySideways();
    tree.displayTree();

    cout<<"Compare the original tree and recovered tree"<<endl;
    cout << "Are they the same?  " << ((original == tree) ? " yes " : " no")
         << endl;

    cout << "Are they different?  " << ((original != tree) ? " yes " : " no")
         << endl;

    tree.arrayToBSTree(ndarray);
    tree.displaySideways();
    tree.displayTree();

    cout<<"Compare the original tree and recovered tree"<<endl;

    cout << "Are they same?  " << ((original == tree) ? " yes " : " no")
         << endl;

    cout << "Are they different?  " << ((original != tree) ? " yes " : " no")
         << endl;


    return 0;

}
 */


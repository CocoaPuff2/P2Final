#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int ARRAYSIZE = 100;

// BST Node contains pointer for left, right, and data
struct Node {
    string data;
    Node *left;
    Node *right;
};

class BinTree {

    // Overloaded << : prints BinTree in correct structure

    friend ostream &operator<<(ostream &, const BinTree &);

public:
    // Constructors
    BinTree();
    BinTree(const BinTree &);

    // Desctructor
    ~BinTree();

    // required PUBLIC methods
    bool isEmpty() const; // check if tree is empty

    // retrieve the pointer of the node of given data
    bool retrieve(const string &, Node *&) const;

    bool insert(const string &); // insert node with the node data

    // displays the tree in pre-order, provide prefix (Root, L--, R--)
    void displayTree() const;

    void displaySideways() const; // displays the tree sideways

    // get height of a node starting from leaf (= 1)
    int getHeight(const string &) const;

    // Overload operators
    // -- Assignment Operator
    BinTree &operator=(const BinTree &); // this = rhs
    // -- Comparison Operators
    bool operator==(const BinTree &) const; // this == rhs
    bool operator!=(const BinTree &) const; // this != rhs

    // Miscellaneous Functions
    void bstreeToArray(string[]);
    void arrayToBSTree(string[]);

private:
    Node *root; // Points to the root of the BST

    // helper methods
    bool insertHelper(Node *&, const string &);
    bool retrieveHelper(Node *, const string &, Node *&) const;

    int getHeightHelper(Node *, const string &) const;
    int nodeHeight(Node *) const; // Helper to compute height from a given node

    void displayTreeHelper(Node *, string) const;
    void displaySidewaysHelper(Node *, int) const;

    int bstreeToArrayHelper(Node *, string[], int);
    Node *arrayToBSTreeHelper(string[], int, int);

    void makeEmpty(Node *&);
    Node *copyTree(Node *);


};

#endif
#include "bintree.h"
#include <iomanip>
using namespace std;

// constructor
BinTree::BinTree() : root(nullptr) {}

// copy
BinTree::BinTree(const BinTree &other) {
    root = copyTree(other.root);
};

// destructor
BinTree::~BinTree() {
    makeEmpty(root);
}

// HELPERS
// recursively delete ndoes
void BinTree::makeEmpty(Node *&node) {
    if (node != nullptr) {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
        node = nullptr;
    }
}

// recursively copy nodes
Node *BinTree::copyTree(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node *newNode = new Node(node->data, nullptr, nullptr);
    newNode->left = copyTree(node->left);
    newNode->left = copyTree(node->right);
    return newNode;
}


// PUBLIC METHODS
bool BinTree::isEmpty() const {
    return root == nullptr;
}

bool BinTree::retrieve(const string &value,Node *&result) const {
    return retrieveHelper(root, value, result);
}

bool BinTree::insert(const string &value) {
    return insertHelper(root, value);
}

void BinTree::displayTree() const {
    return displayTreeHelper(root, "Root");
}

void BinTree::displaySideways() const {
    displaySidewaysHelper(root, 0);
}

int BinTree::getHeight(const string &value) const {
    return getHeightHelper(root, value);
}

void BinTree::bstreeToArray(string arr[]) {
    int index = 0;
    index = bstreeToArrayHelper(root, arr, index);
    makeEmpty(root);
}

void BinTree::arrayToBSTree(string arr[]) {
    root = arrayToBSTreeHelper(arr, 0, ARRAYSIZE - 1);
    // clear array when the tree is build
    for (int i = 0; i < ARRAYSIZE; ++i) {
        arr[i] = "";
    }

}

// OPERATOR OVERLOAD
BinTree &BinTree::operator=(const BinTree &rhs) {
    if (this != &rhs) {
        makeEmpty(root);
        root = copyTree(rhs.root);
    }
    return *this;
}

bool BinTree::operator==(const BinTree &rhs) const {
    return compareTrees(root, rhs.root);
}

bool BinTree::operator!=(const BinTree &rhs) const {
    return !(*this == rhs);
}

ostream &operator<<(ostream &output, const BinTree &tree) {
    tree.inorderTravesal(output, tree.root);
    return output;
}



// PRIVATE HELPERS

bool BinTree::insertHelper(Node *&node, const string &value) {
    if (!node) {
        node = new Node(value, nullptr, nullptr);
        return true;
    }
    if (value < node->data) {
        return insertHelper(node->left, value);
    } else if (value > node->data) {
        return insertHelper(node->right, value);
    }
    return false;
}

bool BinTree::retrieveHelper(Node *node, const string &value, Node *&result) const {
    if (!node) return false;
    if (value == node->data) {
        result = node;
        return true;
    }

    if (value < node->data) {
        return retrieveHelper(node->left, value, result);
    }
    return retrieveHelper(node->right, value, result);
}
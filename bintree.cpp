#include "bintree.h"
#include <iomanip>
using namespace std;
/*
 * ORDER:
 * 1. constructors and destructor and their helpers
 * 2. assignment/compare operators and their helper
 * 3. print/display methods and their helpers
 * 4. other required methods and their helpers
 */

/*
 * 1. CONSTRUCTORS AND DESTRUCTOR
 */

// 1. constructor (create empty tree)
BinTree::BinTree() : root(nullptr) {}

// 1.  copy (deep copy)
BinTree::BinTree(const BinTree &other) {
    root = copyTree(other.root);
};

// 1. destructor
BinTree::~BinTree() {
    makeEmpty(root);
}

// 1. PRIVATE HELPERS
Node *BinTree::copyTree(Node *node) {
    // recursively copy nodes
    if (node == nullptr) {
        return nullptr;
    }
    Node *newNode = new Node(node->data, nullptr, nullptr);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

void BinTree::makeEmpty(Node *&node) {
    // recursively delete nodes
    if (node != nullptr) {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
        node = nullptr;
    }
}


/*
     2. ASSIGNMENT COMPARE OPERATORS

 */

// a. The assignment operator (=) to assign one tree to another.
BinTree &BinTree::operator=(const BinTree &rhs) {
    // first checks for self-assignment
    if (this != &rhs) { // tree does not copy itself
        // empty current tree
        makeEmpty(root);
        root = copyTree(rhs.root);
    }
    return *this;
}

// b. The equality and inequality operator (==)
// Define two trees to be equal if they have the same data and structure.
bool BinTree::operator==(const BinTree &rhs) const {
    // helper method to compare structure and data
    return compareTrees(root, rhs.root);
}

// b. The equality and inequality operator (!=)
// Define two trees to be equal if they have the same data and structure.
bool BinTree::operator!=(const BinTree &rhs) const {
    return !(*this == rhs);
}

// 2. PRIVATE HELPER
bool BinTree::compareTrees(Node *node1, Node *node2) const {
    if (node1 == nullptr && node2 == nullptr) {
        return true; // both tree empty
    }
    if (node1 == nullptr || node2 == nullptr) {
        return false;  // only one tree empty
    }
    if (node1->data != node2->data) {
        return false;
    }
    // check subtrees
    return compareTrees(node1->left, node2->left) && compareTrees(node1->right, node2->right);
}


/*
    3. PRINT / DISPLAY

 */

// (a) overload << to display the tree using inorder traversal (friend method)
ostream &operator<<(ostream &output, const BinTree &tree) {
    // allow easy printing of tree in-order
    tree.inorderTraversal(output, tree.root);
    return output;
}

// (b) displaySideways to display the tree sideways, as if it has been
// rotated counterclockwise by 90 degree.
void BinTree::displaySideways() const {
    // rightmost nodes printed first, root, Left
    displaySidewaysHelper(root, 0);
}

// (c) displayTree  to display the tree traditionally, with prefix of Root, L---, R---
void BinTree::displayTree() const {
    displayTreeHelper(root, "Root");
}

// 3. HELPER
void BinTree::inorderTraversal(ostream &output, Node *node) const{
    // L to root to R
    if (node != nullptr) {
        inorderTraversal(output, node->left);
        output << node->data << " ";
        inorderTraversal(output, node->right);
    }
}

void BinTree::displaySidewaysHelper(Node *node, int level) const {
    // first print  right subtree
    if (node == nullptr) {
        return;
    }

    displaySidewaysHelper(node->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "     ";
    }
    cout << node->data << endl;
    // then print left subtree
    displaySidewaysHelper(node->left, level + 1);
}

void BinTree::displayTreeHelper(Node *node, string prefix) const {
    // each node is prefixed with either L-- or R-- depending on
    // whether it's the left or right child.
    if (node != nullptr) {
        cout << prefix <<  " " << node->data << endl;
        displayTreeHelper(node->left, "L--" + prefix);
        displayTreeHelper(node->right, "R--" + prefix);
    }
}



// 4. PUBLIC METHODS

// a.
bool BinTree::isEmpty() const {
    return root == nullptr;
}

/* b.
 get the Node * of a given object in the tree (via pass-by-reference & parameter)
 and to report whether the object is found (true or false).

 The 2nd parameter in the function signature may be initially garbage.
If the object is found, it will point to the actual object in the tree.
 */
bool BinTree::retrieve(const string &value,Node *&result) const {
    // return a pointer to the node if found.
    return retrieveHelper(root, value, result);
}

// c. must preserve "binary search tree" property
bool BinTree::insert(const string &value) {
    return insertHelper(root, value);
}

/* d
   *** Height of a node: between node and its leaf (in its subtree), keep maximal
   values (longest path UPWARDS)

   SPECIAL INSTRUCTION: You must solve the problem for a general binary tree
   where data could be stored anywhere (e.g., tree T4 above).
   Use this height definition: the height of a node at a leaf is 1,
   height of a node at the next level is 2, and so on.  ***
   The height of a value not found is zero.

*/

int BinTree::getHeight(const string &value) const {
    return getHeightHelper(root, value);
}


// NOTE: if convert a tree to array, then back to tree, it might not be the same tree

/* e.
Fill array of data by in-order traversal while emptying the tree

 After the call to bstreeToArray, the tree in Figure 1 should be empty and the
 array should be filled with the following order.
        ---> and, eee, ff, iii, jj, m, not, ooo, pp, r, sssss, tttt, y, z
 */

void BinTree::bstreeToArray(string arr[]) {
    // TLDR:  converts the binary search tree
    // into an array of strings using inorder traversal,
    // and leaves the tree empty.
    int index = 0;
    index = bstreeToArrayHelper(root, arr, index);
    makeEmpty(root);
}

/* f
builds a balanced BinTree from a sorted array of node data
 string leaving the array filled with none.
 The root (recursively) is at (low+high)/2 where low is the lowest subscript of the array
 range and high is the highest.

 After the call to arrayToBSTree, the array should be filled with NULLs
 */
void BinTree::arrayToBSTree(string arr[]) {
    // TLDR:  root node is placed at the middle of the array,
    // and the left and right subtrees are recursively built
    // from the left and right halves of the array.
    root = arrayToBSTreeHelper(arr, 0, ARRAYSIZE - 1);
    // clear array when the tree is build
    for (int i = 0; i < ARRAYSIZE; ++i) {
        arr[i] = "";
    }

}



// Note: duplicate values aren't allowed
bool BinTree::insertHelper(Node *&node, const string &value) {
    // Initially starts at the root
    //  helper function recursively finds the appropriate spot
    //  in the tree and inserts the new node.
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


// NOTE: Follow special instructions: height starts at leaf node at 1
// height of a non-leaf node is the maximum height of its children plus 1.

int BinTree::getHeightHelper(Node *node, const string &value) const {
    if (node == nullptr) return 0;

    // node containing the value, return height 1 (leaf node)
    if (node->data == value) {
        return nodeHeight(node);
    }

    // recursive searching
    int leftHeight = getHeightHelper(node->left, value);
    int rightHeight = getHeightHelper(node->right, value);

    // value was found in either subtree, return the height (longest path upwards)
    if (leftHeight > 0 || rightHeight < 0) {
        return std::max(leftHeight, rightHeight) + 1;
    }

    //return max(leftHeight, rightHeight);
    return 0;
}

// todo: work on other helpers for part 4
int BinTree::bstreeToArrayHelper(Node *node, string arr[], int index) {
    if (node == nullptr) {
        return index;
    }

    // traverse the left st
    index = bstreeToArrayHelper(node->left, arr, index);

    // add node data to array
    arr[index++] = node->data;

    // traverse the right st
    index = bstreeToArrayHelper(node->left, arr, index);

    return index;
}

Node *BinTree::arrayToBSTreeHelper(string arr[], int high, int low) {
    if (low > high) {
        return nullptr;
    }

    // find middle value
    int mid = (low + high) / 2;

    // create new node w/ middle element
    Node *newNode = new Node(arr[mid]);

    // left and right st
    newNode->left = arrayToBSTreeHelper(arr, low, mid - 1);
    newNode->right = arrayToBSTreeHelper(arr, low + 1, mid);

    return newNode;
}

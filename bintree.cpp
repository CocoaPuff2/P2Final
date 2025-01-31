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
BinTree::BinTree(const BinTree& other) {
    root = copyTree(other.root);
};

Node* BinTree::copyTree(Node* node) {
    // recursively copy nodes
    if (node == nullptr) {
        return nullptr;
    }
    Node *newNode = new Node(node->data, nullptr, nullptr);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

// 1. destructor
BinTree::~BinTree() {
    makeEmpty(root);
}

void BinTree::makeEmpty(Node*& node) {
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
BinTree& BinTree::operator=(const BinTree& rhs) {
   if (this == &rhs) {
       return *this;
   }

   makeEmpty(root);
   root = copyTree(rhs.root);

   return *this;
}

// b. The equality and inequality operator (==)
// Define two trees to be equal if they have the same data and structure.
bool BinTree::operator==(const BinTree& rhs) const {
    // helper method to compare structure and data
    return compareTrees(root, rhs.root);
}

// b. The equality and inequality operator (!=)
bool BinTree::operator!=(const BinTree& rhs) const {
    return !(*this == rhs);
}

// 2. PRIVATE HELPER
bool BinTree::compareTrees(Node* node1, Node* node2) const {
    if (node1 == nullptr && node2 == nullptr) {
        return true; // both tree empty
    }
    if (node1 == nullptr || node2 == nullptr) {
        return false;  // only one tree empty
    }

    return (node1->data == node2->data) &&
        compareTrees(node1->left, node2->left) &&
            compareTrees(node1->right, node2->right);

}


/*
    3. PRINT / DISPLAY

 */

// (a) overload << to display the tree using inorder traversal (friend method)
ostream& operator<<(ostream& output, const BinTree& tree) {
    // allow easy printing of tree in-order
    tree.inorderTraversal(output, tree.root);

    return output;
}

void BinTree::inorderTraversal(ostream &output, Node *node) const {
    // L to root to R
    if (node != nullptr) {
        inorderTraversal(output, node->left);
        output << node->data << " ";
        inorderTraversal(output, node->right);
    }
}



// (c) displayTree  to display the tree traditionally, with prefix of Root, L---, R---
void BinTree::displayTree() const {
    displayTreeHelper(root, "Root: ", 0);
}

void BinTree::displayTreeHelper(Node* node, const string& prefix, int depth) const {
    // each node is prefixed with either L-- or R-- depending on
    // whether it's the left or right child.
    if (node == nullptr) return;
    cout << string(depth * 5, ' ') << prefix << node->data << endl;
    if (node->left != nullptr) {
        displayTreeHelper(node->left, "L--", depth + 1);
    }
    if (node->right != nullptr) {
        displayTreeHelper(node->right, "R--", depth + 1);
    }
}

// (b) displaySideways to display the tree sideways, as if it has been
// rotated counterclockwise by 90 degree.
void BinTree::displaySideways() const {
    // rightmost nodes printed first, root, Left
    displaySidewaysHelper(root, 0);
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



// 4. PUBLIC METHODS

// a.
bool BinTree::isEmpty() const {
    return root == nullptr;
}

/* b.
 get the Node * of a given object in the tree (via pass-by-reference & parameter)
 and report whether the object is found (true or false).

 The 2nd parameter in the function signature may be initially garbage.
If the object is found, it will point to the actual object in the tree.
 */
bool BinTree::retrieve(const string& value,Node*& result) const {
    // return a pointer to the node if found.
    return retrieveHelper(root, value, result);
}

bool BinTree::retrieveHelper(Node* node, const string& value, Node*& result) const {
    result = nullptr; // start as garbage
    Node* curr = root;

    while (curr != nullptr) {
        if (value == curr->data) {
            result = curr;
            return true;
        } else if (value < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}

// c. must preserve "binary search tree" property
/*
 * Note: should check input and see if the value is numeric.
 * Helper isNumeric: If yes numeric, then convert string to integer for comparison
 * If NOT numeric, continue comparing with string values (will be ASCII based comparison)
 */
bool BinTree::insert(const string& value) {
   //return insertHelper(root, value);
    // cout << "Starting insert for value: " << value << endl;
    return insertHelper(root, value);
    // bool inserted = insertHelper(root, value);
    // return inserted;
}

bool BinTree::isNumeric(const string& str) const {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);

}

// Note: duplicate values aren't allowed
// Insert Helper Method
bool BinTree::insertHelper(Node*& node, const string& value) {
    if (node == nullptr) {
        node = new Node(value, nullptr, nullptr);
        //cout << "Inserting new node:  " << value << endl;
        return true;
    }

    //cout << "Current node: " << node->data << endl;
    //cout << "Current value: " << value << endl;


    // if both values are numeric
    if (isNumeric(node->data) && isNumeric(value)) {
        int nodeInt = stoi(node->data);
        int valueInt = stoi(value);

        if (valueInt < nodeInt) {
            //cout << "Going left: " << valueInt << " < " << nodeInt << endl;
            return insertHelper(node->left, value);
        } else if (valueInt > nodeInt) {
            //cout << "Going right: " << valueInt << " < " << nodeInt << endl;
            return insertHelper(node->right, value);
        }
    } else {
        // if both values are strings, compare ASCII based
        if (value < node->data) {
            //cout << "Going left: " << value << " < " << node->data << endl;
            return insertHelper(node->left, value);
        } else if (value > node->data) {
           // cout << "Going right: " << value << " < " << node->data << endl;
            return insertHelper(node->right, value);
        }
    }
    return false; // no duplicates allowed
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

int BinTree::getHeight(const string& value) const {
    return getHeightHelper(root, value);
}

// NOTE: Follow special instructions: height starts at leaf node at 1
// height of a non-leaf node is the maximum height of its children plus 1.
int BinTree::getHeightHelper(Node *node, const string& value) const {
    if (node == nullptr) return 0;

    // node containing the value, return height 1 (leaf node)
    if (node->data == value) {  //  if node matches value
        return nodeHeight(node);
    }

    // recursive searching
    int leftHeight = getHeightHelper(node->left, value);
    int rightHeight = getHeightHelper(node->right, value);

    // value was found in either subtree, return the height (longest path upwards!)
    if (leftHeight > 0 || rightHeight > 0) {
        return std::max(leftHeight, rightHeight) + 1;
    }

    return 0;
}

// get height of given node
int BinTree::nodeHeight(Node* node) const {
    if (node == nullptr) return 0;
    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}



// NOTE: if convert a tree to array, then back to tree, it might not be the same tree

/* e.
Fill array of data by in-order traversal while emptying the tree

 After the call to bstreeToArray, the tree in Figure 1 should be empty and the
 array should be filled with the following order.
        ---> and, eee, ff, iii, jj, m, not, ooo, pp, r, sssss, tttt, y, z
 */

void BinTree::bstreeToArray(string arr[]) {
    // TLDR:  converts the binary search tree into an array of strings
    // using inorder traversal, and leaves the tree empty.
    int index = 0;
    index = bstreeToArrayHelper(root, arr, index);
    makeEmpty(root);
}

int BinTree::bstreeToArrayHelper(Node *node, string arr[], int index) {
    if (node == nullptr) {
        return index;
    }

    // traverse the left st
    index = bstreeToArrayHelper(node->left, arr, index);

    // add node data to array
    arr[index++] = node->data;

    // traverse the right st
    index = bstreeToArrayHelper(node->right, arr, index);

    return index;
}

/* f
builds a balanced BinTree from a sorted array of node data
 string leaving the array filled with none.
 The root (recursively) is at (low+high)/2 where low is the lowest subscript of the array
 range and high is the highest.

 After the call to arrayToBSTree, the array should be filled with NULLs
 */
void BinTree::arrayToBSTree(string arr[]) {
    // TLDR: root node is placed at the middle of the array, and the left and
    // right subtrees are recursively built from the left and right halves of the array.
    int n = 0;
    while (!arr[n].empty()) {
        n++;
    }
    root = arrayToBSTreeHelper(arr, 0, n - 1);
    // clear array when  tree is build
    for (int i = 0; i < n; ++i) {
        arr[i] = "";
    }

}

Node *BinTree::arrayToBSTreeHelper(string arr[], int start, int end) {

    if (start > end) {
        return nullptr;
    }

    // find middle value
    int mid = start + (end - start) / 2;

    //  new node w/ middle element
    Node *newNode = new Node(arr[mid]);

    // left and right st
    newNode->left = arrayToBSTreeHelper(arr, start, mid - 1);
    newNode->right = arrayToBSTreeHelper(arr, mid + 1, end);

    return newNode;
}

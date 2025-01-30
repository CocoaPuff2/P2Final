#include "bintree.h"
#include <iostream>
#include <cctype>

using namespace std;
/*

void buildTree(BinTree &T, const string values[], int size) {
    for (int i = 0; i < size; ++i) {
        bool success = T.insert(values[i]);
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
    // Input values to be inserted directly into the tree
    string values1[] = {"18", "3", "37", "11", "25", "21", "40", "8", "13", "1", "42", "15"};
    string values2[] = {"iii", "not", "tttt", "eee", "r", "not", "and", "jj", "r", "eee", "pp", "r", "sssss", "eee", "not", "tttt", "ooo", "ff", "m", "m", "y", "z"};
    string values3[] = {"b", "a", "c", "b", "a", "c"};
    string values4[] = {"c", "b", "a"};

    // Test the manual input method for each set of values
    BinTree filetree;

    // First set of values
    cout << "Building tree with first set of values: " << endl;
    buildTree(filetree, values1, sizeof(values1)/sizeof(values1[0]));
    cout << "Sideway print: " << endl;
    filetree.displaySideways();
    cout << "Display tree: " << endl;
    filetree.displayTree();

    // Second set of values
    cout << "Building tree with second set of values: " << endl;
    BinTree filetree2;
    buildTree(filetree2, values2, sizeof(values2)/sizeof(values2[0]));
    cout << "Sideway print: " << endl;
    filetree2.displaySideways();
    cout << "Display tree: " << endl;
    filetree2.displayTree();

    // Third set of values
    cout << "Building tree with third set of values: " << endl;
    BinTree filetree3;
    buildTree(filetree3, values3, sizeof(values3)/sizeof(values3[0]));
    cout << "Sideway print: " << endl;
    filetree3.displaySideways();
    cout << "Display tree: " << endl;
    filetree3.displayTree();

    // Fourth set of values
    cout << "Building tree with fourth set of values: " << endl;
    BinTree filetree4;
    buildTree(filetree4, values4, sizeof(values4)/sizeof(values4[0]));
    cout << "Sideway print: " << endl;
    filetree4.displaySideways();
    cout << "Display tree: " << endl;
    filetree4.displayTree();

    return 0;
}
*/
#include <iostream>
#include "bst.h"

using namespace std;
using namespace bst;

void bst_callback(const Node* node) {
    cout << "(key: " << node->key << "," << "value: " << node->value << ")" << endl;

}

int main() {
    Node* root = NULL;
    int keys[] = { 45, 53, 9, 17, 3, 54, 51 };
    for (int i = 0; i < 7; ++i) {
        insert_key(root, keys[i], i);
    }
    cout << "IN-ORDER" << endl;
    traverse_tree(root, &bst_callback);

    cout << "PRE-ORDER" << endl;
    traverse_tree(root, &bst_callback, PREORDER);

    cout << "POST-ORDER" << endl;
    traverse_tree(root, &bst_callback, POSTORDER);

    clear_tree(root);

    return 0;
}

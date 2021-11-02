#pragma once

namespace bst
{
    struct Node {
        int key;
        int value;
        Node* left;
        Node* right;
    };
    enum TRAVERSAL_MODE { INORDER, PREORDER, POSTORDER };

    const Node* search_key(int key, const Node* node);
    void insert_key(Node*& root, int key, int value);
    void clear_tree(Node*& root);
    void traverse_tree(const Node* root, void (*callback)(const Node*), TRAVERSAL_MODE mode = INORDER);
}

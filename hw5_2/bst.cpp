#include <iostream>
#include "bst.h"

namespace bst
{
    const Node* search_key(int key, const Node* node) {
        if (node == NULL) {
            return node;
        }

        else if (node->key) {
            return node;
        }
        else if (key < node->key) {
            return search_key(key, node->left);
        }
        else {
            return search_key(key, node->right);
        }
    }

    void insert_key(Node*& root, int key, int value) {
        if (root == NULL) {
            root = new Node{ key, value, NULL, NULL };
        }
        else if (key < root->key) {
            insert_key(root->left, key, value);
        }
        else if (key > root->key) {
            insert_key(root->right, key, value);
        }
    }

    void clear_tree(Node*& root) {
        if (root != NULL) {
            clear_tree(root->left);
            clear_tree(root->right);
            delete root;
        }
    }

    void traverse_tree_inorder(const Node* root, void (*callback)(const Node*)) {
        if (root == NULL) {
            return;
        }
        traverse_tree_inorder(root->left, callback);
        callback(root);
        traverse_tree_inorder(root->right, callback);
    }

    void traverse_tree_preorder(const Node* root, void (*callback)(const Node*)) {
        if (root == NULL) {
            return;
        }
        callback(root);
        traverse_tree_preorder(root->left, callback);
        traverse_tree_preorder(root->right, callback);
    }

    void traverse_tree_postorder(const Node* root, void (*callback)(const Node*)) {
        if (root == NULL) {
            return;
        }
        traverse_tree_postorder(root->left, callback);
        traverse_tree_postorder(root->right, callback);
        callback(root);
    }

    void traverse_tree(const Node* root, void(*callback)(const Node*), TRAVERSAL_MODE mode) {
        switch (mode) {
        case INORDER:
            traverse_tree_inorder(root, callback);
            break;
        case PREORDER:
            traverse_tree_preorder(root, callback);
            break;
        case POSTORDER:
            traverse_tree_postorder(root, callback);
            break;
        default:
            std::cerr << "Error in traversal mode.\n";
            break;
        }
    }
}

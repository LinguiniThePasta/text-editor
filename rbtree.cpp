//
// Created by linguinithepasta on 4/14/24.
//

#include "rbtree.h"
rbTree::rbTree() {
    rootNode = nullptr;
}

node* rbTree::rotateLeft(node* root) {
    // Implement left rotation logic here
    return root;
}

node* rbTree::rotateRight(node* root) {
    // Implement right rotation logic here
    return root;
}

void rbTree::fixViolationInsert(node* root, node* ptr) {
    // Fix Red-Black Tree violations after insertion
}

void rbTree::fixViolationDelete(node* root, node* ptr) {
    // Fix Red-Black Tree violations after deletion
}

node* rbTree::insertNode(node* root, node* ptr) {
    if (root == nullptr) {
        // New root node
        ptr->color = Color::Black;
        return ptr;
    }

    // ... (perform regular BST insertion) ...

    // Fix Red-Black Tree violations
    fixViolationInsert(root, ptr);

    return root;
}

node* rbTree::deleteNode(node* root, node* ptr) {
    // ... (perform regular BST deletion) ...

    // Fix Red-Black Tree violations
    fixViolationDelete(root, ptr);

    return root;
}

void rbTree::changeColor(node* nodeToBeChanged, Color col) {
    // Change the color of the node to the desired color
    // ...
}
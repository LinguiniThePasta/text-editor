#include <vector>
#include <string>
#include "PieceTree.h"



namespace PieceTree {
    node *RedBlackTree::getRoot() {
        return this->rootNode;
    }
    node *RedBlackTree::getLeft() {
        return nullptr;
    }
    node *RedBlackTree::getRight() {
        return nullptr;
    }
    bool RedBlackTree::isEmpty() {
        return true;
    }
    pieceTable RedBlackTree::getStringTable() {
        return this->stringTable;
    }
    RedBlackTree *RedBlackTree::buildTree(buffer) {
        return nullptr;
    }
    void RedBlackTree::rotateLeft(node *ptr) {
        node *y = ptr->right;
        ptr->right = y->left;
        y->left->parent = ptr;
        y->parent = ptr->parent;

        if (ptr->parent == nullptr) {
            this->rootNode = y;
        } else {
            if (ptr == ptr->parent->left) {
                ptr->parent->left = y;
            }
            else {
                ptr->parent->right = y;
            }
        }
        y->left = ptr;
        ptr->parent = y;
   }
    void RedBlackTree::rotateRight(node *ptr) {
        node *y = ptr->left;
        ptr->left = y->right;
        y->right->parent = ptr;
        y->parent = ptr->parent;

        if (ptr->parent == nullptr) {
            this->rootNode = y;
        } else {
            if (ptr == ptr->parent->right) {
                ptr->parent->right = y;
            }
            else {
                ptr->parent->left = y;
            }
        }
        y->right = ptr;
        ptr->parent = y;
    }

    void RedBlackTree::fixViolationInsert(node* z) {
        while (z->parent->color == Color::Red) {
            if (z->parent == z->parent->parent->left) {
                node *y = z->parent->parent->right;
                if (y->color == Color::Red) {
                    z->parent->color = Color::Black;
                    y->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    rotateRight(z->parent->parent);
                }
            }
            else {
                node *y = z->parent->parent->left;
                if (y->color == Color::Red) {
                    z->parent->color = Color::Black;
                    y->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    rotateLeft(z->parent->parent);
                }
            }
            this->rootNode->color = Color::Black;
        }
    }

    void RedBlackTree::fixViolationDelete(node* root, node* ptr) {
    }

    void RedBlackTree::insertNode(node *z, int location) {
        node *y = nullptr;
        node *x = rootNode;
        int totalOffset = 0;
        int left = 0;
        //0 = left, 1 = middle, 2 = right
        while (x != nullptr) {
            y = x;
            //TODO: Define the abstraction!
            //means if z is smaller than x
            if (location < totalOffset + x->leftSubtreeLength) {
                x = x->left;
                left = 0;
            } else if (location < totalOffset + x->leftSubtreeLength + x->stringLength) {
                x = x->left;
                left = 1;
            } else {
                x = x->right;
                totalOffset += x->leftSubtreeLength + x->stringLength;
                left = 2;
            }
        }
        //Now that you've figured out which node to insert it under, you have to check the buffers and split a buffer into two to add a thing there accordingly
        z->parent = y;
        if (y == nullptr) {
            rootNode = z;
        } else {
            if (left == 0) {
                y->left = z;
            } else if (left == 1) {
                splitNode(y);
            }else {
                y->right = z;
            }
        }
        z->left = nullptr;
        z->right = nullptr;
        z->color = Color::Red;
        fixViolationInsert(z);
    }

    void RedBlackTree::deleteNode(node* root, node* ptr) {
    }
    void RedBlackTree::changeColor(node* nodeToBeChanged, Color col) {
    }
    std::string RedBlackTree::readTree() {
    }


}

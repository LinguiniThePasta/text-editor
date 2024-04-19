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

    void RedBlackTree::insertNode(node *z) {

        node *y = nullptr;
        node *x = rootNode;
        while (x != nullptr) {
            y = x;
            //TODO: Define the abstraction!
            //means if z is smaller than x
            if (!comp(z, x)) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == nullptr) {
            rootNode = z;
        } else {
            if (!comp(z, y)) {
                y->left = z;
            } else {
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

    int RedBlackTree::compareNodes(node *a, node *b) {
        //TODO: this is dummy code for the time being
        //return 1 if a should be on the right side of b and 0 otherwise
        buffer& bufferA = buffers[a->bufferIndex];
        buffer& bufferB = buffers[b->bufferIndex];

        // Compare the start positions of the nodes
        int startCompare = compareBufferPositions();
        if (startCompare != 0) {
            return startCompare;
        }

        // If start positions are equal, compare the end positions
        return compareBufferPositions(a->end, bufferA, b->end, bufferB);
    }
    int RedBlackTree::compareBufferPositions() {
        // Compare the line numbers first
        if (posA.index < posB.index) {
            return -1;
        } else if (posA.index > posB.index) {
            return 1;
        }

        // If line numbers are equal, compare the character offsets (remainders)
        if (posA.remainder < posB.remainder) {
            return -1;
        } else if (posA.remainder > posB.remainder) {
            return 1;
        }

        // Positions are equal
        return 0;
    }
}

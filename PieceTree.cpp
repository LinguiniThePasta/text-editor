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
    RedBlackTree *RedBlackTree::rotateLeft(node *root) {
        return nullptr;
    }
    RedBlackTree *RedBlackTree::rotateRight(node *root) {
        return nullptr;
    }
    RedBlackTree * RedBlackTree::fixViolationInsert(node* root, node* ptr) {
        return nullptr;
    }
    RedBlackTree * RedBlackTree::fixViolationDelete(node* root, node* ptr) {
        return nullptr;
    }
    RedBlackTree * RedBlackTree::insertNode(node *insertLocation, node *newNode) {
        if (insertLocation == nullptr) {
            this->rootNode = newNode;
            newNode->color = Color::Black;
            return this;
        }
        char left = 1;
        if (insertLocation->leftSubtreeLfcnt >= newNode->leftSubtreeLfcnt) {
            insertLocation->left = newNode;
        } else {
            insertLocation->right = newNode;
            left = 0;
        }
        if (insertLocation->color == Color::Black) {
            return this;
        }

        node *uncle = nullptr;
        //if parent is red, check uncle
        if (insertLocation != this->rootNode) {
            if (insertLocation == insertLocation->parent->left) {
                //uncle is the right child
                uncle = insertLocation->parent->right;
            } else {
                //uncle is the left child
                uncle = insertLocation->parent->left;
            }
        }
        if (uncle == nullptr || uncle->color == Color::Black) {
            //TODO: I'm pretty sure this is wrong but we gotta make sure
            //TODO: I think you need to bubble this up
            if (!left) {
                if (insertLocation == insertLocation->parent->left) {
                    //uncle is the right child
                    node *newParent = rotateRight(insertLocation);
                    node *newGrandparent = rotateRight(newNode->parent);
                    newGrandparent->color = Color::Red;
                    insertLocation->color = Color::Black;
                } else {
                    //uncle is the left child
                    node *newGrandparent = rotateRight(insertLocation->parent);
                    newGrandparent->color = Color::Red;
                    insertLocation->color = Color::Black;
                }
            } else {
                if (insertLocation == insertLocation->parent->right) {
                    //uncle is the left child
                    node *newParent = rotateLeft(insertLocation);
                    node *newGrandparent = rotateLeft(newNode->parent);
                    newGrandparent->color = Color::Red;
                    insertLocation->color = Color::Black;
                } else {
                    //uncle is the right child
                    node *newGrandparent = rotateLeft(insertLocation->parent);
                    newGrandparent->color = Color::Red;
                    insertLocation->color = Color::Black;
                }
            }
        } else if (uncle->color == Color::Red) {
            // if uncle and parent are both red, flip uncle, parent, and grandparent colors

            //TODO: I think you need to bubble this up
            uncle->color = Color::Black;
            insertLocation->color = Color::Black;
            if (insertLocation->parent != this->rootNode) {
                insertLocation->parent->color = Color::Red;
            }
        }


        return this;
    }
    RedBlackTree * RedBlackTree::deleteNode(node* root, node* ptr) {
        return nullptr;
    }
    RedBlackTree * RedBlackTree::changeColor(node* nodeToBeChanged, Color col) {
        return nullptr;
    }
    std::string RedBlackTree::readTree() {
        return nullptr;
    }
}

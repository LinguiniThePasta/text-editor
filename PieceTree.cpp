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
    RedBlackTree * RedBlackTree::insertNode(node* ptr) {
        this->rootNode = ptr;
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

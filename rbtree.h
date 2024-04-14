//
// Created by linguinithepasta on 4/14/24.
//

#ifndef TEXT_EDITOR_RBTREE_H
#define TEXT_EDITOR_RBTREE_H

#include <vector>
#include <string>
enum class Color { Red, Black };




typedef struct buffer {
    std::string val;
    std::vector<int> line_starts;
} buffer;

struct bufferPosition {
    int index; // index in buffer.line_starts
    int remainder;
};
struct node {
    int bufferIndex; //index in buffer
    bufferPosition start; //start offset in buffers[bufferIndex]
    bufferPosition end; // end offset in buffers[bufferIndex]

    int leftSubtreeLength; // number of
    int leftSubtreeLfcnt; //left subtree line break count

    node* left;
    node* right;
    node* parent;

    std::vector<int> lineStarts;
    Color color;
};

class rbTree {
public:
    node* getRoot();
    node* getLeft();
    node* getRight();
    bool isEmpty();
private:
    rbTree();

    node* rootNode;
    static node* rotateLeft(node* root);
    static node* rotateRight(node* root);
    static void fixViolationInsert(node* root, node* ptr);
    static void fixViolationDelete(node* root, node* ptr);
    static node* insertNode(node* root, node* ptr);
    static node* deleteNode(node* root, node* ptr);
    static void changeColor(node* nodeToBeChanged, Color col);
};


#endif //TEXT_EDITOR_RBTREE_H

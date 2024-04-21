//
// Created by linguinithepasta on 4/14/24.
//

#ifndef TEXT_EDITOR_PIECETREE_H
#define TEXT_EDITOR_PIECETREE_H

#include <vector>
#include <string>

namespace PieceTree {
    enum class Color {
        Red, Black
    };

    struct buffer {
        std::string val; // this is what the buffer actually contains
        std::vector<int> lineStarts; // this is where all of the new lines are.
    };
    struct pieceTable {
        std::vector<buffer> textBuffer; // this one is where the old text go
        std::vector<buffer> editBuffer; // this one is where the edits go
    };
    struct bufferPosition {
        int index; // index in buffer.lineStarts
        int remainder; // offset in buffer.lineStarts[index]
        //to get the starting character, you would find the line in val based on lineStarts, and then add remainder to it
        char textOrEdit; //1 means text, 0 means edit
    };
    struct node {
        int bufferIndex; //index in buffer
        bufferPosition start; //start offset in buffers[bufferIndex]
        bufferPosition end; // end offset in buffers[bufferIndex]

        int leftSubtreeLength; // text length not including current node
        int stringLength;
        int leftSubtreeLfcnt; //left subtree line break count

        node *left;
        node *right;
        node *parent;
        Color color;
    };

    class RedBlackTree {
    public:
        RedBlackTree() : rootNode{nullptr} {
            stringTable.textBuffer = {}; // empty vector
            stringTable.editBuffer = {}; // empty vector
        }

        node *getRoot();

        node *getLeft();

        node *getRight();

        bool isEmpty();

        pieceTable getStringTable();

        void insertNode(node *newNode, int location);

        void deleteNode(node *root, node *ptr);

        int compareNodes(node *a, node *b);
    private:
        node *rootNode;
        pieceTable stringTable;


        RedBlackTree *buildTree(buffer);

        void rotateLeft(node *ptr);

        void rotateRight(node *ptr);

        void fixViolationInsert(node *ptr);

        void fixViolationDelete(node *root, node *ptr);

        void changeColor(node *nodeToBeChanged, Color col);

        std::string readTree();

        int compareBufferPositions();

        int compareBufferPositions(bufferPosition startA, buffer bufferA, bufferPosition startB, buffer &bufferB);
    };

    class EditInterface {
    public:

    private:
        RedBlackTree *redBlackTree;

        RedBlackTree *insertText(int lineNumber, int offset);

        RedBlackTree *deleteText(int lineNumber, int offset);
    };
}


#endif //TEXT_EDITOR_PIECETREE_H

//
// Created by linguinithepasta on 4/14/24.
//

#ifndef TEXT_EDITOR_REDBLACKTREETEST_H
#define TEXT_EDITOR_REDBLACKTREETEST_H
#include "PieceTree.h"
#include "gtest/gtest.h"

class RedBlackTreeTest : public ::testing::Test {
protected:
    PieceTree::RedBlackTree *tree; // Declare a Red-Black Tree instance for testing

    void SetUp() override {
        // Add setup code here if needed
        // e.g., populate the tree with initial values
        tree = new PieceTree::RedBlackTree();
    }

    void TearDown() override {
        // Add teardown code here if needed
        // e.g., clear the tree
    }
};


#endif //TEXT_EDITOR_REDBLACKTREETEST_H

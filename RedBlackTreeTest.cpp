//
// Created by linguinithepasta on 4/14/24.
//

#include "RedBlackTreeTest.h"

TEST_F(RedBlackTreeTest, InsertNode) {
    // Test inserting elements into the tree
    // TODO: Add test for more than 1 insert
    tree->getStringTable().textBuffer.push_back({"abc", {0}});
    PieceTree::node n = {
            0,
            {0, 0},
            {0,2},
            0,
            0,
            nullptr,
            nullptr,
            nullptr,
            PieceTree::Color::Red
    };
    tree->insertNode(&n);
    ASSERT_EQ(tree->getRoot(), &n);
}
TEST_F(RedBlackTreeTest, DeleteNode) {
    // Test deleting elements from the tree
    ASSERT_EQ(tree->getRoot(), nullptr);
}
TEST_F(RedBlackTreeTest, GetRoot) {
    // Test Getting the root of the tree
    // TODO: Add test for more than 1 insert
    ASSERT_EQ(tree->getRoot(), nullptr);
    tree->getStringTable().textBuffer.push_back({"abc", {0}});
    PieceTree::node n = {
            0,
            {0, 0},
            {0,2},
            0,
            0,
            nullptr,
            nullptr,
            nullptr,
            PieceTree::Color::Red
    };
    tree->insertNode(&n);
    ASSERT_EQ(tree->getRoot(), &n);
}
TEST_F(RedBlackTreeTest, GetLeft) {
    // Test getting the left element of a node
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, GetRight) {
    // Test getting the right element of a node
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, IsEmpty) {
    // Test if check for empty tree is correct
    ASSERT_EQ(tree->isEmpty(), true);

    tree->getStringTable().textBuffer.push_back({"abc", {0}});
    PieceTree::node n = {
            0,
            {0, 0},
            {0,2},
            0,
            0,
            nullptr,
            nullptr,
            nullptr,
            PieceTree::Color::Red
    };
    tree->insertNode(&n);
    ASSERT_EQ(tree->isEmpty(), false);
}
//TEST_F(RedBlackTreeTest, RotationR) {
//    // Test left rotate
//    ASSERT_EQ(1, 1);
//}
//TEST_F(RedBlackTreeTest, RotationL) {
//    // Test right rotate
//    ASSERT_EQ(1, 1);
//}
//TEST_F(RedBlackTreeTest, ColorChange) {
//    // Test changing the color of a node
//    ASSERT_EQ(1, 1);
//}
TEST_F(RedBlackTreeTest, ReadTree) {
    // Test reading the tree to get a string
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, EmptyOnInitialization) {
    // Test making sure that the tree is empty at beginning
    ASSERT_NE(tree, nullptr);
    ASSERT_EQ(tree->getRoot(), nullptr);
    ASSERT_EQ(tree->getStringTable().textBuffer.size(), 0);
    ASSERT_EQ(tree->getStringTable().editBuffer.size(), 0);
}
TEST_F(RedBlackTreeTest, InsertsCorrectNumberOfNodes) {
    // Test if the tree is inserting the correct number of nodes
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, NewNodesPointsToEditBuffer) {
    // Test if the new nodes are added to the edit buffer
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, LineStartsAtCorrectIndex) {
    // Test if the lines start at the correct index and offset
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, CorrectLeftSubtreeLength) {
    // Test if the left subtree length is correct
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, CorrectLeftSubtreeLFCnt) {
    // Test if the left subtree line break count is correct
    ASSERT_EQ(1, 1);
}
TEST_F(RedBlackTreeTest, BufferPositionIsCorrect) {
    // Test if the buffer position of a node is correct
    ASSERT_EQ(1, 1);
}
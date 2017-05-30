/*
 * test_mytree.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mytree.h"

TEST(mytreetest, construct) {
    EXPECT_TRUE(construct(NULL, NULL, 0) == NULL);
    int preOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    EXPECT_TRUE(root != NULL);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(2, root->mLeft->mValue);
    EXPECT_EQ(4, root->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, root->mLeft->mRight);
    EXPECT_EQ(NULL, root->mLeft->mLeft->mLeft);
    EXPECT_EQ(7, root->mLeft->mLeft->mRight->mValue);
    EXPECT_EQ(NULL, root->mLeft->mLeft->mRight->mLeft);
    EXPECT_EQ(NULL, root->mLeft->mLeft->mRight->mRight);
    EXPECT_EQ(3, root->mRight->mValue);
    EXPECT_EQ(5, root->mRight->mLeft->mValue);
    EXPECT_EQ(6, root->mRight->mRight->mValue);
    EXPECT_EQ(NULL, root->mRight->mLeft->mLeft);
    EXPECT_EQ(NULL, root->mRight->mLeft->mRight);
    EXPECT_EQ(8, root->mRight->mRight->mLeft->mValue);
    EXPECT_EQ(NULL, root->mRight->mRight->mLeft->mLeft);
    EXPECT_EQ(NULL, root->mRight->mRight->mLeft->mRight);
    destoryTree(root);

    int preOrder2[] = { 1, 2, 3, 4 };
    int inOrder2[] = { 4, 3, 2, 1 };
    BinaryTreeNode *root2 = construct(preOrder2, inOrder2,
            sizeof(preOrder2) / sizeof(preOrder2[0]));
    EXPECT_TRUE(root2 != NULL);
    EXPECT_EQ(1, root2->mValue);
    EXPECT_EQ(NULL, root2->mRight);
    EXPECT_EQ(2, root2->mLeft->mValue);
    EXPECT_EQ(NULL, root2->mLeft->mRight);
    EXPECT_EQ(3, root2->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, root2->mLeft->mLeft->mRight);
    EXPECT_EQ(4, root2->mLeft->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, root2->mLeft->mLeft->mLeft->mLeft);
    EXPECT_EQ(NULL, root2->mLeft->mLeft->mLeft->mRight);
    destoryTree(root2);

    int preOrder3[] = { 1 };
    int inOrder3[] = { 1 };
    BinaryTreeNode *root3 = construct(preOrder3, inOrder3,
            sizeof(preOrder3) / sizeof(preOrder3[0]));
    EXPECT_TRUE(root3 != NULL);
    EXPECT_EQ(1, root3->mValue);
    EXPECT_EQ(NULL, root3->mRight);
    EXPECT_EQ(NULL, root2->mLeft);
    destoryTree(root3);

    int preOrder4[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inOrder4[] = { 4, 7, 2, 1, 5, 3, 9, 6 };
    BinaryTreeNode *root4 = NULL;
    try {
        root4 = construct(preOrder4, inOrder4,
                sizeof(preOrder4) / sizeof(preOrder4[0]));
        ADD_FAILURE();
    } catch (std::exception& e) {
    }
    if (root4 != NULL) {
        destoryTree(root4);
    }
}


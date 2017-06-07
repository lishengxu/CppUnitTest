/*
 * test_mytree.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mytree.h"
#include "common.h"

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

TEST(mytreetest, preOrderTraversalRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 3, 8, 10, 6 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    preOrderTraversalRecursive(root, pOut);

    EXPECT_EQ(10, pOut->size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(preOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, preOrderTraversalNonNonRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 3, 8, 10, 6 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    preOrderTraversalNonRecursive(root, pOut);

    EXPECT_EQ(10, pOut->size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(preOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, inOrderTraversalRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 3, 8, 10, 6 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    inOrderTraversalRecursive(root, pOut);

    EXPECT_EQ(10, pOut->size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(inOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, inOrderTraversalNonRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 3, 8, 10, 6 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    inOrderTraversalNonRecursive(root, pOut);

    EXPECT_EQ(10, pOut->size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(inOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, posOrderTraversalRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 3, 8, 10, 6 };
    int posOrder[] = { 7, 4, 2, 5, 9, 10, 8, 6, 3, 1 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    posOrderTraversalRecursive(root, pOut);

    EXPECT_EQ(10, pOut->size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(posOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, posOrderTraversalNonRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 3, 8, 10, 6 };
    int posOrder[] = { 7, 4, 2, 5, 9, 10, 8, 6, 3, 1 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    posOrderTraversalNonRecursive(root, pOut);

    EXPECT_EQ(10, pOut->size());
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(posOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, levelTraversal) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 6 };
    int expectOrder[] = { 1, 2, 3, 4, 9, 6, 7, 5, 11, 8, 10 };
    int length = sizeof(preOrder) / sizeof(preOrder[0]);
    BinaryTreeNode *root = construct(preOrder, inOrder, length);
    std::vector<int> *pOut = new std::vector<int>();
    levelTraversal(root, pOut);

    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(expectOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, isSequeueOfPosOrderTraversalBST) {
    int posOrder1[] = { 1 };
    int posOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int posOrder3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int posOrder4[] = { 5, 7, 6, 9, 11, 10, 8 };
    int posOrder5[] = { 1, 3, 2, 5, 7, 6, 4, 9, 11, 10, 13, 15, 14, 12, 8 };
    int posOrderError[] = { 7, 4, 6, 5 };
    int posOrder6[] = { 1, 2, 3, 5, 8, 9, 7, 6, 4, 12, 11, 14, 17, 16, 15, 19,
            20, 18, 13, 10 };
    EXPECT_EQ(false, isSequeueOfPosOrderTraversalBST(NULL, 0));
    EXPECT_EQ(false,
            isSequeueOfPosOrderTraversalBST(posOrderError, LENGTH(posOrderError)));
    EXPECT_EQ(true,
            isSequeueOfPosOrderTraversalBST(posOrder1, LENGTH(posOrder1)));
    EXPECT_EQ(true,
            isSequeueOfPosOrderTraversalBST(posOrder2, LENGTH(posOrder2)));
    EXPECT_EQ(true,
            isSequeueOfPosOrderTraversalBST(posOrder3, LENGTH(posOrder3)));
    EXPECT_EQ(true,
            isSequeueOfPosOrderTraversalBST(posOrder4, LENGTH(posOrder4)));
    EXPECT_EQ(true,
            isSequeueOfPosOrderTraversalBST(posOrder5, LENGTH(posOrder5)));
    EXPECT_EQ(true,
            isSequeueOfPosOrderTraversalBST(posOrder6, LENGTH(posOrder6)));
}

TEST(mytreetest, contain) {
    EXPECT_EQ(false, contain(NULL, NULL));
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 6 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));

    EXPECT_EQ(false, contain(NULL, root));
    EXPECT_EQ(false, contain(root, NULL));

    int preOrderChild1[] = { 9, 5, 12 };
    int inOrderChild1[] = { 5, 9, 12 };
    BinaryTreeNode *child1 = construct(preOrderChild1, inOrderChild1,
            LENGTH(preOrderChild1));
    EXPECT_EQ(false, contain(root, child1));

    int preOrderChild2[] = { 9, 5, 11 };
    int inOrderChild2[] = { 5, 9, 11 };
    BinaryTreeNode *child2 = construct(preOrderChild2, inOrderChild2,
            LENGTH(preOrderChild2));
    EXPECT_EQ(true, contain(root, child2));

    destoryTree(root);
    destoryTree(child1);
    destoryTree(child2);
}

TEST(mytreetest, getMirrorRecursive) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 6 };
    int expectPreOrderMirror[] = { 1, 3, 6, 8, 10, 9, 11, 5, 2, 4, 7 };
    int expectInOrderMirror[] = { 6, 10, 8, 3, 11, 9, 5, 1, 2, 7, 4 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));
    std::vector<int> *pOut = new std::vector<int>();

    getMirrorRecursive(root);

    preOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(expectPreOrderMirror[i], pOut->at(i)) << "is differ at index:"
                << i << std::endl;
    }
    pOut->clear();

    inOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(expectInOrderMirror[i], pOut->at(i)) << "is differ at index:"
                << i << std::endl;
    }
    pOut->clear();

    getMirrorRecursive(root);

    preOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(preOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    pOut->clear();

    inOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(inOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }

    destoryTree(root);
    delete pOut;
}

TEST(mytreetest, getMirror) {
    int preOrder[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 10 };
    int inOrder[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 6 };
    int expectPreOrderMirror[] = { 1, 3, 6, 8, 10, 9, 11, 5, 2, 4, 7 };
    int expectInOrderMirror[] = { 6, 10, 8, 3, 11, 9, 5, 1, 2, 7, 4 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));
    std::vector<int> *pOut = new std::vector<int>();

    getMirror(root);

    preOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(expectPreOrderMirror[i], pOut->at(i)) << "is differ at index:"
                << i << std::endl;
    }
    pOut->clear();

    inOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(expectInOrderMirror[i], pOut->at(i)) << "is differ at index:"
                << i << std::endl;
    }
    pOut->clear();

    getMirror(root);

    preOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(preOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }
    pOut->clear();

    inOrderTraversalNonRecursive(root, pOut);
    EXPECT_EQ(11, pOut->size());
    for (int i = 0; i < 11; ++i) {
        EXPECT_EQ(inOrder[i], pOut->at(i)) << "is differ at index:" << i
                << std::endl;
    }

    destoryTree(root);
    delete pOut;
}

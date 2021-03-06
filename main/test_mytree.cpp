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

TEST(mytreetest, isSequeueOfPreOrderTraversalBST) {
    int preOrder1[] = { 1 };
    int preOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int preOrder3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int preOrder4[] = { 8, 6, 5, 7, 10, 9, 11 };
    int preOrder5[] = { 8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13, 15 };
    int preOrderError[] = { 5, 6, 7, 4 };
    int preOrderError2[] = { 1, 2, 3, 5, 8, 9, 7, 6, 4, 12, 11, 14, 17, 16, 15,
            19, 20, 18, 13, 10 };
    EXPECT_EQ(false, isSequeueOfPreOrderTraversalBST(NULL, 0));
    EXPECT_EQ(false,
            isSequeueOfPreOrderTraversalBST(preOrderError, LENGTH(preOrderError)));
    EXPECT_EQ(true,
            isSequeueOfPreOrderTraversalBST(preOrder1, LENGTH(preOrder1)));
    EXPECT_EQ(true,
            isSequeueOfPreOrderTraversalBST(preOrder2, LENGTH(preOrder2)));
    EXPECT_EQ(true,
            isSequeueOfPreOrderTraversalBST(preOrder3, LENGTH(preOrder3)));
    EXPECT_EQ(true,
            isSequeueOfPreOrderTraversalBST(preOrder4, LENGTH(preOrder4)));
    EXPECT_EQ(true,
            isSequeueOfPreOrderTraversalBST(preOrder5, LENGTH(preOrder5)));
    EXPECT_EQ(false,
            isSequeueOfPreOrderTraversalBST(preOrderError2, LENGTH(preOrderError2)));
}

TEST(mytreetest, isAVL) {
    EXPECT_FALSE(isAVL(NULL));

    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));
    EXPECT_TRUE(isAVL(root));
    destoryTree(root);

    int preOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));
    EXPECT_FALSE(isAVL(root));
    destoryTree(root);

    int preOrder3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    root = construct(preOrder3, inOrder3, LENGTH(preOrder3));
    EXPECT_FALSE(isAVL(root));
    destoryTree(root);

    int preOrder4[] = { 1, 2, 4, 7, 12, 3, 9, 5, 11, 6, 8, 10, 13 };
    int inOrder4[] = { 4, 7, 2, 12, 1, 5, 9, 11, 3, 8, 10, 6, 13 };
    root = construct(preOrder4, inOrder4, LENGTH(preOrder4));
    EXPECT_TRUE(isAVL(root));
    destoryTree(root);

    int preOrder5[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 12, 10 };
    int inOrder5[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 12, 6 };
    root = construct(preOrder5, inOrder5, LENGTH(preOrder5));
    EXPECT_FALSE(isAVL(root));
    destoryTree(root);
}

TEST(mytreetest, findPath) {
    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));
    std::vector<int> *pOut = new std::vector<int>();
    findPath(root, 0, pOut);
    EXPECT_EQ(0, pOut->size());
    findPath(root, 1, pOut);
    EXPECT_EQ(1, pOut->size());
    int expect[] = { 1 };
    for (int i = 0; i < LENGTH(expect); ++i) {
        EXPECT_EQ(expect[i], pOut->at(i)) << "is differ at " << i << std::endl;
    }
    pOut->clear();

    int preOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    root = construct(preOrder1, inOrder1, LENGTH(preOrder1));
    findPath(root, 0, pOut);
    EXPECT_EQ(0, pOut->size());
    findPath(root, 3, pOut);
    EXPECT_EQ(0, pOut->size());
    findPath(root, 45, pOut);
    int expect1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < LENGTH(expect1); ++i) {
        EXPECT_EQ(expect1[i], pOut->at(i)) << "is differ at " << i << std::endl;
    }
    pOut->clear();

    int preOrder2[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 10 };
    int inOrder2[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 6, 10 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));

    findPath(root, 13, pOut);
    EXPECT_EQ(0, pOut->size());
    findPath(root, 18, pOut);
    int expect2[] = { 1, 3, 9, 5, 1, 3, 6, 8 };
    EXPECT_EQ(8, pOut->size());
    for (int i = 0; i < LENGTH(expect2); ++i) {
        EXPECT_EQ(expect2[i], pOut->at(i)) << "is differ at " << i << std::endl;
    }
}

TEST(mytreetest, getCommonAncestor) {
    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));
    BinaryTreeNode *pOne = root;
    BinaryTreeNode *pTwo = root;
    EXPECT_EQ(root, getCommonAncestor(root, pOne, pTwo));
    destoryTree(root);

    int preOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    root = construct(preOrder1, inOrder1, LENGTH(preOrder1));
    pOne = root->mLeft->mLeft->mLeft->mLeft->mLeft->mLeft->mLeft->mLeft;
    pTwo = root->mLeft->mLeft;
    EXPECT_EQ(pTwo, getCommonAncestor(root, pOne, pTwo));
    destoryTree(root);

    int preOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));
    pOne = root->mRight->mRight->mRight->mRight->mRight->mRight->mRight->mRight;
    pTwo = root->mRight->mRight;
    EXPECT_EQ(pTwo, getCommonAncestor(root, pOne, pTwo));
    destoryTree(root);

    int preOrder3[] = { 10, 6, 4, 8, 14, 12, 16 };
    int inOrder3[] = { 4, 6, 8, 10, 12, 14, 16 };
    root = construct(preOrder3, inOrder3, LENGTH(preOrder3));
    pOne = root->mLeft->mLeft;
    pTwo = root->mRight->mRight;
    EXPECT_EQ(root, getCommonAncestor(root, pOne, pTwo));
    destoryTree(root);

    int preOrder5[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 12, 10 };
    int inOrder5[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 12, 6 };
    root = construct(preOrder5, inOrder5, LENGTH(preOrder5));
    pOne = root->mRight->mLeft->mLeft;
    EXPECT_EQ(5, pOne->mValue);
    pTwo = root->mRight->mRight->mLeft->mRight;
    EXPECT_EQ(12, pTwo->mValue);
    EXPECT_EQ(root->mRight, getCommonAncestor(root, pOne, pTwo));
    EXPECT_EQ(root, getCommonAncestor(root, root->mLeft, pTwo));
    destoryTree(root);
}

TEST(mytreetest, getDepth) {
    EXPECT_EQ(0, getDepth(NULL));

    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));
    EXPECT_EQ(1, getDepth(root));
    destoryTree(root);

    int preOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));
    EXPECT_EQ(9, getDepth(root));
    destoryTree(root);

    int preOrder3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    root = construct(preOrder3, inOrder3, LENGTH(preOrder3));
    EXPECT_EQ(9, getDepth(root));
    destoryTree(root);

    int preOrder4[] = { 1, 2, 4, 7, 3, 9, 5, 11, 6, 8, 10 };
    int inOrder4[] = { 4, 7, 2, 1, 5, 9, 11, 3, 8, 10, 6 };
    root = construct(preOrder4, inOrder4, LENGTH(preOrder4));
    EXPECT_EQ(5, getDepth(root));

    destoryTree(root);
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

TEST(mytreetest, DISABLED_getMirrorRecursive) {
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

TEST(mytreetest, DISABLED_getMirror) {
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

static void destoryListTree(BinaryTreeNode *root) {
    if (root == NULL) {
        return;
    }
    BinaryTreeNode* pCur = root;
    destoryListTree(pCur->mRight);
    delete pCur;
    pCur = NULL;
}

TEST(mytreetest, convertBinaryTreeToDoubleLinkedList) {
    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));

    root = convertBinaryTreeToDoubleLinkedList(root);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);
    EXPECT_EQ(NULL, root->mRight);
    destoryListTree(root);

    int preOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    root = construct(preOrder1, inOrder1, LENGTH(preOrder1));

    root = convertBinaryTreeToDoubleLinkedList(root);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);

    BinaryTreeNode *pCur = root;
    BinaryTreeNode *pNext = pCur->mRight;
    for (int i = 2; i < 9; ++i) {
        EXPECT_EQ(i, pNext->mValue);
        EXPECT_EQ(pCur, pNext->mLeft);
        pCur = pNext;
        pNext = pCur->mRight;
    }
    EXPECT_EQ(9, pNext->mValue);
    EXPECT_EQ(NULL, pNext->mRight);
    destoryListTree(root);

    int preOrder2[] = { 10, 6, 4, 8, 14, 12, 16 };
    int inOrder2[] = { 4, 6, 8, 10, 12, 14, 16 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));

    root = convertBinaryTreeToDoubleLinkedList(root);
    EXPECT_EQ(4, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);

    pCur = root;
    pNext = pCur->mRight;
    for (int i = 2; i < 7; ++i) {
        EXPECT_EQ(inOrder2[i - 1], pNext->mValue);
        EXPECT_EQ(pCur, pNext->mLeft);
        pCur = pNext;
        pNext = pCur->mRight;
    }
    EXPECT_EQ(16, pNext->mValue);
    EXPECT_EQ(NULL, pNext->mRight);
    destoryListTree(root);
}

TEST(mytreetest, convertBinaryTreeToDoubleLinkedListRecursive) {
    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));

    root = convertBinaryTreeToDoubleLinkedListRecursive(root);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);
    EXPECT_EQ(NULL, root->mRight);
    destoryListTree(root);

    int preOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    root = construct(preOrder1, inOrder1, LENGTH(preOrder1));

    root = convertBinaryTreeToDoubleLinkedListRecursive(root);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);

    BinaryTreeNode *pCur = root;
    BinaryTreeNode *pNext = pCur->mRight;
    for (int i = 2; i < 9; ++i) {
        EXPECT_EQ(i, pNext->mValue);
        EXPECT_EQ(pCur, pNext->mLeft);
        pCur = pNext;
        pNext = pCur->mRight;
    }
    EXPECT_EQ(9, pNext->mValue);
    EXPECT_EQ(NULL, pNext->mRight);
    destoryListTree(root);

    int preOrder2[] = { 10, 6, 4, 8, 14, 12, 16 };
    int inOrder2[] = { 4, 6, 8, 10, 12, 14, 16 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));

    root = convertBinaryTreeToDoubleLinkedListRecursive(root);
    EXPECT_EQ(4, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);

    pCur = root;
    pNext = pCur->mRight;
    for (int i = 2; i < 7; ++i) {
        EXPECT_EQ(inOrder2[i - 1], pNext->mValue);
        EXPECT_EQ(pCur, pNext->mLeft);
        pCur = pNext;
        pNext = pCur->mRight;
    }
    EXPECT_EQ(16, pNext->mValue);
    EXPECT_EQ(NULL, pNext->mRight);
    destoryListTree(root);
}

TEST(mytreetest, convertBinaryTreeToDoubleLinkedListRecursiveAnother) {
    int preOrder[] = { 1 };
    int inOrder[] = { 1 };
    BinaryTreeNode *root = construct(preOrder, inOrder, LENGTH(preOrder));

    root = convertBinaryTreeToDoubleLinkedListRecursiveAnother(root);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);
    EXPECT_EQ(NULL, root->mRight);
    destoryListTree(root);

    int preOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inOrder1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    root = construct(preOrder1, inOrder1, LENGTH(preOrder1));

    root = convertBinaryTreeToDoubleLinkedListRecursiveAnother(root);
    EXPECT_EQ(1, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);

    BinaryTreeNode *pCur = root;
    BinaryTreeNode *pNext = pCur->mRight;
    for (int i = 2; i < 9; ++i) {
        EXPECT_EQ(i, pNext->mValue);
        EXPECT_EQ(pCur, pNext->mLeft);
        pCur = pNext;
        pNext = pCur->mRight;
    }
    EXPECT_EQ(9, pNext->mValue);
    EXPECT_EQ(NULL, pNext->mRight);
    destoryListTree(root);

    int preOrder2[] = { 10, 6, 4, 8, 14, 12, 16 };
    int inOrder2[] = { 4, 6, 8, 10, 12, 14, 16 };
    root = construct(preOrder2, inOrder2, LENGTH(preOrder2));

    root = convertBinaryTreeToDoubleLinkedListRecursiveAnother(root);
    EXPECT_EQ(4, root->mValue);
    EXPECT_EQ(NULL, root->mLeft);

    pCur = root;
    pNext = pCur->mRight;
    for (int i = 2; i < 7; ++i) {
        EXPECT_EQ(inOrder2[i - 1], pNext->mValue);
        EXPECT_EQ(pCur, pNext->mLeft);
        pCur = pNext;
        pNext = pCur->mRight;
    }
    EXPECT_EQ(16, pNext->mValue);
    EXPECT_EQ(NULL, pNext->mRight);
    destoryListTree(root);
}

/*
 * mytree.h
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#ifndef MYTREE_H_
#define MYTREE_H_
#include <vector>

struct BinaryTreeNode {
    int mValue;
    BinaryTreeNode *mLeft;
    BinaryTreeNode *mRight;
};

BinaryTreeNode* construct(const int* preOrder, const int* inOrder,
        const int length);

void preOrderTraversalRecursive(BinaryTreeNode *pHead, std::vector<int> *pOut =
        NULL);

void preOrderTraversalNonRecursive(BinaryTreeNode *pHead,
        std::vector<int> *pOut = NULL);

void inOrderTraversalRecursive(BinaryTreeNode *pHead, std::vector<int> *pOut =
        NULL);

void inOrderTraversalNonRecursive(BinaryTreeNode *pHead,
        std::vector<int> *pOut = NULL);

void posOrderTraversalRecursive(BinaryTreeNode *pHead, std::vector<int> *pOut =
        NULL);

void posOrderTraversalNonRecursive(BinaryTreeNode *pHead,
        std::vector<int> *pOut = NULL);

bool contain(BinaryTreeNode *pRoot, BinaryTreeNode *pChild);

void getMirrorRecursive(BinaryTreeNode *pNode);

void getMirror(BinaryTreeNode *pNode);

void destoryTree(BinaryTreeNode *root);
#endif /* MYTREE_H_ */

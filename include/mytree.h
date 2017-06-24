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

void levelTraversal(BinaryTreeNode *pHead, std::vector<int> *pOut = NULL);

bool isSequeueOfPosOrderTraversalBST(const int *array, int length);

bool isSequeueOfPreOrderTraversalBST(const int *array, int length);

bool isAVL(BinaryTreeNode *pRoot);

void findPath(BinaryTreeNode *pRoot, const int sum, std::vector<int> *pOut =
        NULL);

BinaryTreeNode* getCommonAncestor(BinaryTreeNode *pRoot, BinaryTreeNode *pOne,
        BinaryTreeNode *pTwo);

unsigned int getDepth(BinaryTreeNode *pRoot);

bool contain(BinaryTreeNode *pRoot, BinaryTreeNode *pChild);

void getMirrorRecursive(BinaryTreeNode *pNode);

void getMirror(BinaryTreeNode *pNode);

BinaryTreeNode* convertBinaryTreeToDoubleLinkedList(BinaryTreeNode *pRoot);

BinaryTreeNode* convertBinaryTreeToDoubleLinkedListRecursive(
        BinaryTreeNode *pRoot);

BinaryTreeNode* convertBinaryTreeToDoubleLinkedListRecursiveAnother(
        BinaryTreeNode *pRoot);

void destoryTree(BinaryTreeNode *root);
#endif /* MYTREE_H_ */

/*
 * mytree.h
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#ifndef MYTREE_H_
#define MYTREE_H_

struct BinaryTreeNode {
    int mValue;
    BinaryTreeNode *mLeft;
    BinaryTreeNode *mRight;
};

BinaryTreeNode* construct(const int* preOrder, const int* inOrder,
        const int length);

void destoryTree(BinaryTreeNode *root);
#endif /* MYTREE_H_ */

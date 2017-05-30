/*
 * mytree.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#include <stddef.h>
#include "mytree.h"
#include <exception>
#include <stdexcept>

BinaryTreeNode* construct(const int* preOrder, const int* inOrder,
        const int length) {
    if (preOrder == NULL || inOrder == NULL || length < 1) {
        return NULL;
    }
    BinaryTreeNode* pCur = new BinaryTreeNode();
    int value = *preOrder;
    pCur->mValue = value;
    int index = 0;
    while (index < length) {
        if (*(inOrder + index) == value) {
            break;
        }
        ++index;
    }
    if (index >= length) {
        std::logic_error ex("Invalid input: the inOrder can not find " + value);
        throw std::exception(ex);
    }
    pCur->mLeft = construct(preOrder + 1, inOrder, index);
    pCur->mRight = construct(preOrder + index + 1, inOrder + index + 1,
            length - index - 1);
    return pCur;
}

void destoryTree(BinaryTreeNode *root) {
    if (root == NULL) {
        return;
    }
    BinaryTreeNode* pCur = root;
    destoryTree(pCur->mLeft);
    destoryTree(pCur->mRight);
    delete pCur;
    pCur = NULL;
}

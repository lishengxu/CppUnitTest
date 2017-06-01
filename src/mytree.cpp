/*
 * mytree.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */
#include <stdio.h>
#include <stddef.h>
#include <exception>
#include <stdexcept>
#include <stack>
#include <utility>
#include "mytree.h"

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

void preOrderTraversalRecursive(BinaryTreeNode *pNode,
        std::vector<int> *pOut/*=NULL*/) {
    if (pNode == NULL) {
        return;
    }
    printf("%d\n", pNode->mValue);
    if (pOut != NULL) {
        pOut->push_back(pNode->mValue);
    }
    preOrderTraversalRecursive(pNode->mLeft, pOut);
    preOrderTraversalRecursive(pNode->mRight, pOut);
}

void preOrderTraversalNonRecursive(BinaryTreeNode *pHead,
        std::vector<int> *pOut/*=NULL*/) {
    if (pHead == NULL) {
        return;
    }
    std::stack<BinaryTreeNode*> stack;
    stack.push(pHead);

    while (!stack.empty()) {
        BinaryTreeNode* pCur = stack.top();
        stack.pop();
        printf("%d\n", pCur->mValue);
        if (pOut != NULL) {
            pOut->push_back(pCur->mValue);
        }
        if (pCur->mRight != NULL) {
            stack.push(pCur->mRight);
        }
        if (pCur->mLeft != NULL) {
            stack.push(pCur->mLeft);
        }
    }
}

void inOrderTraversalRecursive(BinaryTreeNode *pNode,
        std::vector<int> *pOut/*=NULL*/) {
    if (pNode == NULL) {
        return;
    }
    inOrderTraversalRecursive(pNode->mLeft, pOut);
    printf("%d\n", pNode->mValue);
    if (pOut != NULL) {
        pOut->push_back(pNode->mValue);
    }
    inOrderTraversalRecursive(pNode->mRight, pOut);
}

void inOrderTraversalNonRecursive(BinaryTreeNode *pHead,
        std::vector<int> *pOut/*=NULL*/) {
    if (pHead == NULL) {
        return;
    }
    std::stack<BinaryTreeNode*> stack;
    BinaryTreeNode* pCur = pHead;
    while (pCur != NULL || !stack.empty()) {
        if (pCur != NULL) {
            stack.push(pCur);
            pCur = pCur->mLeft;
        } else {
            pCur = stack.top();
            stack.pop();
            printf("%d\n", pCur->mValue);
            if (pOut != NULL) {
                pOut->push_back(pCur->mValue);
            }
            pCur = pCur->mRight;
        }
    }
}

void posOrderTraversalRecursive(BinaryTreeNode *pNode,
        std::vector<int> *pOut/*=NULL*/) {
    if (pNode == NULL) {
        return;
    }
    posOrderTraversalRecursive(pNode->mLeft, pOut);
    posOrderTraversalRecursive(pNode->mRight, pOut);
    printf("%d\n", pNode->mValue);
    if (pOut != NULL) {
        pOut->push_back(pNode->mValue);
    }
}

void posOrderTraversalNonRecursive(BinaryTreeNode *pHead,
        std::vector<int> *pOut/*=NULL*/) {
    if (pHead == NULL) {
        return;
    }
    std::stack<BinaryTreeNode*> stack;

    BinaryTreeNode* pCur = pHead;
    BinaryTreeNode *last = pHead;
    stack.push(pCur);
    while (!stack.empty()) {
        pCur = stack.top();
        if ((pCur->mLeft == NULL && pCur->mRight == NULL)
                || (pCur->mRight == NULL && last == pCur->mLeft)
                || last == pCur->mRight) {
            printf("%d\n", pCur->mValue);
            if (pOut != NULL) {
                pOut->push_back(pCur->mValue);
            }
            last = pCur;
            stack.pop();
        } else {
            if (pCur->mRight != NULL) {
                stack.push(pCur->mRight);
            }
            if (pCur->mLeft != NULL) {
                stack.push(pCur->mLeft);
            }
        }
    }
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

/*
 * mytree.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */
#include <stdio.h>
#include <stddef.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <stack>
#include <queue>
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

static bool containChild(BinaryTreeNode *pRoot, BinaryTreeNode *pChild) {
    if (pChild == NULL) {
        return true;
    }
    if (pRoot == NULL) {
        return false;
    }

    if (pRoot->mValue == pChild->mValue) {
        return containChild(pRoot->mLeft, pChild->mRight)
                && containChild(pRoot->mRight, pChild->mRight);
    }
    return false;
}

void levelTraversal(BinaryTreeNode *pHead, std::vector<int> *pOut/*= NULL*/) {
    if (pHead == NULL) {
        return;
    }

    BinaryTreeNode *pCur = pHead;
    std::queue<BinaryTreeNode*> queue;
    queue.push(pCur);
    while (!queue.empty()) {
        BinaryTreeNode *pCur = queue.front();
        queue.pop();
        printf("%d\n", pCur->mValue);
        if (pOut != NULL) {
            pOut->push_back(pCur->mValue);
        }
        if (pCur->mLeft != NULL) {
            queue.push(pCur->mLeft);
        }
        if (pCur->mRight != NULL) {
            queue.push(pCur->mRight);
        }
    }
}

bool isSequeueOfPosOrderTraversalBST(const int *array, int length) {
    if (array == NULL || length < 1) {
        return false;
    }

    int root = array[length - 1];
    int leftIndex = 0;
    for (; leftIndex < length - 1; ++leftIndex) {
        if (array[leftIndex] > root) {
            break;
        }
    }

    int rightIndex = leftIndex;
    for (; rightIndex < length - 1; ++rightIndex) {
        if (array[rightIndex] < root) {
            break;
        }
    }
    if (rightIndex < length - 1) {
        return false;
    }

    bool leftFlag = true;
    if (leftIndex > 0) {
        leftFlag = isSequeueOfPosOrderTraversalBST(array, leftIndex);
    }
    bool rightFlag = true;
    if (leftIndex < length - 1) {
        rightFlag = isSequeueOfPosOrderTraversalBST(array + leftIndex,
                length - leftIndex - 1);
    }
    return leftFlag && rightFlag;
}

bool isSequeueOfPreOrderTraversalBST(const int *array, int length) {
    if (array == NULL || length < 1) {
        return false;
    }

    int value = array[0];
    int rightIndex = length - 1;
    for (/*NULL*/; rightIndex > 0; --rightIndex) {
        if (array[rightIndex] < value) {
            break;
        }
    }
    int leftIndex = rightIndex;
    for (/*NULL*/; leftIndex > 0; --leftIndex) {
        if (array[leftIndex] > value) {
            break;
        }
    }
    if (leftIndex > 0) {
        return false;
    }

    bool rightFlag = true;
    if (rightIndex < length - 1) {
        rightFlag = isSequeueOfPreOrderTraversalBST(array + rightIndex + 1,
                length - rightIndex - 1);
    }
    bool leftFlag = true;
    if (rightIndex > 0) {
        leftFlag = isSequeueOfPreOrderTraversalBST(array + 1, rightIndex);
    }
    return leftFlag && rightFlag;
}

static void printPath(std::vector<int> *stack, std::vector<int> *pOut = NULL) {
    for (std::vector<int>::const_iterator iter = stack->begin();
            iter != stack->end(); ++iter) {
        std::cout << (*iter) << std::endl;
        if (pOut != NULL) {
            pOut->push_back(*iter);
        }
    }
}

static void findPath(BinaryTreeNode *pNode, std::vector<int> *path,
        const int sum, std::vector<int> *pOut = NULL) {
    path->push_back(pNode->mValue);
    if (pNode->mLeft == NULL && pNode->mRight == NULL && pNode->mValue == sum) {
        printPath(path, pOut);
    }
    if (pNode->mLeft != NULL) {
        findPath(pNode->mLeft, path, sum - pNode->mValue, pOut);
    }
    if (pNode->mRight != NULL) {
        findPath(pNode->mRight, path, sum - pNode->mValue, pOut);
    }

    path->pop_back();
}

/**
 * 该函数是在二叉树中找到从根节点到叶节点的路径长度为指定值的路径。
 * 另外一个待实现的查找为在二叉树的任何节点到任何子节点的路径长度为指定值的路径。
 */
void findPath(BinaryTreeNode *pRoot, const int sum,
        std::vector<int> *pOut/*= NULL*/) {
    if (pRoot == NULL) {
        return;
    }

    std::vector<int> *path = new std::vector<int>();
    findPath(pRoot, path, sum, pOut);
    delete path;
}

bool contain(BinaryTreeNode *pRoot, BinaryTreeNode *pChild) {
    if (pRoot == NULL || pChild == NULL) {
        return false;
    }

    if (pRoot->mValue == pChild->mValue) {
        if (containChild(pRoot->mLeft, pChild->mLeft)
                && containChild(pRoot->mRight, pChild->mRight)) {
            return true;
        }
    }
    return contain(pRoot->mLeft, pChild) || contain(pRoot->mRight, pChild);
}

void getMirrorRecursive(BinaryTreeNode *pNode) {
    if (pNode == NULL) {
        return;
    }
    BinaryTreeNode *temp = pNode->mLeft;
    pNode->mLeft = pNode->mRight;
    pNode->mRight = temp;
    getMirrorRecursive(pNode->mLeft);
    getMirrorRecursive(pNode->mRight);
}

void getMirror(BinaryTreeNode *pNode) {
    if (pNode == NULL) {
        return;
    }

    std::stack<BinaryTreeNode*> stack;
    stack.push(pNode);
    while (!stack.empty()) {
        BinaryTreeNode *pCur = stack.top();
        stack.pop();
        BinaryTreeNode *temp = pCur->mLeft;
        pCur->mLeft = pCur->mRight;
        pCur->mRight = temp;
        if (pCur->mRight != NULL) {
            stack.push(pCur->mRight);
        }
        if (pCur->mLeft != NULL) {
            stack.push(pCur->mLeft);
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

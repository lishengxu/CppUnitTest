/*
 * mylist.cpp
 *
 *  Created on: May 28, 2017
 *      Author: lsx
 */
#include "stdio.h"
#include "mylist.h"

void addToTail(ListNode **pHead, int value) {
    if (pHead == NULL) {
        return;
    }
    ListNode *pNode = new ListNode();
    pNode->mNext = NULL;
    pNode->mValue = value;
    if (*pHead == NULL) {
        *pHead = pNode;
    } else {
        ListNode *pCur = *pHead;
        while (pCur->mNext != NULL) {
            pCur = pCur->mNext;
        }
        pCur->mNext = pNode;
    }
}

void removeNode(ListNode **pHead, int value) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }
    ListNode* pToDel = NULL;
    if ((*pHead)->mValue == value) {
        pToDel = *pHead;
        *pHead = (*pHead)->mNext;
    } else {
        ListNode* pCur = *pHead;
        while (pCur->mNext != NULL && pCur->mNext->mValue != value) {
            pCur = pCur->mNext;
        }
        if (pCur->mNext != NULL) {
            pToDel = pCur->mNext;
            pCur->mNext = pToDel->mNext;
        }
    }
    if (pToDel != NULL) {
        delete pToDel;
        pToDel = NULL;
    }
}

void deleteList(ListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }
    ListNode *pCur = *pHead;
    while (pCur != NULL) {
        ListNode *pToDel = pCur;
        pCur = pCur->mNext;
        delete pToDel;
        pToDel = NULL;
    }
    *pHead = NULL;
}

static void printList(ListNode *pListNode, bool forward,
        std::vector<int> *pOut) {
    if (pListNode != NULL) {
        if (forward) {
            printf("%d\n", pListNode->mValue);
            if (pOut != NULL) {
                pOut->push_back(pListNode->mValue);
            }
        }
        printList(pListNode->mNext, forward, pOut);
        if (!forward) {
            printf("%d\n", pListNode->mValue);
            if (pOut != NULL) {
                pOut->push_back(pListNode->mValue);
            }
        }
    }
}

static void printListReverseNonRecursive(ListNode *pListNode,
        std::vector<int> *pOut) {
    ListNode *pCur = pListNode;
    std::stack<ListNode*> nodes;
    while (pCur != NULL) {
        nodes.push(pCur);
        pCur = pCur->mNext;
    }
    while (!nodes.empty()) {
        pCur = nodes.top();
        nodes.pop();
        printf("%d\n", pCur->mValue);
        if (pOut != NULL) {
            pOut->push_back(pCur->mValue);
        }
    }
}

void printList(ListNode **pHead, bool forward,
        std::vector<int> *pOut/*=NULL*/) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }
    printList(*pHead, forward, pOut);
}

void printListReverse(ListNode **pHead, std::vector<int> *pOut/*=NULL*/) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }
    printListReverseNonRecursive(*pHead, pOut);
}

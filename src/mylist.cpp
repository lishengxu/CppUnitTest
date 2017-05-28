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


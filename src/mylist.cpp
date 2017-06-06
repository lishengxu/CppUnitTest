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

ListNode* findKNodeToTail(ListNode **pHead, unsigned int k) {
    if (pHead == NULL || *pHead == NULL || k == 0) {
        return NULL;
    }
    ListNode *pCur = *pHead;
    ListNode *pKNext = *pHead;
    unsigned int index = 1;
    while (pKNext != NULL && index < k) {
        ++index, pKNext = pKNext->mNext;
    }

    if (pKNext == NULL) {
        return NULL;
    }

    while (pKNext->mNext != NULL) {
        pKNext = pKNext->mNext;
        pCur = pCur->mNext;
    }
    return pCur;
}

ListNode* findMiddleNode(ListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }

    ListNode *pFirst = *pHead, *pSecond = *pHead;
    while (pSecond->mNext != NULL && pSecond->mNext->mNext != NULL) {
        pSecond = pSecond->mNext->mNext;
        pFirst = pFirst->mNext;
    }

    return pFirst;
}

ListNode* findEndNode(ListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }

    ListNode *pCur = *pHead;
    while (pCur->mNext != NULL) {
        pCur = pCur->mNext;
    }

    return pCur;
}

bool isCircleList(ListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return false;
    }

    ListNode *pFirst = *pHead, *pSecond = *pHead;
    while (pSecond->mNext != NULL && pSecond->mNext->mNext != NULL) {
        if (pSecond->mNext == pFirst || pSecond->mNext->mNext == pFirst) {
            return true;
        } else {
            pSecond = pSecond->mNext->mNext;
            pFirst = pFirst->mNext;
        }
    }

    return false;
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

void deleteNode(ListNode **pHead, ListNode *pToBeDeleted) {
    if (pHead == NULL || *pHead == NULL || pToBeDeleted == NULL) {
        return;
    }
    if (*pHead == pToBeDeleted) {
        *pHead = (*pHead)->mNext;
    } else {
        ListNode *pCur = *pHead;
        while (pCur->mNext != NULL && pCur->mNext != pToBeDeleted) {
            pCur = pCur->mNext;
        }
        if (pCur->mNext != NULL) {
            pCur->mNext = pCur->mNext->mNext;
        }
    }
    delete pToBeDeleted;
    pToBeDeleted = NULL;
}

/**
 * 即使无法处理尾部节点，尾部节点可以使用delteNode方法删除，由于出现删除尾部节点的概率为1/n，
 * 这样时间复杂度依然是o(1)
 */
void quickDeleteNode(ListNode **pHead, ListNode *pToBeDeleted) {
    if (pHead == NULL || *pHead == NULL || pToBeDeleted == NULL) {
        return;
    }

    if (*pHead == pToBeDeleted) {
        *pHead = (*pHead)->mNext;
    } else {
        ListNode *pNext = pToBeDeleted->mNext;
        if (pNext == NULL) {
            deleteNode(pHead, pToBeDeleted);
            return;
        } else {
            pToBeDeleted->mValue = pNext->mValue;
            pToBeDeleted->mNext = pNext->mNext;
            pToBeDeleted = pNext;
        }
    }

    delete pToBeDeleted;
    pToBeDeleted = NULL;
}

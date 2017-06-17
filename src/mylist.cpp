/*
 * mylist.cpp
 *
 *  Created on: May 28, 2017
 *      Author: lsx
 */
#include "stdio.h"
#include "mylist.h"

static ComplexListNode* cloneNodes(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }

    ComplexListNode *pNewHead = NULL;
    ComplexListNode *pNewCur = NULL;
    ComplexListNode *pCur = *pHead;
    while (pCur != NULL) {
        ComplexListNode *pNew = new ComplexListNode();
        pNew->mValue = pCur->mValue;
        pNew->mNext = pCur->mNext;
        pNew->mSibling = pCur->mSibling;
        if (pNewHead == NULL) {
            pNewHead = pNew;
        } else {
            pNewCur->mNext = pNew;
        }
        pNewCur = pNew;
        pCur = pCur->mNext;
    }
    return pNewHead;
}

static void cloneSibling(ComplexListNode **pHead, ComplexListNode **pNew) {
    if (pHead == NULL || *pHead == NULL || pNew == NULL || *pNew == NULL) {
        return;
    }
    ComplexListNode *pCur = *pHead;
    ComplexListNode *pNewCur = *pNew;
    while (pCur != NULL) {
        ComplexListNode *pSibling = pCur->mSibling;
        if (pSibling != NULL) {
            pNewCur->mSibling = getValue(pNew, getIndex(pHead, pSibling));
        }
        pCur = pCur->mNext;
        pNewCur = pNewCur->mNext;
    }
}

static void cloneAnotherNodes(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }

    ComplexListNode *pCur = *pHead;
    while (pCur != NULL) {
        ComplexListNode *pNew = new ComplexListNode();
        pNew->mValue = pCur->mValue;
        pNew->mSibling = NULL;
        pNew->mNext = pCur->mNext;
        pCur->mNext = pNew;
        pCur = pNew->mNext;
    }
}

static void cloneOddSiblingToOdd(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }

    ComplexListNode *pCur = *pHead;
    while (pCur != NULL && pCur->mNext != NULL) {
        if (pCur->mSibling != NULL) {
            pCur->mNext->mSibling = pCur->mSibling->mNext;
        }
        pCur = pCur->mNext->mNext;
    }
}

static ComplexListNode* paritySplit(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }

    ComplexListNode *pCur = *pHead;
    ComplexListNode *pNewHead = NULL;
    ComplexListNode *pNewCur = NULL;
    while (pCur != NULL && pCur->mNext != NULL) {
        if (pNewHead == NULL) {
            pNewHead = pCur->mNext;
        } else {
            pNewCur->mNext = pCur->mNext;
        }
        pNewCur = pCur->mNext;
        pCur->mNext = pCur->mNext->mNext;
        pCur = pCur->mNext;
    }
    return pNewHead;
}

ComplexListNode* clone(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }

    ComplexListNode *pNewHead = cloneNodes(pHead);
    cloneSibling(pHead, &pNewHead);

    return pNewHead;
}

ComplexListNode* quickClone(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }

    cloneAnotherNodes(pHead);
    cloneOddSiblingToOdd(pHead);
    return paritySplit(pHead);
}

int getIndex(ComplexListNode **pHead, ComplexListNode *pNode) {
    if (pHead == NULL || *pHead == NULL || pNode == NULL) {
        return -1;
    }

    ComplexListNode *pCur = *pHead;
    int index = 0;
    while (pCur != NULL && pCur != pNode) {
        pCur = pCur->mNext;
        ++index;
    }

    if (pCur != NULL) {
        return index;
    }
    return -1;
}

ComplexListNode* getValue(ComplexListNode **pHead, int index) {
    if (pHead == NULL || *pHead == NULL || index < 0) {
        return NULL;
    }

    ComplexListNode *pCur = *pHead;
    while (pCur != NULL && index > 0) {
        pCur = pCur->mNext;
        --index;
    }
    return pCur;
}

void deleteList(ComplexListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }
    ComplexListNode *pCur = *pHead;
    while (pCur != NULL) {
        ComplexListNode *pToDel = pCur;
        pCur = pCur->mNext;
        delete pToDel;
        pToDel = NULL;
    }
    *pHead = NULL;
}

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

ListNode* getCommonNode(ListNode **pLeftHead, ListNode **pRightHead) {
    if (pLeftHead == NULL || *pLeftHead == NULL || pRightHead == NULL
            || *pRightHead == NULL) {
        return NULL;
    }

    int leftLen = 0, rightLen = 0;
    ListNode *pLeftCur = *pLeftHead, *pRightCur = *pRightHead;
    while (pLeftCur != NULL) {
        ++leftLen, pLeftCur = pLeftCur->mNext;
    }
    while (pRightCur != NULL) {
        ++rightLen, pRightCur = pRightCur->mNext;
    }

    pLeftCur = *pLeftHead, pRightCur = *pRightHead;
    if (leftLen > rightLen) {
        int index = leftLen - rightLen;
        while (index > 0 && pLeftCur != NULL) {
            --index, pLeftCur = pLeftCur->mNext;
        }
    } else {
        int index = rightLen - leftLen;
        while (index > 0 && pRightCur != NULL) {
            --index, pRightCur = pRightCur->mNext;
        }
    }
    while (pLeftCur != NULL && pRightCur != NULL && pLeftCur != pRightCur) {
        pLeftCur = pLeftCur->mNext, pRightCur = pRightCur->mNext;
    }
    if (pLeftCur == NULL || pRightCur == NULL) {
        return NULL;
    }
    return pLeftCur;
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

void reverseList(ListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }

    ListNode *pBegin = NULL, *pNext = NULL, *pCur = *pHead;
    while (pCur != NULL) {
        pNext = pCur->mNext;
        pCur->mNext = pBegin;
        pBegin = pCur;
        pCur = pNext;
    }

    *pHead = pBegin;
}

ListNode* reverseListRecursive(ListNode *pBegin, ListNode *pCur) {
    if (pCur == NULL) {
        return pBegin;
    }

    ListNode *pNext = pCur->mNext;
    pCur->mNext = pBegin;
    return reverseListRecursive(pCur, pNext);
}

void reverseListRecursive(ListNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }

    *pHead = reverseListRecursive(NULL, *pHead);
}

ListNode* mergeOrderList(ListNode **pHead1, ListNode **pHead2) {
    if (pHead1 == NULL || pHead2 == NULL) {
        return NULL;
    }

    ListNode *pCur1 = *pHead1, *pCur2 = *pHead2;
    ListNode *pNew = NULL, *pNewCur = NULL;

    while (pCur1 != NULL && pCur2 != NULL) {
        if (pCur1->mValue > pCur2->mValue) {
            if (pNew == NULL) {
                pNew = pCur2;
            } else {
                pNewCur->mNext = pCur2;
            }
            pNewCur = pCur2;
            pCur2 = pCur2->mNext;
        } else {
            if (pNew == NULL) {
                pNew = pCur1;
            } else {
                pNewCur->mNext = pCur1;
            }
            pNewCur = pCur1;
            pCur1 = pCur1->mNext;
        }
    }

    while (pCur1 != NULL) {
        if (pNew == NULL) {
            pNew = pCur1;
        } else {
            pNewCur->mNext = pCur1;
        }
        pNewCur = pCur1;
        pCur1 = pCur1->mNext;
    }
    while (pCur2 != NULL) {
        if (pNew == NULL) {
            pNew = pCur2;
        } else {
            pNewCur->mNext = pCur2;
        }
        pNewCur = pCur2;
        pCur2 = pCur2->mNext;
    }

    return pNew;
}

ListNode* mergeOrderListNewNode(ListNode **pHead1, ListNode **pHead2) {
    if (pHead1 == NULL || pHead2 == NULL) {
        return NULL;
    }

    ListNode *pCur1 = *pHead1, *pCur2 = *pHead2;
    ListNode *pNew = new ListNode();
    ListNode *pCurNew = pNew;

    while (pCur1 != NULL && pCur2 != NULL) {
        ListNode *node = new ListNode();
        node->mNext = NULL;
        if (pCur1->mValue > pCur2->mValue) {
            node->mValue = pCur2->mValue;
            pCur2 = pCur2->mNext;
        } else {
            node->mValue = pCur1->mValue;
            pCur1 = pCur1->mNext;
        }
        pCurNew->mNext = node;
        pCurNew = node;
    }
    while (pCur1 != NULL) {
        ListNode *node = new ListNode();
        node->mNext = NULL;
        node->mValue = pCur1->mValue;
        pCur1 = pCur1->mNext;
        pCurNew->mNext = node;
        pCurNew = node;
    }
    while (pCur2 != NULL) {
        ListNode *node = new ListNode();
        node->mNext = NULL;
        node->mValue = pCur2->mValue;
        pCur2 = pCur2->mNext;
        pCurNew->mNext = node;
        pCurNew = node;
    }

    ListNode *result = pNew->mNext;
    delete pNew;
    return result;
}

ListNode* mergeOrderList(ListNode *pNode1, ListNode *pNode2) {
    if (pNode1 == NULL) {
        return pNode2;
    }
    if (pNode2 == NULL) {
        return pNode1;
    }

    ListNode *pCur = NULL;
    if (pNode1->mValue > pNode2->mValue) {
        pCur = pNode2;
        pCur->mNext = mergeOrderList(pNode1, pNode2->mNext);
    } else {
        pCur = pNode1;
        pCur->mNext = mergeOrderList(pNode1->mNext, pNode2);
    }
    return pCur;
}

ListNode* mergeOrderListRecursive(ListNode **pHead1, ListNode **pHead2) {
    if (pHead1 == NULL || pHead2 == NULL) {
        return NULL;
    }

    return mergeOrderList(*pHead1, *pHead2);
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

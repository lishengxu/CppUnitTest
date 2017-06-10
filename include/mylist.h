/*
 * mylist.h
 *
 *  Created on: May 28, 2017
 *      Author: lsx
 */

#ifndef MYLIST_H_
#define MYLIST_H_
#include <stddef.h>
#include <vector>
#include <stack>

struct ListNode {
    int mValue;
    ListNode *mNext;
};

struct ComplexListNode {
    int mValue;
    ComplexListNode *mNext;
    ComplexListNode *mSibling;
};

ComplexListNode* clone(ComplexListNode **pHead);

int getIndex(ComplexListNode **pHead, ComplexListNode *pNode);

ComplexListNode* getValue(ComplexListNode **pHead, int index);

void deleteList(ComplexListNode **pHead);

void addToTail(ListNode **pHead, int value);

ListNode* findKNodeToTail(ListNode **pHead, unsigned int k);

ListNode* findMiddleNode(ListNode **pHead);

ListNode* findEndNode(ListNode **pHead);

bool isCircleList(ListNode **pHead);

void removeNode(ListNode **pHead, int value);

void deleteList(ListNode **pHead);

void reverseList(ListNode **pHead);

void reverseListRecursive(ListNode **pHead);

ListNode* mergeOrderList(ListNode **pHead1, ListNode **pHead2);

ListNode* mergeOrderListNewNode(ListNode **pHead1, ListNode **pHead2);

ListNode* mergeOrderListRecursive(ListNode **pHead1, ListNode **pHead2);

void printList(ListNode **pHead, bool forward, std::vector<int> *pOut = NULL);

void printListReverse(ListNode **pHead, std::vector<int> *pOut = NULL);

void deleteNode(ListNode **pHead, ListNode *pToBeDeleted);

void quickDeleteNode(ListNode **pHead, ListNode *pToBeDeleted);
#endif /* MYLIST_H_ */

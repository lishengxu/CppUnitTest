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

void addToTail(ListNode **pHead, int value);

ListNode* findKNodeToTail(ListNode **pHead, unsigned int k);

ListNode* findMiddleNode(ListNode **pHead);

ListNode* findEndNode(ListNode **pHead);

bool isCircleList(ListNode **pHead);

void removeNode(ListNode **pHead, int value);

void deleteList(ListNode **pHead);

void printList(ListNode **pHead, bool forward, std::vector<int> *pOut = NULL);

void printListReverse(ListNode **pHead, std::vector<int> *pOut = NULL);

void deleteNode(ListNode **pHead, ListNode *pToBeDeleted);

void quickDeleteNode(ListNode **pHead, ListNode *pToBeDeleted);
#endif /* MYLIST_H_ */

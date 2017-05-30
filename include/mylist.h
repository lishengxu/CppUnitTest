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

void removeNode(ListNode **pHead, int value);

void deleteList(ListNode **pHead);

void printList(ListNode **pHead, bool forward, std::vector<int> *pOut = NULL);

void printListReverse(ListNode **pHead, std::vector<int> *pOut = NULL);

#endif /* MYLIST_H_ */
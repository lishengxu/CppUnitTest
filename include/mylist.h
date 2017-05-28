/*
 * mylist.h
 *
 *  Created on: May 28, 2017
 *      Author: lsx
 */

#ifndef MYLIST_H_
#define MYLIST_H_

struct ListNode {
    int mValue;
    ListNode *mNext;
};

void addToTail(ListNode **pHead, int value);

void removeNode(ListNode **pHead, int value);
#endif /* MYLIST_H_ */

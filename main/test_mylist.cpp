/*
 * test_mylist.cpp
 *
 *  Created on: May 28, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mylist.h"

TEST(mylistTest, addToTail) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    addToTail(pHead, 1);
    EXPECT_EQ(1, (*pHead)->mValue);
    EXPECT_EQ(NULL, (*pHead)->mNext);
    addToTail(pHead, 2);
    EXPECT_EQ(2, (*pHead)->mNext->mValue);
    EXPECT_EQ(NULL, (*pHead)->mNext->mNext);
}

TEST(mylistTest, removeNode) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    addToTail(pHead, 1);
    addToTail(pHead, 2);
    addToTail(pHead, 3);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    addToTail(pHead, 4);
    removeNode(pHead, 1);
    EXPECT_EQ(2, (*pHead)->mValue);
    removeNode(pHead, 4);
    EXPECT_EQ(5, (*pHead)->mNext->mNext->mValue);
    removeNode(pHead, 4);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, (*pHead)->mNext->mNext->mNext->mNext);
}

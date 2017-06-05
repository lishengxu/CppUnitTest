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
    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, findKNodeToTail) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    EXPECT_EQ(NULL, findKNodeToTail(pHead, 0));
    EXPECT_EQ(NULL, findKNodeToTail(NULL, 0));
    addToTail(pHead, 1);
    addToTail(pHead, 2);
    EXPECT_EQ((*pHead)->mNext, findKNodeToTail(pHead, 1));
    EXPECT_EQ(2, findKNodeToTail(pHead, 1)->mValue);
    EXPECT_EQ(*pHead, findKNodeToTail(pHead, 2));
    EXPECT_EQ(1, findKNodeToTail(pHead, 2)->mValue);
    EXPECT_EQ(NULL, findKNodeToTail(pHead, 3));

    addToTail(pHead, 3);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    addToTail(pHead, 4);
    EXPECT_EQ(4, findKNodeToTail(pHead, 1)->mValue);
    EXPECT_EQ(6, findKNodeToTail(pHead, 2)->mValue);
    EXPECT_EQ(2, findKNodeToTail(pHead, 6)->mValue);
    EXPECT_EQ(1, findKNodeToTail(pHead, 7)->mValue);
    EXPECT_EQ(NULL, findKNodeToTail(pHead, 8));
    deleteList(pHead);
    free(pHead);
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
    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, printlist) {
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
    std::vector<int> *pOut = new std::vector<int>();
    printList(pHead, true);
    printList(pHead, true, pOut);
    EXPECT_EQ(1, pOut->at(0));
    EXPECT_EQ(4, pOut->at(6));
    printf("--------\n");
    pOut->clear();
    printList(pHead, false, pOut);
    EXPECT_EQ(4, pOut->at(0));
    EXPECT_EQ(1, pOut->at(6));
    deleteList(pHead);
    free(pHead);
    free(pOut);
}

TEST(mylistTest, printlistreverse) {
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
    std::vector<int> *pOut = new std::vector<int>();
    printListReverse(pHead, pOut);
    EXPECT_EQ(4, pOut->at(0));
    EXPECT_EQ(1, pOut->at(6));
    deleteList(pHead);
    free(pHead);
    free(pOut);
}

TEST(mylistTest, deleteNode) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;

    addToTail(pHead, 1);
    ListNode *pToBeDeleted = *pHead;
    EXPECT_EQ(1, (*pHead)->mValue);
    quickDeleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(NULL, *pHead);

    addToTail(pHead, 1);
    addToTail(pHead, 2);
    addToTail(pHead, 3);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    addToTail(pHead, 4);

    pToBeDeleted = *pHead;
    EXPECT_EQ(1, (*pHead)->mValue);
    deleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(2, ((*pHead)->mValue));

    pToBeDeleted = (*pHead)->mNext->mNext->mNext;
    EXPECT_EQ(5, (*pHead)->mNext->mNext->mNext->mValue);
    deleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mValue);

    pToBeDeleted = (*pHead)->mNext->mNext->mNext->mNext;
    EXPECT_EQ(4, (*pHead)->mNext->mNext->mNext->mNext->mValue);
    deleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(NULL, (*pHead)->mNext->mNext->mNext->mNext);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mValue);
    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, quickdeleteNode) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;

    addToTail(pHead, 1);
    ListNode *pToBeDeleted = *pHead;
    EXPECT_EQ(1, (*pHead)->mValue);
    quickDeleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(NULL, *pHead);

    addToTail(pHead, 1);
    addToTail(pHead, 2);
    addToTail(pHead, 3);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    addToTail(pHead, 4);

    pToBeDeleted = *pHead;
    EXPECT_EQ(1, (*pHead)->mValue);
    quickDeleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(2, ((*pHead)->mValue));

    pToBeDeleted = (*pHead)->mNext->mNext->mNext;
    EXPECT_EQ(5, (*pHead)->mNext->mNext->mNext->mValue);
    quickDeleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mValue);

    pToBeDeleted = (*pHead)->mNext->mNext->mNext->mNext;
    EXPECT_EQ(4, (*pHead)->mNext->mNext->mNext->mNext->mValue);
    quickDeleteNode(pHead, pToBeDeleted);
    EXPECT_EQ(NULL, (*pHead)->mNext->mNext->mNext->mNext);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mValue);
    deleteList(pHead);
    free(pHead);
}

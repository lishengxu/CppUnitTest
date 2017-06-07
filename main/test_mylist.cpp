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

TEST(mylistTest, findMiddleNode) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    EXPECT_EQ(NULL, findMiddleNode(pHead));
    addToTail(pHead, 1);
    EXPECT_EQ(1, findMiddleNode(pHead)->mValue);
    addToTail(pHead, 2);
    EXPECT_EQ(1, findMiddleNode(pHead)->mValue);
    addToTail(pHead, 3);
    EXPECT_EQ(2, findMiddleNode(pHead)->mValue);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    EXPECT_EQ(3, findMiddleNode(pHead)->mValue);
    addToTail(pHead, 4);
    EXPECT_EQ(4, findMiddleNode(pHead)->mValue);

    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, findEndNode) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    EXPECT_EQ(NULL, findEndNode(pHead));
    addToTail(pHead, 1);
    EXPECT_EQ(1, findEndNode(pHead)->mValue);
    addToTail(pHead, 2);
    addToTail(pHead, 3);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    EXPECT_EQ(6, findEndNode(pHead)->mValue);
}
TEST(mylistTest, isCircleList) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    EXPECT_EQ(false, isCircleList(pHead));
    addToTail(pHead, 1);
    EXPECT_EQ(false, isCircleList(pHead));
    ListNode *pBegin = *pHead;
    pBegin->mNext = *pHead;
    EXPECT_EQ(true, isCircleList(pHead));
    pBegin->mNext = NULL;
    addToTail(pHead, 2);
    addToTail(pHead, 3);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    EXPECT_EQ(false, isCircleList(pHead));
    ListNode *pEnd = findEndNode(pHead);
    pEnd->mNext = *pHead;
    EXPECT_EQ(true, isCircleList(pHead));
    pEnd->mNext = NULL;
    EXPECT_EQ(false, isCircleList(pHead));
    ListNode *pMiddle = findMiddleNode(pHead);
    pEnd->mNext = pMiddle;
    EXPECT_EQ(true, isCircleList(pHead));
    pEnd->mNext = NULL;
    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, removeNode) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    addToTail(pHead, 1);
    removeNode(pHead, 1);
    EXPECT_EQ(NULL, *pHead);
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

TEST(mylistTest, reverseList) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    reverseList(pHead);
    EXPECT_EQ(NULL, *pHead);
    addToTail(pHead, 1);
    reverseList(pHead);
    EXPECT_EQ(1, (*pHead)->mValue);
    addToTail(pHead, 2);
    reverseList(pHead);
    EXPECT_EQ(2, (*pHead)->mValue);
    addToTail(pHead, 3);
    reverseList(pHead);
    EXPECT_EQ(3, (*pHead)->mValue);
    EXPECT_EQ(2, findEndNode(pHead)->mValue);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    reverseList(pHead);
    EXPECT_EQ(6, (*pHead)->mValue);
    EXPECT_EQ(3, findEndNode(pHead)->mValue);
    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, reverseListrecursive) {
    ListNode **pHead = (ListNode**) malloc(sizeof(ListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    reverseListRecursive(pHead);
    EXPECT_EQ(NULL, *pHead);
    addToTail(pHead, 1);
    reverseListRecursive(pHead);
    EXPECT_EQ(1, (*pHead)->mValue);
    addToTail(pHead, 2);
    reverseListRecursive(pHead);
    EXPECT_EQ(2, (*pHead)->mValue);
    addToTail(pHead, 3);
    reverseListRecursive(pHead);
    EXPECT_EQ(3, (*pHead)->mValue);
    EXPECT_EQ(2, findEndNode(pHead)->mValue);
    addToTail(pHead, 4);
    addToTail(pHead, 5);
    addToTail(pHead, 6);
    reverseListRecursive(pHead);
    EXPECT_EQ(6, (*pHead)->mValue);
    EXPECT_EQ(3, findEndNode(pHead)->mValue);
    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, mergeOrderList) {
    ListNode **pHead1 = (ListNode**) malloc(sizeof(ListNode*));
    ListNode **pHead2 = (ListNode**) malloc(sizeof(ListNode*));

    *pHead1 = NULL;
    *pHead2 = NULL;
    EXPECT_TRUE(pHead1 != NULL);
    EXPECT_TRUE(pHead2 != NULL);
    EXPECT_EQ(NULL, *pHead1);
    EXPECT_EQ(NULL, *pHead2);

    EXPECT_EQ(NULL, mergeOrderList(NULL, NULL));
    EXPECT_EQ(NULL, mergeOrderList(pHead1, pHead2));
    addToTail(pHead2, 1);
    *pHead1 = mergeOrderList(pHead1, pHead2);
    EXPECT_EQ(1, (*pHead1)->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 3);
    *pHead1 = mergeOrderList(pHead1, pHead2);
    EXPECT_EQ(3, (*pHead1)->mNext->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 2);
    *pHead1 = mergeOrderList(pHead1, pHead2);
    EXPECT_EQ(2, (*pHead1)->mNext->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 3);
    addToTail(pHead2, 4);
    *pHead1 = mergeOrderList(pHead1, pHead2);
    EXPECT_EQ(4, findEndNode(pHead1)->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 2);
    addToTail(pHead2, 3);
    addToTail(pHead2, 5);
    *pHead1 = mergeOrderList(pHead1, pHead2);
    EXPECT_EQ(2, (*pHead1)->mNext->mNext->mValue);
    EXPECT_EQ(5, findEndNode(pHead1)->mValue);
    *pHead2 = NULL;

    deleteList(pHead1);
    free(pHead1);
    free(pHead2);
}

TEST(mylistTest, mergeOrderListNewNode) {
    ListNode **pHead1 = (ListNode**) malloc(sizeof(ListNode*));
    ListNode **pHead2 = (ListNode**) malloc(sizeof(ListNode*));
    ListNode **pHeadNew = (ListNode**) malloc(sizeof(ListNode*));

    *pHead1 = NULL;
    *pHead2 = NULL;
    EXPECT_TRUE(pHead1 != NULL);
    EXPECT_TRUE(pHead2 != NULL);
    EXPECT_EQ(NULL, *pHead1);
    EXPECT_EQ(NULL, *pHead2);

    EXPECT_EQ(NULL, mergeOrderListNewNode(NULL, NULL));
    EXPECT_EQ(NULL, mergeOrderListNewNode(pHead1, pHead2));
    addToTail(pHead1, 1);
    *pHeadNew = mergeOrderListNewNode(pHead1, pHead2);
    EXPECT_EQ(1, (*pHeadNew)->mValue);
    deleteList(pHeadNew);

    addToTail(pHead2, 2);
    *pHeadNew = mergeOrderListNewNode(pHead1, pHead2);
    EXPECT_EQ(2, (*pHeadNew)->mNext->mValue);
    deleteList(pHeadNew);

    addToTail(pHead1, 3);
    *pHeadNew = mergeOrderListNewNode(pHead1, pHead2);
    EXPECT_EQ(3, (*pHeadNew)->mNext->mNext->mValue);
    deleteList(pHeadNew);

    addToTail(pHead1, 3);
    addToTail(pHead1, 4);
    *pHeadNew = mergeOrderListNewNode(pHead1, pHead2);
    EXPECT_EQ(4, findEndNode(pHeadNew)->mValue);
    deleteList(pHeadNew);

    addToTail(pHead2, 2);
    addToTail(pHead2, 3);
    addToTail(pHead2, 5);

    *pHeadNew = mergeOrderListNewNode(pHead1, pHead2);
    EXPECT_EQ(2, (*pHeadNew)->mNext->mNext->mValue);
    EXPECT_EQ(5, findEndNode(pHeadNew)->mValue);
    deleteList(pHeadNew);

    deleteList(pHead1);
    deleteList(pHead2);
    free(pHead1);
    free(pHead2);
    free(pHeadNew);
}

TEST(mylistTest, mergeOrderListRecursive) {
    ListNode **pHead1 = (ListNode**) malloc(sizeof(ListNode*));
    ListNode **pHead2 = (ListNode**) malloc(sizeof(ListNode*));

    *pHead1 = NULL;
    *pHead2 = NULL;
    EXPECT_TRUE(pHead1 != NULL);
    EXPECT_TRUE(pHead2 != NULL);
    EXPECT_EQ(NULL, *pHead1);
    EXPECT_EQ(NULL, *pHead2);

    EXPECT_EQ(NULL, mergeOrderListRecursive(NULL, NULL));
    EXPECT_EQ(NULL, mergeOrderListRecursive(pHead1, pHead2));
    addToTail(pHead2, 1);
    *pHead1 = mergeOrderListRecursive(pHead1, pHead2);
    EXPECT_EQ(1, (*pHead1)->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 3);
    *pHead1 = mergeOrderListRecursive(pHead1, pHead2);
    EXPECT_EQ(3, (*pHead1)->mNext->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 2);
    *pHead1 = mergeOrderListRecursive(pHead1, pHead2);
    EXPECT_EQ(2, (*pHead1)->mNext->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 3);
    addToTail(pHead2, 4);
    *pHead1 = mergeOrderListRecursive(pHead1, pHead2);
    EXPECT_EQ(4, findEndNode(pHead1)->mValue);
    *pHead2 = NULL;

    addToTail(pHead2, 2);
    addToTail(pHead2, 3);
    addToTail(pHead2, 5);
    *pHead1 = mergeOrderListRecursive(pHead1, pHead2);
    EXPECT_EQ(2, (*pHead1)->mNext->mNext->mValue);
    EXPECT_EQ(5, findEndNode(pHead1)->mValue);
    *pHead2 = NULL;

    deleteList(pHead1);
    free(pHead1);
    free(pHead2);
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

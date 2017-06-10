/*
 * test_mylist.cpp
 *
 *  Created on: May 28, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mylist.h"

TEST(mylistTest, clone) {
    EXPECT_EQ(NULL, clone(NULL));
    ComplexListNode **pHead = (ComplexListNode**) malloc(
            sizeof(ComplexListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    ComplexListNode *pNode1 = new ComplexListNode();
    pNode1->mNext = NULL;
    pNode1->mValue = 1;
    pNode1->mSibling = pNode1;
    *pHead = pNode1;

    ComplexListNode **pNew = (ComplexListNode**) malloc(
            sizeof(ComplexListNode*));
    *pNew = clone(pHead);
    EXPECT_EQ(1, (*pNew)->mValue);
    EXPECT_EQ(NULL, (*pNew)->mNext);
    EXPECT_EQ(1, (*pNew)->mSibling->mValue);
    deleteList(pNew);

    ComplexListNode *pNode2 = new ComplexListNode();
    pNode2->mNext = NULL;
    pNode2->mValue = 2;
    pNode2->mSibling = NULL;
    pNode1->mNext = pNode2;

    ComplexListNode *pNode3 = new ComplexListNode();
    pNode3->mNext = NULL;
    pNode3->mValue = 3;
    pNode3->mSibling = NULL;
    pNode2->mNext = pNode3;

    ComplexListNode *pNode4 = new ComplexListNode();
    pNode4->mNext = NULL;
    pNode4->mValue = 4;
    pNode4->mSibling = NULL;
    pNode3->mNext = pNode4;

    ComplexListNode *pNode5 = new ComplexListNode();
    pNode5->mNext = NULL;
    pNode5->mValue = 5;
    pNode5->mSibling = NULL;
    pNode4->mNext = pNode5;

    ComplexListNode *pNode6 = new ComplexListNode();
    pNode6->mNext = NULL;
    pNode6->mValue = 6;
    pNode6->mSibling = NULL;
    pNode5->mNext = pNode6;

    EXPECT_EQ(1, (*pHead)->mValue);
    EXPECT_EQ(2, (*pHead)->mNext->mValue);
    EXPECT_EQ(3, (*pHead)->mNext->mNext->mValue);
    EXPECT_EQ(4, (*pHead)->mNext->mNext->mNext->mValue);
    EXPECT_EQ(5, (*pHead)->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, (*pHead)->mNext->mNext->mNext->mNext->mNext->mNext);
    pNode1->mSibling = pNode4;
    pNode2->mSibling = pNode3;
    pNode3->mSibling = pNode1;
    pNode4->mSibling = pNode2;
    pNode5->mSibling = pNode1;
    pNode6->mSibling = pNode5;
    EXPECT_EQ((*pHead)->mNext->mNext->mNext, (*pHead)->mSibling);
    EXPECT_EQ((*pHead)->mNext->mNext, (*pHead)->mNext->mSibling);
    EXPECT_EQ(*pHead, (*pHead)->mNext->mNext->mSibling);
    EXPECT_EQ((*pHead)->mNext, (*pHead)->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pHead), (*pHead)->mNext->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pHead)->mNext->mNext->mNext->mNext,
            (*pHead)->mNext->mNext->mNext->mNext->mNext->mSibling);

    *pNew = clone(pHead);
    EXPECT_EQ(1, (*pNew)->mValue);
    EXPECT_EQ(2, (*pNew)->mNext->mValue);
    EXPECT_EQ(3, (*pNew)->mNext->mNext->mValue);
    EXPECT_EQ(4, (*pNew)->mNext->mNext->mNext->mValue);
    EXPECT_EQ(5, (*pNew)->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(6, (*pNew)->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, (*pNew)->mNext->mNext->mNext->mNext->mNext->mNext);
    EXPECT_EQ((*pNew)->mNext->mNext->mNext, (*pNew)->mSibling);
    EXPECT_EQ((*pNew)->mNext->mNext, (*pNew)->mNext->mSibling);
    EXPECT_EQ(*pNew, (*pNew)->mNext->mNext->mSibling);
    EXPECT_EQ((*pNew)->mNext, (*pNew)->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pNew), (*pNew)->mNext->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pNew)->mNext->mNext->mNext->mNext,
            (*pNew)->mNext->mNext->mNext->mNext->mNext->mSibling);

    deleteList(pHead);
    deleteList(pNew);

    free(pHead);
    free(pNew);
}

TEST(mylistTest, quickClone) {
    EXPECT_EQ(NULL, quickClone(NULL));
    ComplexListNode **pHead = (ComplexListNode**) malloc(
            sizeof(ComplexListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);

    ComplexListNode *pNode1 = new ComplexListNode();
    pNode1->mNext = NULL;
    pNode1->mValue = 1;
    pNode1->mSibling = pNode1;
    *pHead = pNode1;

    ComplexListNode **pNew = (ComplexListNode**) malloc(
            sizeof(ComplexListNode*));
    *pNew = quickClone(pHead);
    EXPECT_EQ(1, (*pNew)->mValue);
    EXPECT_EQ(NULL, (*pNew)->mNext);
    EXPECT_EQ(1, (*pNew)->mSibling->mValue);
    deleteList(pNew);

    ComplexListNode *pNode2 = new ComplexListNode();
    pNode2->mNext = NULL;
    pNode2->mValue = 2;
    pNode2->mSibling = NULL;
    pNode1->mNext = pNode2;

    ComplexListNode *pNode3 = new ComplexListNode();
    pNode3->mNext = NULL;
    pNode3->mValue = 3;
    pNode3->mSibling = NULL;
    pNode2->mNext = pNode3;

    ComplexListNode *pNode4 = new ComplexListNode();
    pNode4->mNext = NULL;
    pNode4->mValue = 4;
    pNode4->mSibling = NULL;
    pNode3->mNext = pNode4;

    ComplexListNode *pNode5 = new ComplexListNode();
    pNode5->mNext = NULL;
    pNode5->mValue = 5;
    pNode5->mSibling = NULL;
    pNode4->mNext = pNode5;

    ComplexListNode *pNode6 = new ComplexListNode();
    pNode6->mNext = NULL;
    pNode6->mValue = 6;
    pNode6->mSibling = NULL;
    pNode5->mNext = pNode6;

    EXPECT_EQ(1, (*pHead)->mValue);
    EXPECT_EQ(2, (*pHead)->mNext->mValue);
    EXPECT_EQ(3, (*pHead)->mNext->mNext->mValue);
    EXPECT_EQ(4, (*pHead)->mNext->mNext->mNext->mValue);
    EXPECT_EQ(5, (*pHead)->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(6, (*pHead)->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, (*pHead)->mNext->mNext->mNext->mNext->mNext->mNext);
    pNode1->mSibling = pNode4;
    pNode2->mSibling = pNode3;
    pNode3->mSibling = pNode1;
    pNode4->mSibling = pNode2;
    pNode5->mSibling = pNode1;
    pNode6->mSibling = pNode5;
    EXPECT_EQ((*pHead)->mNext->mNext->mNext, (*pHead)->mSibling);
    EXPECT_EQ((*pHead)->mNext->mNext, (*pHead)->mNext->mSibling);
    EXPECT_EQ(*pHead, (*pHead)->mNext->mNext->mSibling);
    EXPECT_EQ((*pHead)->mNext, (*pHead)->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pHead), (*pHead)->mNext->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pHead)->mNext->mNext->mNext->mNext,
            (*pHead)->mNext->mNext->mNext->mNext->mNext->mSibling);

    *pNew = quickClone(pHead);
    EXPECT_EQ(1, (*pNew)->mValue);
    EXPECT_EQ(2, (*pNew)->mNext->mValue);
    EXPECT_EQ(3, (*pNew)->mNext->mNext->mValue);
    EXPECT_EQ(4, (*pNew)->mNext->mNext->mNext->mValue);
    EXPECT_EQ(5, (*pNew)->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(6, (*pNew)->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, (*pNew)->mNext->mNext->mNext->mNext->mNext->mNext);
    EXPECT_EQ((*pNew)->mNext->mNext->mNext, (*pNew)->mSibling);
    EXPECT_EQ((*pNew)->mNext->mNext, (*pNew)->mNext->mSibling);
    EXPECT_EQ(*pNew, (*pNew)->mNext->mNext->mSibling);
    EXPECT_EQ((*pNew)->mNext, (*pNew)->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pNew), (*pNew)->mNext->mNext->mNext->mNext->mSibling);
    EXPECT_EQ((*pNew)->mNext->mNext->mNext->mNext,
            (*pNew)->mNext->mNext->mNext->mNext->mNext->mSibling);

    deleteList(pHead);
    deleteList(pNew);

    free(pHead);
    free(pNew);
}

TEST(mylistTest, getIndex) {
    EXPECT_EQ(-1, getIndex(NULL, NULL));
    ComplexListNode **pHead = (ComplexListNode**) malloc(
            sizeof(ComplexListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);
    EXPECT_EQ(-1, getIndex(pHead, NULL));

    ComplexListNode *pNode1 = new ComplexListNode();
    pNode1->mNext = NULL;
    pNode1->mValue = 1;
    pNode1->mSibling = pNode1;
    *pHead = pNode1;
    EXPECT_EQ(-1, getIndex(pHead, NULL));
    EXPECT_EQ(0, getIndex(pHead, pNode1));

    ComplexListNode *pNode2 = new ComplexListNode();
    pNode2->mNext = NULL;
    pNode2->mValue = 2;
    pNode2->mSibling = NULL;
    pNode1->mNext = pNode2;

    ComplexListNode *pNode3 = new ComplexListNode();
    pNode3->mNext = NULL;
    pNode3->mValue = 3;
    pNode3->mSibling = NULL;
    pNode2->mNext = pNode3;

    ComplexListNode *pNode4 = new ComplexListNode();
    pNode4->mNext = NULL;
    pNode4->mValue = 4;
    pNode4->mSibling = NULL;
    pNode3->mNext = pNode4;

    ComplexListNode *pNode5 = new ComplexListNode();
    pNode5->mNext = NULL;
    pNode5->mValue = 5;
    pNode5->mSibling = NULL;
    pNode4->mNext = pNode5;

    ComplexListNode *pNode6 = new ComplexListNode();
    pNode6->mNext = NULL;
    pNode6->mValue = 6;
    pNode6->mSibling = NULL;

    EXPECT_EQ(0, getIndex(pHead, pNode1));
    EXPECT_EQ(1, getIndex(pHead, pNode2));
    EXPECT_EQ(2, getIndex(pHead, pNode3));
    EXPECT_EQ(3, getIndex(pHead, pNode4));
    EXPECT_EQ(4, getIndex(pHead, pNode5));
    EXPECT_EQ(-1, getIndex(pHead, pNode6));
    pNode5->mNext = pNode6;
    EXPECT_EQ(5, getIndex(pHead, pNode6));

    deleteList(pHead);
    free(pHead);
}

TEST(mylistTest, getValue) {
    EXPECT_EQ(NULL, getValue(NULL, -1));
    ComplexListNode **pHead = (ComplexListNode**) malloc(
            sizeof(ComplexListNode*));
    *pHead = NULL;
    EXPECT_TRUE(pHead != NULL);
    EXPECT_EQ(NULL, *pHead);
    EXPECT_EQ(NULL, getValue(pHead, 0));

    ComplexListNode *pNode1 = new ComplexListNode();
    pNode1->mNext = NULL;
    pNode1->mValue = 1;
    pNode1->mSibling = pNode1;
    *pHead = pNode1;
    EXPECT_EQ(NULL, getValue(pHead, -1));
    EXPECT_EQ(pNode1, getValue(pHead, 0));
    EXPECT_EQ(NULL, getValue(pHead, 1));
    EXPECT_EQ(NULL, getValue(pHead, 2));

    ComplexListNode *pNode2 = new ComplexListNode();
    pNode2->mNext = NULL;
    pNode2->mValue = 2;
    pNode2->mSibling = NULL;
    pNode1->mNext = pNode2;

    ComplexListNode *pNode3 = new ComplexListNode();
    pNode3->mNext = NULL;
    pNode3->mValue = 3;
    pNode3->mSibling = NULL;
    pNode2->mNext = pNode3;

    ComplexListNode *pNode4 = new ComplexListNode();
    pNode4->mNext = NULL;
    pNode4->mValue = 4;
    pNode4->mSibling = NULL;
    pNode3->mNext = pNode4;

    ComplexListNode *pNode5 = new ComplexListNode();
    pNode5->mNext = NULL;
    pNode5->mValue = 5;
    pNode5->mSibling = NULL;
    pNode4->mNext = pNode5;

    ComplexListNode *pNode6 = new ComplexListNode();
    pNode6->mNext = NULL;
    pNode6->mValue = 6;
    pNode6->mSibling = NULL;

    EXPECT_EQ(NULL, getValue(pHead, -1));
    EXPECT_EQ(pNode1, getValue(pHead, 0));
    EXPECT_EQ(pNode2, getValue(pHead, 1));
    EXPECT_EQ(pNode3, getValue(pHead, 2));
    EXPECT_EQ(pNode4, getValue(pHead, 3));
    EXPECT_EQ(pNode5, getValue(pHead, 4));
    EXPECT_EQ(NULL, getValue(pHead, 5));
    EXPECT_EQ(NULL, getValue(pHead, 6));
    pNode5->mNext = pNode6;
    EXPECT_EQ(pNode6, getValue(pHead, 5));
    EXPECT_EQ(NULL, getValue(pHead, 6));
    EXPECT_EQ(NULL, getValue(pHead, 7));

    deleteList(pHead);
    free(pHead);
}

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

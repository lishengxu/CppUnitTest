/*
 * test_mystack.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "MyStackWithQueue.h"
#include "MyStack.h"
#include "stackoperation.h"
#include "common.h"

TEST(mystacktest, MyStackWithQueue_push) {
    MyStackWithQueue<int> mystack;
    mystack.push(1);
    mystack.push(2);
    EXPECT_EQ(2, mystack.top());
    mystack.pop();
    EXPECT_EQ(1, mystack.top());
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    EXPECT_EQ(5, mystack.top());
    mystack.pop();
    mystack.pop();
    mystack.pop();
    EXPECT_EQ(1, mystack.top());
    mystack.pop();
    try {
        mystack.pop();
        ADD_FAILURE();
    } catch (std::exception &e) {
    }
}

TEST(mystacktest, MyStackmin) {
    MyStack<int> mystack;

    mystack.push(2);
    EXPECT_EQ(2, mystack.min());
    mystack.push(1);
    EXPECT_EQ(1, mystack.min());
    mystack.push(1);
    EXPECT_EQ(1, mystack.min());
    mystack.pop();
    EXPECT_EQ(1, mystack.min());
    mystack.pop();
    EXPECT_EQ(2, mystack.min());
    mystack.push(1);
    mystack.push(3);
    EXPECT_EQ(1, mystack.min());
    mystack.pop();
    EXPECT_EQ(1, mystack.min());
    mystack.push(0);
    EXPECT_EQ(0, mystack.min());
    mystack.pop();
    EXPECT_EQ(1, mystack.min());
}

TEST(mystacktest, isStackPopSequence) {
    EXPECT_EQ(false, isStackPopSequence(NULL, NULL, 0, 0));

    int pushArray[] = { 1, 2, 3, 4, 5 };
    int popArrayCorrect[] = { 4, 3, 2, 1, 5 };
    int popArrayError[] = { 4, 3, 5, 1, 2 };
    EXPECT_EQ(false,
            isStackPopSequence(pushArray, popArrayError, LENGTH(pushArray), LENGTH(popArrayError)));
    EXPECT_EQ(true,
            isStackPopSequence(pushArray, popArrayCorrect, LENGTH(pushArray), LENGTH(popArrayCorrect)));
}

TEST(mystacktest, other) {
    std::stack<int> stack;
    stack.push(1);
    stack.top();
}


/*
 * test_mystack.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "MyStackWithQueue.h"
#include "MyStack.h"

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

TEST(mystacktest, other) {
    std::stack<int> stack;
    stack.push(1);
    stack.top();
}


/*
 * test_myqueue.cpp
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "MyQueueWithStack.h"

TEST(MyQueueWithStacktest, appendTail) {
    MyQueueWithStack<int> myqueue;
    myqueue.appendTail(1);
    myqueue.appendTail(2);
    EXPECT_EQ(1, myqueue.deleteHead());
    myqueue.appendTail(3);
    myqueue.appendTail(4);
    EXPECT_EQ(2, myqueue.deleteHead());
    EXPECT_EQ(3, myqueue.deleteHead());
    EXPECT_EQ(4, myqueue.deleteHead());
    try {
        myqueue.deleteHead();
        ADD_FAILURE();
    } catch (std::exception &e) {

    }
}


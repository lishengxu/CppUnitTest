/*
 * test_class.cpp
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */
#include "gtest/gtest.h"
#include "factorial.h"
#include "FooTest.h"

TEST_F(FooTest, postive) {
	EXPECT_EQ(1, factorial(my_shared_resource_));
}

TEST_F(FooTest, HandleNoneZeroInput) {
	EXPECT_EQ(2, factorial(mFoo));
	EXPECT_EQ(6, factorial(mFoo + 1));
}

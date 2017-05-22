/*
 * test_sortarray.cpp
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "sortarray.h"

TEST(ContainFunctionTest, positive) {
	EXPECT_FALSE(contain(NULL, 0, 0, 0, 0, 0, 0, 1));

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	EXPECT_FALSE(contain(array, -1, -1, -1, -1, -1, -1, 1));
	EXPECT_FALSE(contain(array, 2, 1, 0, 0, 0, 0, 1));
	EXPECT_FALSE(contain(array, 0, 0, 2, 1, 0, 0, 1));
	EXPECT_FALSE(contain(array, 1, 2, 1, 2, 0, 0, 1));

	int array1[] = { 1 };
	EXPECT_FALSE(contain(array1, 0, 0, 0, 0, 1, 1, 2));
	EXPECT_TRUE(contain(array1, 0, 0, 0, 0, 1, 1, 1));

	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
	EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 19));
	EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 17));
	EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 0));
	EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 1));
	EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 9));
	EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 8));
}

TEST(ContainFunctionTest, positive2) {
	EXPECT_FALSE(contain(NULL, 0, 0, 1));
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	EXPECT_FALSE(contain(array, 0, 0, 1));

	int array1[] = { 1 };
	EXPECT_FALSE(contain(array1, 1, 1, 0));
	EXPECT_TRUE(contain(array1, 1, 1, 1));

	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
	EXPECT_FALSE(contain(array2, 4, 4, 19));
	EXPECT_TRUE(contain(array2, 4, 4, 17));
	EXPECT_FALSE(contain(array2, 4, 4, 0));
	EXPECT_TRUE(contain(array2, 4, 4, 1));
	EXPECT_TRUE(contain(array2, 4, 4, 9));
	EXPECT_FALSE(contain(array2, 4, 4, 8));
}


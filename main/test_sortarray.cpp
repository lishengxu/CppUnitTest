/*
 * test_sortarray.cpp
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */

#include <stdlib.h>
#include "gtest/gtest.h"
#include "sortarray.h"
#include "common.h"

TEST(sortarraytest, ContainFunction) {
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

TEST(sortarraytest, ContainFunction2) {
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

int comp(const void*a, const void*b) {
    return *(char*) a - *(char*) b;
}

TEST(sortarraytest, MergeFunction) {
    const int maxLen = 1000;
    char operationLeft[maxLen] = { 0 };
    char operationRight[maxLen] = { 0 };
    EXPECT_STREQ(NULL, merge(NULL, NULL, maxLen));
    strcpy(operationLeft, "");
    strcpy(operationRight, "");
    EXPECT_STREQ("", merge(operationLeft, operationRight, maxLen));
    strcpy(operationLeft, "abcdefghijk");
    strcpy(operationRight, "");
    EXPECT_STREQ("abcdefghijk", merge(operationLeft, operationRight, maxLen));
    strcpy(operationLeft, "");
    strcpy(operationRight, "abcdefghijk");
    EXPECT_STREQ("abcdefghijk", merge(operationLeft, operationRight, maxLen));
    strcpy(operationLeft, "adfjalfdjall");
    strcpy(operationRight, "adjfajfdlkafd");
    qsort(operationLeft, strlen(operationLeft), sizeof(char), comp);
    qsort(operationRight, strlen(operationRight), sizeof(char), comp);
    EXPECT_STREQ("aaaaaadddddfffffjjjjkllll",
            merge(operationLeft, operationRight, maxLen));
}

TEST(sortarraytest, findMinInRotate) {
    EXPECT_EQ(-1, findMinInRotate(NULL, 0));

    int array[] = { 1 };
    int length = sizeof(array) / sizeof(array[0]);
    EXPECT_EQ(1, findMinInRotate(array, length));

    int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    length = sizeof(array1) / sizeof(array1[0]);
    EXPECT_EQ(1, findMinInRotate(array1, length));

    int array2[] = { 2, 2, 2, 1, 1, 1 };
    length = sizeof(array2) / sizeof(array2[0]);
    EXPECT_EQ(1, findMinInRotate(array2, length));

    int array3[] = { 2, 1, 2, 2, 2, 2 };
    length = sizeof(array3) / sizeof(array3[0]);
    EXPECT_EQ(1, findMinInRotate(array3, length));

    int array4[] = { 5, 6, 7, 8, 1, 2, 3, 4 };
    length = sizeof(array4) / sizeof(array4[0]);
    EXPECT_EQ(1, findMinInRotate(array4, length));

    int array5[] = { 2, 3, 2, 2, 2, 2, 2, 2 };
    length = sizeof(array5) / sizeof(array5[0]);
    EXPECT_EQ(2, findMinInRotate(array5, length));

    int array6[] = { 2, 2, 1, 1, 1, 1 };
    length = sizeof(array6) / sizeof(array6[0]);
    EXPECT_EQ(1, findMinInRotate(array6, length));
}

TEST(sortarraytest, quicksort) {
    int array[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int expect[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quicksort(array, LENGTH(array), true);
    for (int i = 0; i < LENGTH(array); ++i) {
        EXPECT_EQ(expect[i], array[i]) << ("differ at index " + i) << std::endl;
    }

    int array1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int expect1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    quicksort(array1, LENGTH(array1), false);
    for (int i = 0; i < LENGTH(array1); ++i) {
        EXPECT_EQ(expect1[i], array1[i]) << "differ at index " + i << std::endl;
    }

    int array2[] = { 1, 8, 2, 7, 5, 2, 5, 3, 9, 6, 4 };
    int expect2[] = { 1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 9 };
    quicksort(array2, LENGTH(array2), true);
    for (int i = 0; i < LENGTH(array2); ++i) {
        EXPECT_EQ(expect2[i], array2[i]) << ("differ at index " + i)
                << std::endl;
    }
    int array3[] = { 1 };
    int expect3[] = { 1 };
    quicksort(array3, LENGTH(array3), true);
    for (int i = 0; i < LENGTH(array3); ++i) {
        EXPECT_EQ(expect3[i], array3[i]) << ("differ at index " + i)
                << std::endl;
    }
}

TEST(sortarraytest, quicksortwithpartition2) {
    int array[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int expect[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quicksort(array, LENGTH(array), true, false);
    for (int i = 0; i < LENGTH(array); ++i) {
        EXPECT_EQ(expect[i], array[i]) << ("differ at index " + i) << std::endl;
    }

    int array1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int expect1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    quicksort(array1, LENGTH(array1), false, false);
    for (int i = 0; i < LENGTH(array1); ++i) {
        EXPECT_EQ(expect1[i], array1[i]) << "differ at index " + i << std::endl;
    }

    int array2[] = { 1, 8, 2, 7, 5, 2, 5, 3, 9, 6, 4 };
    int expect2[] = { 1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 9 };
    quicksort(array2, LENGTH(array2), true, false);
    for (int i = 0; i < LENGTH(array2); ++i) {
        EXPECT_EQ(expect2[i], array2[i]) << ("differ at index " + i)
                << std::endl;
    }

    int array3[] = { 1 };
    int expect3[] = { 1 };
    quicksort(array3, LENGTH(array3), true, false);
    for (int i = 0; i < LENGTH(array3); ++i) {
        EXPECT_EQ(expect3[i], array3[i]) << ("differ at index " + i)
                << std::endl;
    }

}

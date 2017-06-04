/*
 * test_factorial.cpp
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */
#include "gtest/gtest.h"
#include "factorial.h"

TEST(IntegerFunctionTest, negative) {
    EXPECT_EQ(1, factorial(-5));
    EXPECT_EQ(1, factorial(-1));
    EXPECT_GT(factorial(-10), 0);
}

TEST(IntegerFunctionTest, DISABLED_zero) {
    EXPECT_EQ(1, factorial(0));
}

TEST(IntegerFunctionTest, postive) {
    EXPECT_EQ(1, factorial(1));
    EXPECT_EQ(2, factorial(2));
    EXPECT_EQ(6, factorial(3));
    EXPECT_EQ(40320, factorial(8));
}

TEST(factorialtest, fibonacci) {
    EXPECT_EQ(0, fibonacci(-1));
    EXPECT_EQ(0, fibonacci(0));
    EXPECT_EQ(1, fibonacci(1));
    EXPECT_EQ(1, fibonacci(2));
    EXPECT_EQ(55, fibonacci(10));
    EXPECT_EQ(6765, fibonacci(20));
}

TEST(factorialtest, numberof1) {
    EXPECT_EQ(0, numberOf1(0));
    EXPECT_EQ(1, numberOf1(1));
    EXPECT_EQ(1, numberOf1(2));
    EXPECT_EQ(2, numberOf1(9));
    EXPECT_EQ(5, numberOf1(31));
    EXPECT_EQ(10, numberOf1(1023));
    EXPECT_EQ(31, numberOf1(0x7fffffff));
    EXPECT_EQ(32, numberOf1(0xffffffff));
    EXPECT_EQ(1, numberOf1(0x80000000));
}

TEST(factorialtest, numberof) {
    EXPECT_EQ(0, numberOf1(0, true));
    EXPECT_EQ(1, numberOf1(1, true));
    EXPECT_EQ(1, numberOf1(2, true));
    EXPECT_EQ(2, numberOf1(9, true));
    EXPECT_EQ(5, numberOf1(31, true));
    EXPECT_EQ(10, numberOf1(1023, true));
    EXPECT_EQ(31, numberOf1(0x7fffffff, true));
    EXPECT_EQ(32, numberOf1(0xffffffff, true));
    EXPECT_EQ(1, numberOf1(0x80000000));
}

TEST(factorialtest, power) {
    double number = 0.0f;
    try {
        EXPECT_FLOAT_EQ(1, power(number, -1));
        ADD_FAILURE();
    } catch (std::exception &e) {
    }
    EXPECT_FLOAT_EQ(1, power(0, 0));
    EXPECT_FLOAT_EQ(0, power(0, 100));
    EXPECT_FLOAT_EQ(1, power(1000.1234, 0));
    EXPECT_FLOAT_EQ(1, power(-1234243.23424, 0));
    EXPECT_FLOAT_EQ(1, power(1, 1));
    EXPECT_FLOAT_EQ(100, power(10, 2));
    EXPECT_FLOAT_EQ(97.3976002, power(3.1415, 4));
    EXPECT_FLOAT_EQ(100, power(-10, 2));
    EXPECT_FLOAT_EQ(-305.974561, power(-3.1415, 5));
    EXPECT_FLOAT_EQ(0.0102671934, power(3.1415, -4));
    EXPECT_FLOAT_EQ(-0.00025452825, power(-5.23423, -5));
    try {
        power(0, -1);
        ADD_FAILURE();
    } catch (std::exception &e) {
    }
}

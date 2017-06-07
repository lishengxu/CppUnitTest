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

TEST(factorialtest, DISABLED_printAllNumber) {
    std::vector<std::string> *pOut = new std::vector<std::string>();
    printAllNumber(-1, pOut);
    EXPECT_EQ(0, pOut->size());
    pOut->clear();
    printAllNumber(0, pOut);
    EXPECT_EQ(0, pOut->size());
    pOut->clear();

    printAllNumber(1, pOut);
    if (pOut->size() > 2) {
        EXPECT_STREQ("0", pOut->at(0).c_str());
        EXPECT_STREQ("8", pOut->at(pOut->size() - 2).c_str());
        EXPECT_STREQ("9", pOut->at(pOut->size() - 1).c_str());
    } else {
        ADD_FAILURE();
    }
    pOut->clear();

    printAllNumber(5, pOut);
    if (pOut->size() > 2) {
        EXPECT_STREQ("00000", pOut->at(0).c_str());
        EXPECT_STREQ("99998", pOut->at(pOut->size() - 2).c_str());
        EXPECT_STREQ("99999", pOut->at(pOut->size() - 1).c_str());
    } else {
        ADD_FAILURE();
    }
    pOut->clear();
    delete pOut;
}

TEST(factorialtest, DISABLED_print1ToMaxOfNDigits) {
    std::vector<std::string> *pOut = new std::vector<std::string>();
    print1ToMaxOfNDigits(-1, pOut);
    EXPECT_EQ(0, pOut->size());
    pOut->clear();
    print1ToMaxOfNDigits(0, pOut);
    EXPECT_EQ(0, pOut->size());
    pOut->clear();

    print1ToMaxOfNDigits(1, pOut);
    if (pOut->size() > 2) {
        EXPECT_STREQ("1", pOut->at(0).c_str());
        EXPECT_STREQ("8", pOut->at(pOut->size() - 2).c_str());
        EXPECT_STREQ("9", pOut->at(pOut->size() - 1).c_str());
    } else {
        ADD_FAILURE();
    }
    pOut->clear();

    print1ToMaxOfNDigits(5, pOut);
    if (pOut->size() > 2) {
        EXPECT_STREQ("00001", pOut->at(0).c_str());
        EXPECT_STREQ("99998", pOut->at(pOut->size() - 2).c_str());
        EXPECT_STREQ("99999", pOut->at(pOut->size() - 1).c_str());
    } else {
        ADD_FAILURE();
    }
    pOut->clear();
    delete pOut;
}

TEST(factorialtest, add) {
    EXPECT_EQ(NULL, add(NULL, NULL));
    EXPECT_EQ(NULL, add("", ""));
    try {
        add("abc", "efg");
        ADD_FAILURE();
    } catch (std::exception &e) {
    }
    EXPECT_STREQ("3456789", add("3456777", "12"));
    EXPECT_STREQ("1111111111111110",
            add("111111111111111", "999999999999999"));
    EXPECT_STREQ("74894", add("123456", "-48562"));
    EXPECT_STREQ("1", add("10000", "-9999"));
    EXPECT_STREQ("0", add("10000", "-10000"));
    EXPECT_STREQ("-464040", add("123456", "-587496"));
    EXPECT_STREQ("-710952", add("-123456", "-587496"));
}

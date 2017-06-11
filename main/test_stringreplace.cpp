/*
 * test_stringreplace.cpp
 *
 *  Created on: May 23, 2017
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include <string.h>
#include "mystring.h"

TEST(StringReplaceTest, positive) {
    EXPECT_TRUE(stringreplace(NULL, " ", "%02") == NULL);
    EXPECT_TRUE(stringreplace(" ", NULL, "%02") == NULL);
    EXPECT_TRUE(stringreplace(" ", "%02", NULL) == NULL);
    EXPECT_STREQ(stringreplace("", "", ""), "");
    EXPECT_STREQ(stringreplace("%02", "", ""), "%02");
    EXPECT_STREQ(stringreplace("", "%02", ""), "");
    EXPECT_STREQ(stringreplace("", "", "%02"), "%02");
    EXPECT_STREQ(stringreplace("%02", "%02", ""), "");
    EXPECT_STREQ(stringreplace("%02", "", "%02"), "%02");
    EXPECT_STREQ(stringreplace("abcdef", " ", "%02"), "abcdef");
    EXPECT_STREQ(stringreplace("     ", " ", "%02"), "%02%02%02%02%02");
    EXPECT_STREQ(
            stringreplace(stringreplace("a b c d e f ", " ", "%02"), "%02",
                    " "), "a b c d e f ");
    EXPECT_STREQ(stringreplace(" a b c d e f", " ", "%02"),
            "%02a%02b%02c%02d%02e%02f");
}

TEST(StringReplace2Test, positive) {
    const int maxLen = 1000;
    char operation[maxLen] = { 0 };
    EXPECT_TRUE(stringreplace(NULL, 0, ' ', "%02") == NULL);
    EXPECT_TRUE(stringreplace(operation, 0, ' ', NULL) == NULL);
    strcpy(operation, "");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', ""), "");
    strcpy(operation, "");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', "%02"), "");
    strcpy(operation, "%02");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', ""), "%02");
    strcpy(operation, "%02");
    strcpy(operation, "abcdef");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', "%02"), "abcdef");
    strcpy(operation, "     ");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', "%02"),
            "%02%02%02%02%02");
    strcpy(operation, "a b c d e f ");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', "%02"),
            "a%02b%02c%02d%02e%02f%02");
    strcpy(operation, " a b c d e f");
    EXPECT_STREQ(stringreplace(operation, maxLen, ' ', "%02"),
            "%02a%02b%02c%02d%02e%02f");

}

TEST(mystringtest, printPermutation) {
    std::vector<std::string> pOut;
    printPermutation(NULL, &pOut);
    EXPECT_EQ(0, pOut.size());

    char str1[] = "a";
    printPermutation(str1, &pOut);
    EXPECT_EQ(1, pOut.size());
    EXPECT_STREQ("a", pOut.at(0).c_str());
    pOut.clear();

    char str2[] = "abc";
    printPermutation(str2, &pOut);
    EXPECT_EQ(6, pOut.size());
    EXPECT_STREQ("abc", pOut.at(0).c_str());
    EXPECT_STREQ("acb", pOut.at(1).c_str());
    EXPECT_STREQ("bac", pOut.at(2).c_str());
    EXPECT_STREQ("bca", pOut.at(3).c_str());
    EXPECT_STREQ("cba", pOut.at(4).c_str());
    EXPECT_STREQ("cab", pOut.at(5).c_str());
    pOut.clear();
}

TEST(mystringtest, printCombination) {
    std::vector<std::string> pOut;
    printCombination(NULL, &pOut);
    EXPECT_EQ(0, pOut.size());

    char str1[] = "a";
    printCombination(str1, &pOut);
    EXPECT_EQ(1, pOut.size());
    EXPECT_STREQ("a", pOut.at(0).c_str());
    pOut.clear();

    char str2[] = "abc";
    printCombination(str2, &pOut);
    EXPECT_EQ(6, pOut.size());
    EXPECT_STREQ("a", pOut.at(0).c_str());
    EXPECT_STREQ("ab", pOut.at(1).c_str());
    EXPECT_STREQ("abc", pOut.at(2).c_str());
    EXPECT_STREQ("b", pOut.at(3).c_str());
    EXPECT_STREQ("bc", pOut.at(4).c_str());
    EXPECT_STREQ("c", pOut.at(5).c_str());
    pOut.clear();
}

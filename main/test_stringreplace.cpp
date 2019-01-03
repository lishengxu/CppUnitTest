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

TEST(mystringtest, getFirstNotRepeatingChar) {
    EXPECT_EQ('\0', getFirstNotRepeatingChar(NULL));
    EXPECT_EQ('\0', getFirstNotRepeatingChar(""));
    EXPECT_EQ('a', getFirstNotRepeatingChar("a"));
    EXPECT_EQ('a', getFirstNotRepeatingChar("abcdefghijklmnopqrstuvwxyz"));
    EXPECT_EQ('\0',
            getFirstNotRepeatingChar(
                    "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz"));
    EXPECT_EQ('b', getFirstNotRepeatingChar("abaccdeff"));
    EXPECT_EQ('s',
            getFirstNotRepeatingChar(
                    "alkdjafldsaflaieoneafenazjaojdllwkenfaadfa"));
}

TEST(mystringtest, reverseSentenceWithWordOrderNoChanged) {
    reverseSentenceWithWordOrderNoChanged(NULL);
    char str[] = "";
    reverseSentenceWithWordOrderNoChanged(str);
    EXPECT_STREQ("", str);

    char str2[] = "a";
    reverseSentenceWithWordOrderNoChanged(str2);
    EXPECT_STREQ("a", str2);

    char str3[] = "I am a student.";
    reverseSentenceWithWordOrderNoChanged(str3);
    EXPECT_STREQ("student. a am I", str3);
}

TEST(mystringtest, leftRotateString) {
    leftRotateString(NULL, 0);

    char str[] = "";
    leftRotateString(str, 0);

    char str2[] = "a";
    leftRotateString(str2, 1);
    EXPECT_STREQ("a", str2);

    char str3[] = "I am a student.";
    leftRotateString(str3, 0);
    EXPECT_STREQ(str3, "I am a student.");
    leftRotateString(str3, 1);
    EXPECT_STREQ(str3, " am a student.I");
    leftRotateString(str3, 14);
    EXPECT_STREQ(str3, "I am a student.");
    leftRotateString(str3, 16);
    EXPECT_STREQ(str3, " am a student.I");
}

TEST(mystringtest, numberOfDeleteToHuiwen) {
    std::vector<char> pOut;
    EXPECT_EQ(-1, numberOfDeleteToHuiwen(NULL, &pOut));

    EXPECT_EQ(0, numberOfDeleteToHuiwen("1", &pOut));
    EXPECT_EQ(0, pOut.size());

    EXPECT_EQ(1, numberOfDeleteToHuiwen("12", &pOut));
    pOut.clear();

    EXPECT_EQ(0, numberOfDeleteToHuiwen("1234321", &pOut));
    EXPECT_EQ(0, pOut.size());

    EXPECT_EQ(8, numberOfDeleteToHuiwen("2348297439824798234", &pOut));
    EXPECT_EQ(0, pOut.size());
}

TEST(mystringtest, LCSubSequence) {
    std::string pOut;
    EXPECT_EQ(-1, LCSubSequence(NULL, NULL, &pOut));

    EXPECT_EQ(0, LCSubSequence("1", "7", &pOut));
    EXPECT_EQ(0, pOut.size());

    EXPECT_EQ(1, LCSubSequence("12", "21", &pOut));
    EXPECT_EQ('2', pOut.at(0));
    pOut.clear();

    EXPECT_EQ(7, LCSubSequence("1234321", "1234321", &pOut));
    EXPECT_EQ('1', pOut.at(0));
    EXPECT_EQ('1', pOut.at(6));
    EXPECT_STREQ("1234321", pOut.c_str());
    EXPECT_EQ(7, pOut.size());
    pOut.clear();

    EXPECT_EQ(11,
            LCSubSequence("2348297439824798234", "4328974289347928432", &pOut));
    EXPECT_STREQ("42974247924", pOut.c_str());
    EXPECT_EQ(11, pOut.size());
}

TEST(mystringtest, LCSubString) {
    std::string pOut;
    EXPECT_EQ(-1, LCSubString(NULL, NULL, &pOut));

    EXPECT_EQ(0, LCSubString("1", "7", &pOut));
    EXPECT_EQ(0, pOut.size());

    EXPECT_EQ(1, LCSubString("12", "21", &pOut));
    EXPECT_EQ('1', pOut.at(0));
    pOut.clear();

    EXPECT_EQ(7, LCSubString("1234321", "1234321", &pOut));
    EXPECT_EQ('1', pOut.at(0));
    EXPECT_EQ('1', pOut.at(6));
    EXPECT_STREQ("1234321", pOut.c_str());
    EXPECT_EQ(7, pOut.size());
    pOut.clear();

    EXPECT_EQ(3,
            LCSubString("2348297439824798234", "4328974289347928432", &pOut));
    EXPECT_STREQ("974", pOut.c_str());
    pOut.clear();
}

TEST(mystringtest, sortString) {
    sortString(NULL);
    sortString((char*) "");

    char str[] = "a";
    sortString(str);
    EXPECT_STREQ("a", str);

    char str2[] = "aA";
    sortString(str2);
    EXPECT_STREQ("aA", str2);

    char str3[] = "Aa";
    sortString(str3);
    EXPECT_STREQ("aA", str3);

    char str4[] = "aAbBCcDEdefF";
    sortString(str4);
    EXPECT_STREQ("abcdefABCDEF", str4);
}


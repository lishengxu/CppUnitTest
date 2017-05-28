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
			stringreplace(stringreplace("a b c d e f ", " ", "%02"), "%02", " "),
			"a b c d e f ");
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

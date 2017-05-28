/*
 * mystring.cpp
 *
 *  Created on: May 24, 2017
 *      Author: lsx
 */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static char* copy(const char* const src) {
	if (src == NULL) {
		return NULL;
	}
	const int newStringLen = strlen(src) + 1;
	char* newString = (char*) calloc(newStringLen, sizeof(char));
	if (newString == NULL) {
		return NULL;
	}
	strcat(newString, src);
	return newString;
}

/**
 * string replace
 * return new string
 */
char* stringreplace(const char* const operation, const char* const src,
		const char* const desc) {
	if (operation == NULL || src == NULL || desc == NULL) {
		return NULL;
	}

	if (!strcmp(operation, src)) {
		return copy(desc);
	}

	if (!*src) {
		return copy(operation);
	}

	const char* cur = operation;
	const char* next = cur;
	int containCount = 0;
	while (*cur) {
		next = strstr(cur, src);
		if (next != NULL) {
			++containCount;
			cur = next + strlen(src);
		} else {
			break;
		}
	}

	const int newStringLen = strlen(operation)
			+ containCount * (strlen(desc) - strlen(src)) + 1;
	char* newString = (char*) calloc(newStringLen, sizeof(char));
	if (newString == NULL) {
		return NULL;
	}

	cur = operation;
	next = cur;
	while (*cur) {
		next = strstr(cur, src);
		if (next != NULL) {
			strncat(newString, cur, next - cur);
			strcat(newString, desc);
			cur = next + strlen(src);
		} else {
			strcat(newString, cur);
			break;
		}
	}

	return newString;
}

/**
 * 字符串替换对于需要替换的是单个字符的情况，可以使用从后往前遍历的方式。
 * 在需要替换的字符是多个字符的情况下，从后往前替换将导致出现替换的结果与从前往后结果不一致的情况。
 * 如将aa替换成bb，对于aaa则处理会出现不一致，因此单个字符替换可以使用本函数，多个字符替换使用
 * 另外一个函数。
 */
char* stringreplace(char* const operation, const int maxLen, const char src,
		const char* const desc) {
	if (operation == NULL || desc == NULL || maxLen < 1) {
		return NULL;
	}

	const int operationLen = strlen(operation);
	const int descLen = strlen(desc);
	char *cur = operation;
	int containCount = 0;
	while (*cur) {
		if (*cur == src) {
			++containCount;
		}
		++cur;
	}
	if (containCount == 0) {
		return operation;
	}
	int newLen = operationLen + containCount * (descLen - 1);
	if (newLen > maxLen) {
		return NULL;
	}
	int newIndex = newLen;
	int origIndex = operationLen;
	while (origIndex >= 0 && newIndex > origIndex) {
		if (*(operation + origIndex) == src) {
			strncpy(operation + newIndex - descLen + 1, desc, descLen);
			newIndex -= descLen;
			--origIndex;
		} else {
			*(operation + newIndex--) = *(operation + origIndex--);
		}
	}

	return operation;
}

/*
 * mystring.cpp
 *
 *  Created on: May 24, 2017
 *      Author: lsx
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

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

static void printPermutation(char *operation, char *begin,
        std::vector<std::string> *pOut) {
    if (*begin == '\0') {
        printf("%s\n", operation);
        if (pOut != NULL) {
            pOut->push_back(operation);
        }
    } else {
        for (char *index = begin; *index != '\0'; ++index) {
            char temp = *index;
            *index = *begin;
            *begin = temp;
            printPermutation(operation, begin + 1, pOut);
            temp = *index;
            *index = *begin;
            *begin = temp;
        }
    }
}

void printPermutation(char *operation, std::vector<std::string> *pOut/*=
 NULL*/) {
    if (operation == NULL || strlen(operation) == 0) {
        return;
    }

    printPermutation(operation, operation, pOut);
}

static void printStr(char *begin, char *end, std::vector<std::string> *pOut) {
    char *index = begin;
    while (index != end) {
        printf("%c", *index++);
    }
    printf("\n");
    if (pOut != NULL) {
        std::string str(begin, end);
        pOut->push_back(str);
    }
}

static void printCombination(char *operation, int length,
        std::vector<std::string> *pOut) {
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = i + 1; j <= length; ++j) {
            printStr(operation + i, operation + j, pOut);
        }
    }
}

void printCombination(char *operation,
        std::vector<std::string> *pOut/*= NULL*/) {
    if (operation == NULL || strlen(operation) == 0) {
        return;
    }

    printCombination(operation, strlen(operation), pOut);
}

char getFirstNotRepeatingChar(const char *string) {
    if (string == NULL) {
        return '\0';
    }

    int hash[256] = { 0 };
    const char *index = string;
    while (*index) {
        ++hash[*index++ - '\0'];
    }

    index = string;
    while (*index) {
        if (hash[*index - '\0'] == 1) {
            return *index;
        }
        ++index;
    }

    return '\0';
}

static void reverse(char *begin, char *end) {
    char *beginIndex = begin;
    char *endIndex = end;
    while (beginIndex < endIndex) {
        char temp = *beginIndex;
        *beginIndex = *endIndex;
        *endIndex = temp;
        ++beginIndex, --endIndex;
    }
}

void reverseSentenceWithWordOrderNoChanged(char *operation) {
    if (operation == NULL || strlen(operation) == 0) {
        return;
    }

    unsigned int len = strlen(operation);
    reverse(operation, operation + len - 1);

    unsigned int index1 = 0, index2 = index1;
    while (index1 < len) {
        while (index1 < len && operation[index1] == ' ') {
            ++index1;
        }
        if (index1 >= len) {
            break;
        }
        index2 = index1;
        while (index1 < len && operation[index1] != ' ') {
            ++index1;
        }
        reverse(operation + index2, operation + index1 - 1);
    }
}

void leftRotateString(char *operation, unsigned int n) {
    if (operation == NULL || n < 0) {
        return;
    }

    unsigned int len = strlen(operation);
    if (len < 2) {
        return;
    }
    n = n % len;

    reverse(operation, operation + len - 1);
    reverse(operation, operation + len - n - 1);
    reverse(operation + len - n, operation + len - 1);
}


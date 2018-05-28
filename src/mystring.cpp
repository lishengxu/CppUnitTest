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
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j <= length; ++j) {
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

int numberOfDeleteToHuiwen(const char *operation,
        std::vector<char> *pOut/* = NULL*/) {
    if (operation == NULL) {
        return -1;
    }

    int len = strlen(operation);
    int lcs[len + 1][len + 1];
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j <= len; ++j) {
            lcs[i][j] = 0;
        }
    }

    for (int i = 1; i <= len; ++i) {
        for (int j = len - 1; j >= 0; --j) {
            if (operation[i - 1] == operation[j]) {
                lcs[i][j] = lcs[i - 1][j + 1] + 1;
            } else {
                lcs[i][j] =
                        lcs[i - 1][j] > lcs[i][j + 1] ?
                                lcs[i - 1][j] : lcs[i][j + 1];
            }
        }
    }

    return len - lcs[len][0];
}

static void printSubSequence(const char *operation, int *path, unsigned int i,
        unsigned int j, unsigned int length, std::string *pOut) {
    if (i == 0 || j == 0) {
        return;
    }

    if (path[i * length + j] == 0) {
        printSubSequence(operation, path, i - 1, j - 1, length, pOut);
        if (pOut != NULL) {
            pOut->push_back(operation[i - 1]);
        }
    } else if (path[i * length + j] == 1) {
        printSubSequence(operation, path, i, j - 1, length, pOut);
    } else if (path[i * length + j] == -1) {
        printSubSequence(operation, path, i - 1, j, length, pOut);
    }
}

int LCSubSequence(const char *left, const char *right,
        std::string *pOut/* = NULL*/) {
    if (left == NULL || right == NULL) {
        return -1;
    }

    unsigned int leftLen = strlen(left);
    unsigned int rightLen = strlen(right);
    int matrix[leftLen + 1][rightLen + 1];
    int path[(leftLen + 1) * (rightLen + 1)];
    for (unsigned int i = 0; i <= leftLen; ++i) {
        matrix[i][0] = 0;
    }
    for (unsigned int j = 0; j <= rightLen; ++j) {
        matrix[0][j] = 0;
    }

    for (unsigned int i = 1; i <= leftLen; ++i) {
        for (unsigned int j = 1; j <= rightLen; ++j) {
            if (left[i - 1] == right[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                path[i * (rightLen + 1) + j] = 0;
            } else {
                if (matrix[i - 1][j] > matrix[i][j - 1]) {
                    matrix[i][j] = matrix[i - 1][j];
                    path[i * (rightLen + 1) + j] = -1;
                } else {
                    matrix[i][j] = matrix[i][j - 1];
                    path[i * (rightLen + 1) + j] = 1;
                }
            }
        }
    }

    printSubSequence(left, path, leftLen, rightLen, rightLen + 1, pOut);
    return matrix[leftLen][rightLen];
}

int LCSubString(const char *left, const char *right,
        std::string *pOut/* = NULL*/) {
    if (left == NULL || right == NULL) {
        return -1;
    }

    unsigned int leftLen = strlen(left);
    unsigned int rightLen = strlen(right);
    int matrix[leftLen][rightLen];
    for (unsigned int i = 0; i <= leftLen; ++i) {
        matrix[i][0] = 0;
    }
    for (unsigned int j = 0; j <= rightLen; ++j) {
        matrix[0][j] = 0;
    }

    unsigned int flag = 0;
    int result = 0;
    for (unsigned int i = 1; i <= leftLen; ++i) {
        for (unsigned int j = 1; j <= rightLen; ++j) {
            if (left[i - 1] == right[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                if (matrix[i][j] > result) {
                    result = matrix[i][j];
                    flag = i - 1;
                }
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    if (result == 0) {
        return result;
    }
    char subString[result + 1];
    strncpy(subString, left + flag - result + 1, result);
    subString[result] = '\0';
    if (pOut != NULL) {
        pOut->assign(subString);
    }
    return result;
}

static void moveForwardAndSwap(char *operation, int begin, int end) {
    if (begin >= end) {
        return;
    }

    char temp = operation[begin];
    for (int index = begin; index < end; ++index) {
        operation[index] = operation[index + 1];
    }
    operation[end] = temp;
}

void sortString(char *operation) {
    if (operation == NULL) {
        return;
    }

    int len = strlen(operation);
    for (int index = len - 1, swapIndex = len - 1; index >= 0; --index) {
        if (operation[index] >= 'A' && operation[index] <= 'Z') {
            moveForwardAndSwap(operation, index, swapIndex);
            --swapIndex;
        }
    }
}

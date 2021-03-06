/*
 * factorial.cpp
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <stdexcept>
#include <math.h>
#include <memory.h>
#include "factorial.h"
#include <algorithm>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long fibonacci(const int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    long long preOne = 0;
    long long preTow = 1;
    long long result;
    for (int i = 2; i <= n; ++i) {
        result = preOne + preTow;
        preOne = preTow;
        preTow = result;
    }
    return result;
}

static int numberOf(const int n) {
    int result = 0;
    int number = n;
    while (number) {
        ++result;
        number &= number - 1;
    }
    return result;
}

int numberOf1(const int n, bool newFunction) {
    if (newFunction) {
        return numberOf(n);
    }
    int base = 1;
    int result = 0;
    while (base) {
        if (base & n) {
            ++result;
        }
        base <<= 1;
    }
    return result;
}

static bool equal(double number1, double number2) {
    if (abs(number1 - number2) < 0.0000001) {
        return true;
    }
    return false;
}

/**
 * 由于计算机在存储浮点数时有误差，因此浮点数不能直接使用==判断是否相等。
 * 负数除以2时，是向下取整，还是向上取整，需要考虑。
 *
 */
double power(double base, int exponent) {
    if (equal(base, 0) && exponent < 0) {
        std::logic_error ex("invalid input.");
        throw std::exception(ex);
    }
    unsigned int absExponent = abs(exponent);
    if (absExponent == 0) {
        return 1;
    }
    if (absExponent == 1) {
        return base;
    }
    double result = power(base, absExponent >> 1);
    result *= result;
    if (absExponent & 0x01) {
        result *= base;
    }
    if (exponent < 0) {
        result = 1 / result;
    }
    return result;
}

static void printNumber(char *pNumbers, const int length) {
    bool hasNonZero = false;
    for (int i = 0; i < length; ++i) {
        if (hasNonZero) {
            printf("%c", pNumbers[i]);
        } else if (pNumbers[i] != '0') {
            hasNonZero = true;
            printf("%c", pNumbers[i]);
        }
    }
    if (hasNonZero) {
        printf("\n");
    }
}

static void printNumber(char *pNumbers, const int length, const int index,
        std::vector<std::string> *pOut = NULL) {
    if (index == length) {
        printNumber(pNumbers, length);
        if (pOut != NULL) {
            pOut->push_back(pNumbers);
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        *(pNumbers + index) = i + '0';
        printNumber(pNumbers, length, index + 1, pOut);
    }
}

void printAllNumber(const int n, std::vector<std::string> *pOut/*=NULL*/) {
    if (n <= 0) {
        return;
    }
    char *pNumbers = (char*) calloc(n + 1, sizeof(char));
    printNumber(pNumbers, n, 0, pOut);
    free(pNumbers);
}

static bool increaseNumber(char *pNumbers, const int length) {
    bool isOverflow = false;
    bool nTakeOver = true;
    for (int i = length - 1; i >= 0; --i) {
        int base = pNumbers[i] - '0';
        if (nTakeOver) {
            ++base;
        }
        if (base == 10) {
            nTakeOver = true;
            pNumbers[i] = '0';
            if (i == 0) {
                isOverflow = true;
            }
        } else {
            nTakeOver = false;
            pNumbers[i] = base + '0';
            break;
        }
    }
    return isOverflow;
}

void print1ToMaxOfNDigits(const int n,
        std::vector<std::string> *pOut/*=NULL*/) {
    if (n <= 0) {
        return;
    }

    char *pNumbers = (char*) calloc(n + 1, sizeof(char));
    memset(pNumbers, '0', n);
    while (!increaseNumber(pNumbers, n)) {
        printNumber(pNumbers, n);
        pOut->push_back(pNumbers);
    }
    free(pNumbers);
}

static int stringcompare(const char *left, const char *right) {
    int leftLen = strlen(left);
    int rightLen = strlen(right);
    if (leftLen > rightLen) {
        return 1;
    } else if (leftLen < rightLen) {
        return -1;
    } else {
        for (int i = 0; i < leftLen; ++i) {
            if (*(left + i) > *(right + i)) {
                return 1;
            } else if (*(left + i) < *(right + i)) {
                return -1;
            }
        }
    }
    return 0;
}

static unsigned int powerBase10(unsigned int n) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < n; ++i) {
        result *= 10;
    }
    return result;
}

unsigned int get1CountFrom1ToN(const unsigned int n) {
    unsigned int count = 0;
    unsigned int number = n;
    unsigned int base = 0;
    while (true) {
        unsigned int value = number / powerBase10(base);
        if (value == 0) {
            break;
        }
        unsigned int bit = value % 10;
        count += bit * base * powerBase10(base) / 10;

        if (bit > 1) {
            count += powerBase10(base);
        } else if (bit == 1) {
            if (base == 0) {
                count += 1;
            } else {
                count += number % powerBase10(base) + 1;
            }
        }
        ++base;
    }
    return count;
}

const char* add(const char* left, const char *right) {
    if (left == NULL || right == NULL || strlen(left) == 0
            || strlen(right) == 0) {
        return NULL;
    }

    int resultFlag = 0;
    bool isAdd = true;
    bool leftIsPos = true;
    if (*left == '+') {
        ++left;
    } else if (*left == '-') {
        ++left;
        leftIsPos = false;
    }

    bool rightIsPos = true;
    if (*right == '+') {
        ++right;
    } else if (*right == '-') {
        ++right;
        rightIsPos = false;
    }

    if (!leftIsPos && rightIsPos) {
        if (stringcompare(left, right) > 0) {
            resultFlag = -1;
        } else {
            std::swap(left, right);
        }
        isAdd = false;
    } else if (leftIsPos && !rightIsPos) {
        if (stringcompare(left, right) < 0) {
            resultFlag = -1;
            std::swap(left, right);
        }
        isAdd = false;
    } else if (!leftIsPos && !rightIsPos) {
        resultFlag = -1;
    }

    int leftLen = strlen(left);
    int rightLen = strlen(right);
    if (leftLen == 0 || rightLen == 0) {
        return NULL;
    }

    char *newNumber = (char*) calloc(leftLen + 2 + 1, sizeof(char));
    const char* leftIndex = left + leftLen - 1;
    const char* rightIndex = right + rightLen - 1;
    char* newIndex = newNumber;
    int takeOver = 0;
    while (leftIndex >= left && rightIndex >= right) {
        int leftDigit = *leftIndex - '0';
        int rightDigit = *rightIndex - '0';
        if (leftDigit > 9 || leftDigit < 0 || rightDigit > 9
                || rightDigit < 0) {
            free(newNumber);
            std::logic_error ex("invalid input ");
            throw std::exception(ex);
            return NULL;
        }
        int value = leftDigit + takeOver;
        if (isAdd) {
            value += rightDigit;
        } else {
            value -= rightDigit;
        }
        if (value >= 10) {
            takeOver = 1;
            value -= 10;
        } else if (value < 0) {
            takeOver = -1;
            value += 10;
        } else {
            takeOver = 0;
        }
        *newIndex++ = value + '0';
        --leftIndex, --rightIndex;
    }
    while (leftIndex >= left) {
        int digit = *leftIndex - '0';
        if (digit > 9 || digit < 0) {
            free(newNumber);
            std::logic_error ex("invalid input " + digit);
            throw std::exception(ex);
            return NULL;
        }
        int value = digit + takeOver;
        if (value >= 10) {
            takeOver = 1;
            value -= 10;
        } else {
            takeOver = 0;
        }
        *newIndex++ = value + '0';
        --leftIndex;
    }
    while (rightIndex >= right) {
        int digit = *rightIndex - '0';
        if (digit < 0 || digit > 9) {
            free(newNumber);
            throw std::invalid_argument("invalid input");
            return NULL;
        }
        int value = digit + takeOver;
        if (value >= 10) {
            takeOver = 1;
            value -= 10;
        } else if (value < 0) {
            takeOver = -1;
            value += 10;
        } else {
            takeOver = 0;
        }
        *newIndex++ = value + '0';
        --rightIndex;
    }
    if (takeOver > 0) {
        *newIndex++ = takeOver + '0';
    }
    --newIndex;
    while (newIndex > newNumber) {
        if (*newIndex == '0') {
            --newIndex;
        } else {
            break;
        }
    }
    if (resultFlag == -1) {
        *++newIndex = '-';
    }
    *++newIndex = '\0';
    std::reverse(newNumber, newIndex);
    return newNumber;
}

unsigned int getUglyNumber(const unsigned int n) {
    if (n == 0) {
        return 0;
    }
    unsigned int ugly[n];
    unsigned int base[3][2];
    base[0][0] = 2;
    base[1][0] = 3;
    base[2][0] = 5;

    ugly[0] = 1;
    base[0][1] = 0;
    base[1][1] = 0;
    base[2][1] = 0;
    for (unsigned int i = 1; i != n; ++i) {
        unsigned int max = ugly[i - 1];
        unsigned int curMax = base[2][0] * max;
        for (unsigned int j = 0; j < 3; ++j) {
            if (base[j][0] * ugly[base[j][1]] == max) {
                ++base[j][1];
            }
            if (base[j][0] * ugly[base[j][1]] <= curMax) {
                curMax = base[j][0] * ugly[base[j][1]];
            }
        }
        ugly[i] = curMax;
    }
    return ugly[n - 1];
}

static int gMaxValue = 6;
void printAllProbality(const int n, std::vector<float> *pOut/* = NULL*/) {
    if (n < 1) {
        return;
    }
    int *pBuffer = (int *) calloc(gMaxValue * n + 1, sizeof(int));
    for (int i = 1; i <= gMaxValue; ++i) {
        pBuffer[i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = gMaxValue * i; j >= i; --j) {
            unsigned int sum = 0;
            for (int k = j - 1; k > 0 && k > j - 7; --k) {
                sum += pBuffer[k];
            }
            pBuffer[j] = sum;
        }

        for (int j = 1; j < i; ++j) {
            pBuffer[j] = 0;
        }
    }

    double base = pow(gMaxValue, n);
    for (int i = n; i <= n * gMaxValue; ++i) {
        printf("%f\n", pBuffer[i] / base);
        if (pOut != NULL) {
            pOut->push_back(pBuffer[i] / base);
        }
    }
    free(pBuffer);
}

static unsigned int functionFalse(unsigned int n) {
    return 0;
}
static unsigned int functionTrue(unsigned int n);
static unsigned int (*p[2])(unsigned int) = {functionFalse, functionTrue};
static unsigned int functionTrue(unsigned int n) {
    return n + p[!!n](n - 1);
}

int add1ToN(unsigned int n) {
    return functionTrue(n);
}

int addNoUseArithmetic(int left, int right) {
    int sum = left, temp = right;
    while (temp) {
        sum ^= temp;
        temp = ((sum ^ temp) & temp) << 1;
    }
    return sum;
}

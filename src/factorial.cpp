/*
 * factorial.cpp
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */
#include <stdlib.h>
#include <exception>
#include <stdexcept>
#include <math.h>

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


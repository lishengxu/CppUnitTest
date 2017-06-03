/*
 * factorial.cpp
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */
#include <stdlib.h>

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

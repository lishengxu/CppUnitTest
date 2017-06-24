/*
 * factorial.h
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */

#ifndef FACTORIAL_H_
#define FACTORIAL_H_
#include <stddef.h>
#include <vector>

int factorial(int n);

long long fibonacci(const int n);

int numberOf1(const int n, bool newFunction = false);

double power(double base, int exponent);

void printAllNumber(const int n, std::vector<std::string> *pOut = NULL);

void print1ToMaxOfNDigits(const int n, std::vector<std::string> *pOut = NULL);

unsigned int get1CountFrom1ToN(const unsigned int n);

const char* add(const char* number1, const char *number2);

unsigned int getUglyNumber(const unsigned int n);

void printAllProbality(const int n, std::vector<float> *pOut = NULL);

int add1ToN(unsigned int n);

int addNoUseArithmetic(int left, int right);

#endif /* FACTORIAL_H_ */

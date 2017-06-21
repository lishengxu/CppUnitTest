/*
 * sortarray.h
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */

#ifndef SORTARRAY_H_
#define SORTARRAY_H_
#include <stddef.h>
#include <vector>
#include <map>

bool contain(const int *array, int rowBegin, int rowEnd, int columnBegin,
        int columnEnd, int rows, int columns, int number);

bool contain(const int *array, int rows, int columns, int number);

char* merge(char * desc, char *src, int maxLen);

int findMinInRotate(const int *rotateArray, int length);

void quicksort(int *array, int length, bool increasing = true,
        bool isPartition1 = true);

void frontOddAndAfterEven(int *array, int length);

void printMatrixClockwise(const int *array, const int rows, const int columns,
        std::vector<int> *pOut = NULL);

int kthLargestNum(int *array, int length, int k);

int moreThanHalfNum(int *array, int length);

int moreThanHalfNum(const int *array, int length);

void getLeastNumbers(int *array, unsigned int length, int *output,
        unsigned int k);

void getLeastNumbers(const int *array, unsigned int length, int *output,
        unsigned int k);

int getMaxSequeueSum(const int *array, unsigned int length);

void getMinConnectionNumber(int *array, unsigned int length,
        std::vector<std::string> *pOut = NULL);

unsigned int getReversePairNumber(int *array, unsigned int length);

unsigned int getNumberOfK(int *array, unsigned int length, int k);

void findNumbersAppearOnce(int *array, unsigned int length, int &number1,
        int &number2);

void findNumberPairWithSumEqualsS(int *array, unsigned int length, int sum,
        std::map<int, int> *pOut = NULL);

void findSequeueWithSumEqualsS(unsigned int sum,
        std::vector<std::string> *pOut = NULL);

#endif /* SORTARRAY_H_ */

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

/**
 * 对数值进行排序的方案：
 * 1、当数据量非常小时，可以使用bitmap排序，其基本思想是将排序数据对于的bit位设置成1，然后从头
 * 遍历，输出数值为1的位的key，完成排序。
 * 2、数据量较小时，可以使用hash表排序，其基本思想是申请n位数组，然后遍历待排序数据，将对于的数组
 * 值设置增加。遍历数组中的值，输出数值，完成排序。
 * 3、数据量比较正常，可以使用快速排序，其基本思想是通过每次确定一个待排序数组的位置，完成排序。
 * 4、数据量非常大时，内存无法填满，需要使用外部归并排序，其基本思想是先归并小的已排序数据，
 * 然后将小的数据归并成大的已排序数据。
 */
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

bool isSequeue(int *array, unsigned int length);

int getLastNumber(unsigned int n, unsigned int m);

double getAVGWaitTime(int *arriveTime, int *dealTime, unsigned int length,
        int processorNums);

#endif /* SORTARRAY_H_ */

/*
 * sortarray.h
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */

#ifndef SORTARRAY_H_
#define SORTARRAY_H_

bool contain(const int *array, int rowBegin, int rowEnd, int columnBegin,
        int columnEnd, int rows, int columns, int number);

bool contain(const int *array, int rows, int columns, int number);

char* merge(char * desc, char *src, int maxLen);

int findMinInRotate(const int *rotateArray, int length);

void quicksort(int *array, int length, bool increasing = true,
        bool isPartition1 = true);

#endif /* SORTARRAY_H_ */

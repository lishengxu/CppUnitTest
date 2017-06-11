/*
 * sortarray.cpp
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdexcept>
#include <exception>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "sortarray.h"

bool contain(const int *array, int rowBegin, int rowEnd, int columnBegin,
        int columnEnd, int rows, int columns, int number) {
    if (array == NULL || rowBegin < 0 || rowEnd < rowBegin || columnBegin < 0
            || columnEnd < columnBegin || rowEnd >= rows
            || columnEnd >= columns) {
        return false;
    }

    bool result = false;
    int rMiddle = rowBegin + ((rowEnd - rowBegin) >> 1);
    int cMiddle = columnBegin + ((columnEnd - columnBegin) >> 1);
    int value = *(array + rMiddle * rows + cMiddle);
    if (value == number) {
        result = true;
    } else if (value < number) {
        result = contain(array, rowBegin, rMiddle, cMiddle + 1, columnEnd, rows,
                columns, number)
                || contain(array, rMiddle + 1, rowEnd, columnBegin, columnEnd,
                        rows, columns, number);
    } else {
        result = contain(array, rMiddle, rowEnd, columnBegin, cMiddle - 1, rows,
                columns, number)
                || contain(array, rowBegin, rMiddle - 1, columnBegin, columnEnd,
                        rows, columns, number);
    }
    return result;
}

bool contain(const int *array, int rows, int columns, int number) {
    if (array == NULL || rows <= 0 || columns <= 0) {
        return false;
    }

    int result = false;
    int curRow = 0;
    int curColumn = columns - 1;

    while (curRow < rows && curColumn >= 0) {
        int curValue = *(array + curRow * rows + curColumn);
        if (curValue == number) {
            result = true;
            break;
        }
        curValue < number ? ++curRow : --curColumn;
    }
    return result;
}

char* merge(char* desc, char* src, int maxLen) {
    if (desc == NULL || src == NULL || maxLen < 1) {
        return NULL;
    }
    const int descLen = strlen(desc);
    const int srcLen = strlen(src);

    int newIndex = srcLen + descLen;
    if (newIndex > maxLen) {
        return NULL;
    }
    int descIndex = descLen - 1;
    int srcIndex = srcLen - 1;
    *(desc + newIndex--) = '\0';
    while (descIndex >= 0 && srcIndex >= 0) {
        if (*(desc + descIndex) < *(src + srcIndex)) {
            *(desc + newIndex--) = *(src + srcIndex--);
        } else {
            *(desc + newIndex--) = *(desc + descIndex--);
        }
    }
    while (srcIndex >= 0) {
        *(desc + newIndex--) = *(src + srcIndex--);
    }
    return desc;
}

static int findMin(const int *rotateArray, int begin, int end) {
    int result = rotateArray[begin];
    for (int i = begin; i < end; ++i) {
        if (rotateArray[i] < result) {
            result = rotateArray[i];
        }
    }
    return result;
}

int findMinInRotate(const int *rotateArray, int length) {
    if (rotateArray == NULL || length < 1) {
        return -1;
    }

    int begin = 0;
    int end = length - 1;
    while (rotateArray[begin] >= rotateArray[end]) {
        if (begin >= end - 1) {
            return rotateArray[end];
        }
        int middle = begin + ((end - begin) >> 1);
        if (rotateArray[middle] == rotateArray[begin]
                && rotateArray[middle] == rotateArray[end]) {
            return findMin(rotateArray, begin, end);
        }
        if (rotateArray[middle] >= rotateArray[begin]) {
            begin = middle;
        } else if (rotateArray[middle] <= rotateArray[end]) {
            end = middle;
        } else {
            std::logic_error ex("Invalid input:" + rotateArray[middle]);
            throw std::exception(ex);
        }
    }
    return rotateArray[begin];
}

static int partition1(int *array, int begin, int end, bool increasing = true) {
    int index = begin + ((end - begin) >> 1);
    std::swap(array[index], array[begin]);

    int value = array[begin];
    int beginIndex = begin;
    int endIndex = end;
    while (beginIndex < endIndex) {
        if (increasing) {
            while (beginIndex < endIndex && array[endIndex] >= value) {
                --endIndex;
            }
        } else {
            while (beginIndex < endIndex && array[endIndex] <= value) {
                --endIndex;
            }
        }
        array[beginIndex] = array[endIndex];
        if (increasing) {
            while (beginIndex < endIndex && array[beginIndex] <= value) {
                ++beginIndex;
            }
        } else {
            while (beginIndex < endIndex && array[beginIndex] >= value) {
                ++beginIndex;
            }
        }
        array[endIndex] = array[beginIndex];
    }
    array[beginIndex] = value;
    return beginIndex;
}

static int partition2(int *array, int begin, int end, bool increasing = true) {
    int index = begin + ((end - begin) >> 1);
    std::swap(array[index], array[end]);

    int small = begin;
    for (int index = begin; index < end; ++index) {
        if (increasing) {
            if (array[index] < array[end]) {
                if (small != index) {
                    std::swap(array[small], array[index]);
                }
                ++small;
            }
        } else {
            if (array[index] > array[end]) {
                if (small != index) {
                    std::swap(array[small], array[index]);
                }
                ++small;
            }
        }

    }
    std::swap(array[small], array[end]);
    return small;
}

static void quicksort(int *array, int begin, int end, bool increasing = true,
        bool isPartition1 = true) {
    if (begin == end) {
        return;
    }

    int index =
            isPartition1 ?
                    partition1(array, begin, end, increasing) :
                    partition2(array, begin, end, increasing);
    if (index > begin) {
        quicksort(array, begin, index - 1, increasing);
    }
    if (index < end) {
        quicksort(array, index + 1, end, increasing);
    }
}

void quicksort(int *array, int length, bool increasing, bool isPartition1) {
    if (array == NULL || length <= 0) {
        return;
    }
    int begin = 0;
    int end = length - 1;
    quicksort(array, begin, end, increasing, isPartition1);
}

static void reOrder(int *array, int begin, int end, bool (*func)(int)) {
    if (array == NULL || begin < 0 || begin > end) {
        return;
    }
    int front = begin;
    for (int i = begin; i <= end; ++i) {
        if (func(array[i])) {
            if (front != i) {
                std::swap(array[front], array[i]);
            }
            ++front;
        }
    }
}

static bool isOdd(int number) {
    return number & 0x01;
}

void frontOddAndAfterEven(int *array, int length) {
    if (array == NULL || length <= 0) {
        return;
    }

    reOrder(array, 0, length - 1, isOdd);
}

void printMatrixClockwise(const int *array, const int rows, const int columns,
        std::vector<int> *pOut/*= NULL*/) {
    if (array == NULL || rows < 1 || columns < 1) {
        return;
    }

    for (int start = 0, endRow = rows - 1, endCol = columns - 1;
            start <= endRow && start <= endCol; ++start, --endRow, --endCol) {
        for (int index = start; index <= endCol; ++index) {
            printf("%d\n", array[start * columns + index]);
            if (pOut != NULL) {
                pOut->push_back(array[start * columns + index]);
            }
        }

        for (int index = start + 1; index <= endRow; ++index) {
            printf("%d\n", array[index * columns + endCol]);
            if (pOut != NULL) {
                pOut->push_back(array[index * columns + endCol]);
            }
        }

        if (start < endRow) {
            for (int index = endCol - 1; index >= start; --index) {
                printf("%d\n", array[endRow * columns + index]);
                if (pOut != NULL) {
                    pOut->push_back(array[endRow * columns + index]);
                }
            }
        }

        if (start < endCol) {
            for (int index = endRow - 1; index > start; --index) {
                printf("%d\n", array[index * columns + start]);
                if (pOut != NULL) {
                    pOut->push_back(array[index * columns + start]);
                }
            }
        }
    }
}

int kthLargestNum(int *array, int length, int k) {
    if (array == NULL || length < 1 || k < 1 || length < k) {
        return 0;
    }

    const int kIndex = length - k;
    int begin = 0, end = length - 1;
    int index = 0;
    do {
        index = partition2(array, begin, end, true);
        if (index > kIndex) {
            end = index - 1;
        } else if (index < kIndex) {
            begin = index + 1;
        }
    } while (index != kIndex);

    return array[kIndex];
}

static bool isMoreThanHalf(const int *array, int length, int value) {
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] == value) {
            ++count;
        }
    }
    return (length >> 1) < count;
}

int moreThanHalfNum(int *array, int length) {
    if (array == NULL || length < 1) {
        return 0;
    }

    int result = kthLargestNum(array, length, (length >> 1) + 1);
    if (!isMoreThanHalf(array, length, result)) {
        result = 0;
    }
    return result;
}

int moreThanHalfNum(const int *array, int length) {
    if (array == NULL || length < 1) {
        return 0;
    }

    int base = 0;
    int times = 0;
    for (int i = 0; i < length; ++i) {
        if (times == 0) {
            base = array[i];
        }
        if (array[i] == base) {
            ++times;
        } else {
            --times;
        }
    }
    int result = base;
    if (!isMoreThanHalf(array, length, result)) {
        result = 0;
    }
    return result;
}

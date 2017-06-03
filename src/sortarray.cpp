/*
 * sortarray.cpp
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */
#include <stddef.h>
#include <string.h>
#include <stdexcept>
#include <exception>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

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

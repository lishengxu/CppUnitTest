/*
 * sortarray.cpp
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */
#include <stddef.h>
#include <string.h>

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

/*
 * mystring.h
 *
 *  Created on: May 24, 2017
 *      Author: lsx
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <vector>
#include <string>
#include <stddef.h>

char* stringreplace(const char* const operation, const char* const src,
        const char* const desc);

char* stringreplace(char* const operation, const int maxLen, const char src,
        const char* const desc);

void printPermutation(char *operation, std::vector<std::string> *pOut = NULL);

void printCombination(char *operation, std::vector<std::string> *pOut = NULL);

char getFirstNotRepeatingChar(const char *string);

void reverseSentenceWithWordOrderNoChanged(char *operation);

void leftRotateString(char *operation, unsigned int n);

int LCS(const char *operation, std::vector<char> *pOut = NULL);

void sortString(char *operation);

#endif /* MYSTRING_H_ */

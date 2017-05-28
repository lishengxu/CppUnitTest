/*
 * mystring.h
 *
 *  Created on: May 24, 2017
 *      Author: lsx
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

char* stringreplace(const char* const operation, const char* const src,
		const char* const desc);

char* stringreplace(char* const operation, const int maxLen, const char src,
		const char* const desc);
#endif /* MYSTRING_H_ */

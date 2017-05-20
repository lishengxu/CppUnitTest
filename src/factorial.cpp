/*
 * factorial.cpp
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}


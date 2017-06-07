/*
 * stackoperation.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: lsx
 */

#include <stddef.h>
#include <string.h>
#include <stack>
#include "stackoperation.h"

bool isStackPopSequence(int *pushArray, int *popArray, int pushSize,
        int popSize) {
    if (pushArray == NULL || popArray == NULL || pushSize < 1
            || pushSize != popSize) {
        return false;
    }

    std::stack<int> stack;
    int pushIndex = 0;
    int popIndex = 0;
    while (popIndex < popSize) {
        while (stack.empty() || stack.top() != popArray[popIndex]) {
            if (pushIndex == pushSize) {
                break;
            }
            stack.push(pushArray[pushIndex++]);
        }
        if (stack.top() != popArray[popIndex]) {
            break;
        }
        stack.pop(), ++popIndex;
    }
    if (!stack.empty() || popIndex < popSize) {
        return false;
    }
    return true;
}


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
    while (pushIndex < pushSize && popIndex < popSize) {
        if (pushArray[pushIndex] == popArray[popIndex]) {
            ++pushIndex, ++popIndex;
            while (!stack.empty() && popIndex < popSize) {
                if (stack.top() == popArray[popIndex]) {
                    stack.pop(), ++popIndex;
                } else {
                    break;
                }
            }
        } else {
            stack.push(pushArray[pushIndex]);
            ++pushIndex;
        }
    }
    if (pushIndex < pushSize) {
        return false;
    }
    while (!stack.empty() && popIndex < popSize) {
        if (stack.top() == popArray[popIndex]) {
            stack.pop(), ++popIndex;
        } else {
            break;
        }
    }
    if (!stack.empty() || popIndex < popSize) {
        return false;
    }
    return true;
}


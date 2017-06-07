/*
 * MyStack.h
 *
 *  Created on: Jun 7, 2017
 *      Author: lsx
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_
#include <stack>
#include <stddef.h>

template<typename T>
class MyStack {

public:
    MyStack();
    virtual ~MyStack();
    void push(const T& node);
    void pop();
    T& min();

private:
    std::stack<T> mStack;
    std::stack<T> mMinStack;
};

template<typename T>
MyStack<T>::MyStack() {
}

template<typename T>
MyStack<T>::~MyStack() {
}

template<typename T>
void MyStack<T>::push(const T& node) {
    mStack.push(node);
    if (mMinStack.empty() || mMinStack.top() >= node) {
        mMinStack.push(node);
    }
}

template<typename T>
void MyStack<T>::pop() {
    T& node = mStack.top();
    mStack.pop();
    if (node == mMinStack.top()) {
        mMinStack.pop();
    }
}

template<typename T>
T& MyStack<T>::min() {
    return mMinStack.top();
}

#endif /* MYSTACK_H_ */

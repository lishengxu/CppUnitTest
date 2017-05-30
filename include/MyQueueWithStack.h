/*
 * MyQueueWithStack.h
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#ifndef MYQUEUEWITHSTACK_H_
#define MYQUEUEWITHSTACK_H_
#include <stack>
#include <stddef.h>
#include <stdexcept>

template<typename T>
class MyQueueWithStack {
public:
    MyQueueWithStack();
    virtual ~MyQueueWithStack();
    void appendTail(const T& node);
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template<typename T>
MyQueueWithStack<T>::MyQueueWithStack() {
}

template<typename T>
MyQueueWithStack<T>::~MyQueueWithStack() {
}

template<typename T>
void MyQueueWithStack<T>::appendTail(const T& node) {
    stack1.push(node);
}

template<typename T>
T MyQueueWithStack<T>::deleteHead() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (stack2.empty()) {
        std::logic_error ex("queue is empty.");
        throw std::exception(ex);
    }
    T node = stack2.top();
    stack2.pop();
    return node;
}
#endif /* MYQUEUEWITHSTACK_H_ */

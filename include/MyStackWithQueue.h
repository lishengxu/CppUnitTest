/*
 * MyStackWithQueue.h
 *
 *  Created on: May 30, 2017
 *      Author: lsx
 */

#ifndef MYSTACKWITHQUEUE_H_
#define MYSTACKWITHQUEUE_H_
#include <queue>
#include <stddef.h>

template<typename T>
class MyStackWithQueue {

public:
    MyStackWithQueue();
    virtual ~MyStackWithQueue();
    void push(const T& node);
    T& top();
    void pop();

private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};

template<typename T>
MyStackWithQueue<T>::MyStackWithQueue() {
}

template<typename T>
MyStackWithQueue<T>::~MyStackWithQueue() {
}

template<typename T>
void MyStackWithQueue<T>::push(const T& node) {
    queue1.empty() ? queue2.push(node) : queue1.push(node);
}

template<typename T>
T& MyStackWithQueue<T>::top() {
    if (queue1.empty()) {
        if (queue2.empty()) {
            std::logic_error ex("stack is empty.");
            throw std::exception(ex);
        }
        return queue2.back();
    } else {
        if (queue1.empty()) {
            std::logic_error ex("stack is empty.");
            throw std::exception(ex);
        }
        return queue1.back();
    }
}

template<typename T>
void MyStackWithQueue<T>::pop() {
    if (queue1.empty()) {
        if (queue2.empty()) {
            std::logic_error ex("stack is empty.");
            throw std::exception(ex);
        }
        while (queue2.size() != 1) {
            queue1.push(queue2.front());
            queue2.pop();
        }
        queue2.pop();
    } else {
        if (queue1.empty()) {
            std::logic_error ex("stack is empty.");
            throw std::exception(ex);
        }
        while (queue1.size() != 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.pop();
    }
}

#endif /* MYSTACKWITHQUEUE_H_ */

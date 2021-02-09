#ifndef MINQUEUE_H
#define MINQUEUE_H
#include <stdexcept>
#include <iostream>
#include "TemplatedDLList.h"
using namespace std;

struct Empty : public std::runtime_error {
  explicit Empty(char const* msg=nullptr): runtime_error(msg) {}
};

template <typename T>
class MinQueue {
private:
    int count;
    DLList<T> mq;
public:
    MinQueue() : count(0), mq() {} // constructor
    void printItems() { // just for testing purposes
        cout << mq;
    }
    void enqueue(T obj) {
        mq.insert_last(obj);
        count++;
    }
    T dequeue() {
        T obj = mq.remove_first();
        count--;
        return obj;
    }
    int size() {
        return count;
    }
    bool is_empty() {
        return mq.is_empty();
    }
    // my min function works for some test cases but not others. I don't know why, it logically makes sense to me
    T min() {
        if (is_empty()) {
            throw Empty("Empty List.");
        }
        else {
            DLListNode<T>* temp = mq.first_node();
            T obj;
            T min = temp->obj;
            while (temp != mq.after_last_node()) {
                if (temp->obj < min) {
                    min = temp->obj;
                }
                temp = temp->next;
            }
            return min;
        }
    }
};

#endif
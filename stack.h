#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

//stack classes added
template<typename T>
class StackNode {
public:
    T data;
    StackNode* next;

    StackNode(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        StackNode<T>* newNode = new StackNode<T>(value);
        if (newNode == nullptr) {
            cout << "Error: Memory allocation failed. Cannot push.\n";
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty."<<endl;
            return;
        }
        StackNode<T>* temp = top;
        top = top->next;
        delete temp;
    }

    const T& peek() const {
        if (isEmpty()) {
            cout << "Error: Stack is empty."<<endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

#endif // STACK_H

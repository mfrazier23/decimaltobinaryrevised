#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

//queue classes added
template<typename T>
class QueueNode {
public:
    T data;
    QueueNode* next;

    QueueNode(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        QueueNode<T>* newNode = new QueueNode<T>(value);
        if (newNode == nullptr) {
            cout << "Error: Memory allocation failed"<<endl;
            return;
        }
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty."<<endl;
            return;
        }
        QueueNode<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    const T& peek() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty."<<endl;
            exit(EXIT_FAILURE);
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

#endif // QUEUE_H

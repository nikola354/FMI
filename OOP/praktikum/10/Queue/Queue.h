#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>

template <typename T>
class Queue {
    T *data;

    unsigned count;
    unsigned capacity;

    int tail;
    int head;

public:
    Queue();

    Queue(const Queue<T> &other);

    Queue<T> & operator=(const Queue<T> &other);

    ~Queue();

    void push(const T &element);

    T pull();

    bool isEmpty() const;

private:
    void copyFrom(const Queue<T> &other);

    void free();
};

template<typename T>
Queue<T>::Queue() {
    count = 0;
    capacity = 4;

    data = new T[capacity];

    head = 0;
    tail = -1;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &other) {
    copyFrom(other);
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    free();
}

template<typename T>
void Queue<T>::copyFrom(const Queue<T> &other) {
    count = other.count;
    capacity = other.capacity;

    data = new T[capacity];
    for (int i = 0; i < count; ++i) {
        data[i] = other.data[i];
    }

    head = other.head;
    tail = other.tail;
}

template<typename T>
void Queue<T>::free() {
    delete[] data;
}

template<typename T>
void Queue<T>::push(const T &element) {
    if (count >= capacity) { //resize:
        capacity *= 2;
        T *temp = new T[capacity];

        for (int i = 0; i < count; ++i) {
            temp[i] = data[i];
        }

        delete [] data;
        data = temp;
    }

    data[count++] = element;
    (tail += 1) %= count;
}

template<typename T>
T Queue<T>::pull() {
    if (isEmpty())
        throw "The collection is empty!";

    T result = data[head++];
    head %= count;
    count--;

    return data[head++];
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

#endif //QUEUE_QUEUE_H

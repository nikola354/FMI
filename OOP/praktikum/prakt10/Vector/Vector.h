//
// Created by nikola354 on 04.05.22.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>

template<typename T>
class Vector {
private:
    T *data;
    unsigned size;
    unsigned capacity;

public:
    Vector();

    Vector(const Vector<T> &other);

    Vector<T> &operator=(const Vector<T> &other);

    //move operator=
    Vector<T> &operator=(Vector<int> &&rhs) noexcept ;

    Vector(Vector<T> &&other);

    ~Vector();

private:
    void free();

    void copyFrom(const Vector<T> &other);

    void resize();

public:
    void pushBack(const T &toAdd);

    void pushAt(unsigned index, const T &toAdd);

    T &popAt(unsigned index);

    T &popBack();

    const T &operator[](unsigned index) const;

    T &operator[](unsigned index);

    bool empty() const;

    void clear();

    void swap(T &other);

};

template<typename T>
Vector<T>::Vector() {
    std::cout << "Default constructor" << std::endl;

    size = 0;
    capacity = 1;
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T> &other) {
    std::cout << "Copy constructor" << std::endl;

    copyFrom(other);
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    std::cout << "Operator=" << std::endl;
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    free();
}

template<typename T>
void Vector<T>::free() {
    delete[] data;
    size = 0;
}

template<typename T>
void Vector<T>::copyFrom(const Vector<T> &other) {
    size = other.size;
    capacity = other.capacity;
    data = reinterpret_cast<int *>(new char[capacity]);
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
void Vector<T>::pushAt(unsigned index, const T &toAdd) {
    if (index > size)
        throw "Index is too big!";

    if (size >= capacity) {
        resize();
    }

    for (int i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    size++;
    data[index] = toAdd;
}

template<typename T>
void Vector<T>::pushBack(const T &toAdd) {
    pushAt(size, toAdd);
}

template<typename T>
T &Vector<T>::popAt(unsigned index) {
    if (index >= size)
        throw "Index is to big!";

    T result = data[index];

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    data[size] = T();

    return result;
}

template<typename T>
void Vector<T>::resize() {
    T *temp = new T[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = data[i];
    }

    capacity *= 2;

    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = temp[i];
    }
    delete[] temp;
}

template<typename T>
T &Vector<T>::popBack() {
    return popAt(size - 1);
}

template<typename T>
const T &Vector<T>::operator[](unsigned int index) const {
    if (index >= size)
        throw "Index is too big!";

    return data[index];
}

template<typename T>
T &Vector<T>::operator[](unsigned int index) {
    if (index >= size)
        throw "Index is too big!";

    return data[index];
}

template<typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template<typename T>
void Vector<T>::clear() {
    free();
    capacity = 1;
    data = new T[capacity];
}

template<typename T>
void Vector<T>::swap(T &other) {
    //todo with pointers:

    Vector<T> temp = *this;
    this = other;
    other = temp;
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<int> &&rhs) noexcept{
    std::cout << "Move operator=" << std::endl;
    if (this != &rhs) {
        free();

        size = rhs.size;
        capacity = rhs.capacity;
        data = rhs.data;

        rhs.data = nullptr;
    }
    return *this;
}

template<typename T>
Vector<T>::Vector(Vector<T> &&rhs) {
    std::cout << "Move constructor" << std::endl;

    size = rhs.size;
    capacity = rhs.capacity;
    data = rhs.data;

    rhs.data = nullptr;
}

#endif //VECTOR_VECTOR_H

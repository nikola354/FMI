//
// Created by nikola354 on 11.05.22.
//

#ifndef OBSERVABLE_OBSERVABLE_H
#define OBSERVABLE_OBSERVABLE_H

#include <iostream>

//T must have:
//default constr;
//operator=
//operator<<
template <typename T>
class Observable{
    T data;

public:
    T getValue() const;

    void setValue(const T &other);
};

template<typename T>
void Observable<T>::setValue(const T &other) {
    T oldData = this->data;
    std::cout << "Will set value from " << oldData << " to " << other << std::endl;
    this->data = other;
    std::cout << "Did set value from " << oldData << " to " << other << std::endl;
}

template<typename T>
T Observable<T>::getValue() const {
    T result = data;
    return result;
}

#endif //OBSERVABLE_OBSERVABLE_H

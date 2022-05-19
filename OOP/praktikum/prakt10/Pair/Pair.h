//
// Created by nikola354 on 04.05.22.
//

#ifndef PAIR_PAIR_H
#define PAIR_PAIR_H


template<typename T>
class Pair {
private:
    T a;
    T b;

public:

    Pair(const T &a, const T &b) {
        this->a = a;
        this->b = b;
    }

    const T &getA() const {
        return a;
    }

    const T &getB() const {
        return b;
    }

    void setA(const T &val) {
        a = val;
    }

    void setB(const T &val) {
        b = val;
    }

    bool operator==(const Pair &other) {
        return (a == other.a && b == other.b);
    }

    bool operator!=(const Pair &other) {
        return !(*this == other);
    }

    const T &max() const{
        return (a > b ? a : b);
    }
};

#endif //PAIR_PAIR_H

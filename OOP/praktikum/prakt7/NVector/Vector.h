#pragma once

#include <iostream>

using std::istream;
using std::ostream;

class Vector {
private:
    int dim;
    int *elements;

public:
    Vector();

    Vector(int dim);

    Vector(const Vector &other);

    Vector &operator=(const Vector &other);

    ~Vector();

    //operators:
    friend istream &operator>>(istream &in, Vector &v);

    friend ostream &operator<<(ostream &out, const Vector &v);

    Vector &operator+=(const Vector &other);

    Vector &operator-=(const Vector &other);

    Vector &operator*=(int scalar) {
        for (int i = 0; i < dim; ++i) {
            elements[i] *= scalar;
        }

        return *this;
    }

    friend Vector operator+(const Vector &first,const Vector &second);

    friend Vector operator-(const Vector &first, const Vector &second);

    friend Vector operator*(const Vector &v, int scalar);

    //other functions:

    bool isPerpendicularTo (const Vector &other) const;

    bool isParallelTo (const Vector &other) const;

    double getLength() const;

    int getElement(int index) const;

private:
    void copyFrom(const Vector &other);

    void free();

};

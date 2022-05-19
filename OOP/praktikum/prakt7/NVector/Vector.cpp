#include <cmath>
#include "Vector.h"

using std::cin;
using std::cout;

Vector::Vector() {
    dim = 0;
    elements = nullptr;
}


Vector::Vector(int dim) {
    this->dim = dim;
    elements = new int[dim];
}

Vector::Vector(const Vector &other) {
    copyFrom(other);
}

Vector &Vector::operator=(const Vector &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Vector::~Vector() {
    free();
}

void Vector::copyFrom(const Vector &other) {
    dim = other.dim;
    elements = new int[dim];

    for (int i = 0; i < dim; ++i) {
        elements[i] = other.elements[i];
    }
}

void Vector::free() {
    delete[] elements;
}

istream &operator>>(istream &in, Vector &v) {
    for (int i = 0; i < v.dim; ++i) {
        in >> v.elements[i];
    }

    return in;
}

ostream &operator<<(ostream &out, const Vector &v) {
    cout << "(";
    for (int i = 0; i < v.dim; ++i) {
        cout << v.elements[i];
        if (i != v.dim - 1) {
            cout << ",";
        }
    }
    cout << ")";

    return out;
}

Vector &Vector::operator+=(const Vector &other) {
    if (dim != other.dim) {
        throw "Vectors are with different sizes!";
    }

    for (int i = 0; i < dim; ++i) {
        elements[i] += other.elements[i];
    }

    return *this;
}

Vector &Vector::operator-=(const Vector &other) {
    if (dim != other.dim) {
        throw "Vectors are with different sizes!";
    }

    for (int i = 0; i < dim; ++i) {
        elements[i] -= other.elements[i];
    }

    return *this;
}

Vector operator+(const Vector &first, const Vector &second) {
    Vector result(first);

    result += second;

    return result;
}

Vector operator-(const Vector &first, const Vector &second) {
    Vector result(first);

    result -= second;

    return result;
}

Vector operator*(const Vector &v, int scalar) {
    Vector result(v);

    result *= scalar;

    return result;
}

bool Vector::isPerpendicularTo(const Vector &other) const {
    if (dim != other.dim) {
        throw "Vectors are with different sizes!";
    }
    
    int toCheck = 0;

    for (int i = 0; i < dim; ++i) {
        toCheck += elements[i] * other.elements[i];
    }
    
    return toCheck == 0;
}

bool Vector::isParallelTo(const Vector &other) const {
    if (dim != other.dim) {
        throw "Vectors are with different sizes!";
    }

    double scalar = elements[0] / other.elements[0];

    for (int i = 1; i < dim; ++i) {
        if (elements[i] / other.elements[i] != scalar)
            return false;
    }

    return true;
}

double Vector::getLength() const {
    double length = 0;
    for (int i = 0; i < dim; ++i) {
        length += elements[i] * elements[i];
    }

    return sqrt(length);
}

int Vector::getElement(int index) const {
    if (index >= dim)
        throw "Too big index";

    return this->elements[index];
}


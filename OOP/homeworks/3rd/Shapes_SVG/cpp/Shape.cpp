//
// Created by nikola354 on 27.05.22.
//

#include "../headers/Shape.h"

void Shape::copyFrom(const Shape &other) {
    pointsCount = other.pointsCount;

    points = new Point[pointsCount];
    for (int i = 0; i < pointsCount; ++i) {
        points[i] = other.points[i];
    }
    color = other.color;
}

void Shape::free() {
    delete[] points;
}

Shape::Shape(size_t pointsCount, const String &color) {
    this->pointsCount = pointsCount;
    points = new Point[pointsCount];

    this->color = color;
}

Shape::~Shape() {
    free();
}

Shape &Shape::operator=(const Shape &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Shape::Shape(const Shape &other) {
    copyFrom(other);
}

const Shape::Type &Shape::getType() const {
    return type;
}

void Shape::setColor(const String &color) {
    if (color.getSize() > 0)
        this->color = color;
}

void Shape::translate(double horizontal, double vertical) {
    for (int i = 0; i < pointsCount; ++i) {
        points[i].x += horizontal;
        points[i].y += vertical;
    }
}

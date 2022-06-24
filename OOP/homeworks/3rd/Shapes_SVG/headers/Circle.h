//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_CIRCLE_H
#define SVG_FILES_CIRCLE_H

#include "Shape.h"

const String CIRCLE_TAG("circle");

const double PI = 3.1415;

class Circle : public Shape {
    double radius;

public:
    Circle() = delete;

    Circle(const Circle &other);

    Circle &operator=(const Circle &other);

    Circle(double radius, const Point &center, const String &color = "unknown");

    double getPerimeter() const override;

    double getArea() const override;

    Shape *clone() const override;

    void print() const override;

    bool containsPoint(const Point &point) const override;

    bool isInShape(const Shape *shape) const override;

    double getRadius() const;

    const Point &getCenter() const;

    void writeToFile(std::ofstream &writeFile) const override;

private:
    void free();

    void copyFrom(const Circle &other);
};


#endif //SVG_FILES_CIRCLE_H

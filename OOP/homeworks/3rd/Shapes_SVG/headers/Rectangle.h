//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_RECTANGLE_H
#define SVG_FILES_RECTANGLE_H

#include <iostream>

#include "Shape.h"

const String RECT_TAG("rect");

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle() = delete;

    Rectangle(const Rectangle &other);

    Rectangle &operator=(const Rectangle &other);

    Rectangle(double width, double height, const Point &p, const String &color = "unknown");

    double getPerimeter() const override;

    double getArea() const override;

    Shape *clone() const override;

    void print() const override;

    bool containsPoint(const Point &point) const override;

    bool isInShape(const Shape *shape) const override;

    const Point &getStartPoint() const;

    double getWidth() const;

    double getHeight() const;

    void writeToFile(std::ofstream &writeFile) const override;

private:
    void free() {};

    void copyFrom(const Rectangle &other);

};


#endif //SVG_FILES_RECTANGLE_H

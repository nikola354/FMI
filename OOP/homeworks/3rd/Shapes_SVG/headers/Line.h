//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_LINE_H
#define SVG_FILES_LINE_H

#include "Shape.h"
#include "Circle.h"

const String LINE_TAG("line");

class Line : public Shape {
public:
    Line() = delete;

    Line(const Line &other);

    Line &operator=(const Line &other);

    Line(const Point &start, const Point &end, const String &color = "unknown");

    double getPerimeter() const override;

    double getArea() const override; //returns 0

    Shape *clone() const override;

    void print() const override;

    bool containsPoint(const Point &point) const override;

    bool isInShape(const Shape *shape) const override;

    void writeToFile(std::ofstream &writeFile) const override;

private:
    void free();

    void copyFrom(const Line &other);
};


#endif //SVG_FILES_LINE_H

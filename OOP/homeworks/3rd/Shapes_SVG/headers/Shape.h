//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_SHAPE_H
#define SVG_FILES_SHAPE_H

#include "Point.h"
#include "String.h"
#include "helpers.h"

class Shape { //abstract class
protected:
    enum Type {
        RECTANGLE,
        CIRCLE,
        LINE,
        UNKNOWN
    } type;
    Point *points;
    size_t pointsCount;
    String color;

public:
    Shape(size_t pointsCount, const String &color);

    Shape(const Shape &other);

    virtual ~Shape();

    Shape &operator=(const Shape &other);

private:
    void copyFrom(const Shape &other);

    void free();

public:
    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual Shape *clone() const = 0;

    virtual void print() const = 0;

    virtual bool containsPoint(const Point &point) const = 0;

    virtual bool isInShape(const Shape *) const = 0;

    const Type &getType() const;

    void setColor(const String &color);

    void translate(double horizontal, double vertical);

    virtual void writeToFile(std::ofstream &writeFile) const = 0;
};


#endif //SVG_FILES_SHAPE_H

//
// Created by nikola354 on 27.05.22.
//

#include "../headers/Line.h"
#include "../headers/Rectangle.h"

Line::Line(const Point &start, const Point &end, const String &color) : Shape(2, color) {
    points[0] = start;
    points[1] = end;
    type = Type::LINE;
}

double Line::getPerimeter() const {
    return points[0].getDist(points[1]);
}

double Line::getArea() const {
    return 0;
}

Shape *Line::clone() const {
    return new Line(*this);
}

Line &Line::operator=(const Line &other) {
    if (this != &other) {
        free();
        Shape::operator=(other);
        copyFrom(other);
    }
    return *this;
}

void Line::free() {

}

void Line::copyFrom(const Line &other) {

}

Line::Line(const Line &other) : Shape(other) {
    copyFrom(other);
    type = Type::LINE;
}

void Line::print() const {
    std::cout << "Line: start: " << points[0] << " end: " << points[1] << " color: " << Shape::color << std::endl;
}

bool Line::containsPoint(const Point &point) const {
    if (point == points[0] || point == points[1]) //prevent deleting by 0
        return true;

    //check if in this segment
    if (!isBetween(point.x, points[0].x, points[1].x) || !isBetween(point.y, points[0].y, points[1].y))
        return false;

    //check if on the line:
    return ((points[0].x - point.x) / (points[1].x - point.x) == (points[0].y - point.y) / (points[1].y - point.y));
}

bool Line::isInShape(const Shape *shape) const {
    return shape->containsPoint(points[0]) && shape->containsPoint(points[1]);
}

void Line::writeToFile(std::ofstream &writeFile) const {
    writeFile << "<line x1=\"" << points[0].x << "\" y1=\"" << points[0].y << "\" x2=\"" << points[1].x << "\" y2=\"" << points[1].y << "\" fill=\""
              << color << "\" />" << std::endl;
}

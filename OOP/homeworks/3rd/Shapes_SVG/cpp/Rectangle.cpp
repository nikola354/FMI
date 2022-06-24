//
// Created by nikola354 on 27.05.22.
//

#include "../headers/Rectangle.h"

Rectangle::Rectangle(double width, double height, const Point &p, const String &color) : Shape(1, color) {
    if (width <= 0 || height <= 0)
        throw "The width and height must be positive numbers!";

    this->width = width;
    this->height = height;
    points[0] = p;
    type = Type::RECTANGLE;
}

double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}

double Rectangle::getArea() const {
    return width * height;
}

Shape *Rectangle::clone() const {
    return new Rectangle(*this);
}

Rectangle::Rectangle(const Rectangle &other) : Shape(other) {
    copyFrom(other);
    type = Type::RECTANGLE;
}

void Rectangle::copyFrom(const Rectangle &other) {
    width = other.width;
    height = other.height;
}

Rectangle &Rectangle::operator=(const Rectangle &other) {
    if (this != &other) {
        Shape::operator=(other);
        free();
        copyFrom(other);
    }

    return *this;
}

void Rectangle::print() const {
    std::cout << "Rectangle: " << points[0] << " width: " << width << " height: " << height << ", color: " << Shape::color << std::endl;
}

bool Rectangle::containsPoint(const Point &point) const {
    return ((point.x >= points[0].x && point.x <= points[0].x + width) && (point.y >= points[0].y && point.y <= points[0].y + height));
}

bool Rectangle::isInShape(const Shape *shape) const {
    return (shape->containsPoint(points[0]) && shape->containsPoint(Point(points[0].x + width, points[0].y + height)));
}

const Point &Rectangle::getStartPoint() const {
    return points[0];
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::writeToFile(std::ofstream &writeFile) const {
    writeFile << "<rect x=\"" << points[0].x << "\" y=\"" << points[0].y << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\""
              << color << "\" />" << std::endl;
}

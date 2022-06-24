//
// Created by nikola354 on 27.05.22.
//

#include "../headers/Circle.h"
#include "../headers/Rectangle.h"

Circle::Circle(double radius, const Point &center, const String &color) : Shape(1, color) {
    if (radius <= 0)
        throw "The radius must be a positive number!";

    this->radius = radius;
    points[0] = center;
    type = Type::CIRCLE;
}

double Circle::getPerimeter() const {
    return 2 * PI * radius;
}

double Circle::getArea() const {
    return PI * radius * radius;
}

Shape *Circle::clone() const {
    return new Circle(*this);
}

void Circle::free() {

}

void Circle::copyFrom(const Circle &other) {
    radius = other.radius;
}

Circle::Circle(const Circle &other) : Shape(other) {
    copyFrom(other);
    type = Type::CIRCLE;
}

Circle &Circle::operator=(const Circle &other) {
    if (this != &other) {
        free();
        Shape::operator=(other);
        copyFrom(other);
    }

    return *this;
}

void Circle::print() const {
    std::cout << "Circle: " << "center: " << points[0] << ", radius: " << radius << ", color: " << Shape::color << std::endl;
}

bool Circle::containsPoint(const Point &point) const {
    return point.getDist(points[0]) <= radius;
}

bool Circle::isInShape(const Shape *shape) const {
    if (this->getArea() > shape->getArea())
        return false;

    if (shape->getType() == Type::CIRCLE) {
        const Circle *big = (Circle *) shape;

        double dist = points[0].getDist(big->points[0]);
        return (big->radius >= (dist + this->radius));
    } else if (shape->getType() == Type::RECTANGLE) { //rectangle
        const Rectangle *big = (Rectangle *) shape;

        if (!big->containsPoint(points[0])) //if the rectangle does not contain the center of the circle
            return false;

        //take the shortest dist from the center to one of the sides of the rect:
        double dyDown = points[0].y - big->getStartPoint().y;
        double dyUp = big->getStartPoint().y + big->getHeight() - points[0].y;
        double dxLeft = points[0].x - big->getStartPoint().x;
        double dxRight = big->getStartPoint().x + big->getWidth() - points[0].x;
        double shortestDist = min(min(dyDown, dyUp), min(dxLeft, dxRight));

        return shortestDist >= radius;
    }
    return false;
}

double Circle::getRadius() const {
    return radius;
}

const Point &Circle::getCenter() const {
    return points[0];
}

void Circle::writeToFile(std::ofstream &writeFile) const {
    writeFile << "<circle cx=\"" << points[0].x << "\" cy=\"" << points[0].y << "\" r=\"" << radius << "\" fill=\""
              << color << "\" />" << std::endl;
}

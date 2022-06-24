//
// Created by nikola354 on 27.05.22.
//

#include "../headers/Point.h"

double Point::getDist(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;

    return sqrt(dx * dx + dy * dy);
}

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.x << ", " << point.y << ")";

    return out;
}

bool Point::operator==(const Point &other) const {
    return (x == other.x && y == other.y);
}

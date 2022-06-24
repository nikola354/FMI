//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_Point_H
#define SVG_FILES_Point_H

#include <iostream>
#include <cmath>

struct Point {
    Point();

    Point(double x, double y);

    double x;
    double y;

    double getDist(const Point &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Point &point);

    bool operator==(const Point &other) const;
};


#endif //SVG_FILES_Point_H

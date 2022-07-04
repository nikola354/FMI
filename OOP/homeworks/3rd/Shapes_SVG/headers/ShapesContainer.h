//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_SHAPESCONTAINER_H
#define SVG_FILES_SHAPESCONTAINER_H

#include "Shape.h"

class ShapesContainer {
    Shape **shapes;
    size_t size;
    size_t capacity;

    void free();

    void copy(const ShapesContainer &other);

public:
    ShapesContainer();

    ShapesContainer(const ShapesContainer &other);

    ShapesContainer &operator=(const ShapesContainer &other);

    ~ShapesContainer();

    void addShape(const Shape &obj);

    void resize();

    void print() const;

    size_t getSize() const;

    void printAreas() const;

    void printPers() const;

    void eraseShape(size_t index);

    void printContaining(const Point &point) const;

    void printWithin(const Shape &big) const;

    void translate(unsigned index, double horizontal, double vertical);

    void translate(double horizontal, double vertical);

    void writeToSVG(std::ofstream &writeFile) const;
};


#endif //SVG_FILES_SHAPESCONTAINER_H

//
// Created by nikola354 on 27.05.22.
//

#include "../headers/ShapesContainer.h"

ShapesContainer::ShapesContainer() {
    capacity = 4;
    size = 0;
    shapes = new Shape *[capacity];
}

ShapesContainer::~ShapesContainer() {
    free();
}

void ShapesContainer::addShape(const Shape &obj) {
    if (size >= capacity)
        resize();

    shapes[size++] = obj.clone();
}

void ShapesContainer::free() {
    for (int i = 0; i < size; ++i) {
        delete shapes[i];
    }
    delete[] shapes;
}

void ShapesContainer::resize() {
    capacity *= 2;

    Shape **temp = new Shape *[capacity];
    for (int i = 0; i < size; ++i) {
        temp[i] = shapes[i];
    }

    delete[] shapes;
    shapes = temp;
}

void ShapesContainer::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". ";
        shapes[i]->print();
    }
}

size_t ShapesContainer::getSize() const {
    return size;
}

void ShapesContainer::printAreas() const {
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". " << shapes[i]->getArea() << std::endl;
    }
}

void ShapesContainer::printPers() const {
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". " << shapes[i]->getPerimeter() << std::endl;
    }
}

void ShapesContainer::eraseShape(size_t index) {
    if (index >= size)
        throw "There is no shape at this index!";

    delete shapes[index];

    for (size_t i = index; i < size - 1; ++i) {
        shapes[i] = shapes[i + 1];
    }
    shapes[size--] = nullptr;
}

void ShapesContainer::printContaining(const Point &point) const {
    bool printed = false;
    for (int i = 0; i < size; i++) {
        if (shapes[i]->containsPoint(point)) {
            printed = true;
            shapes[i]->print();
        }
    }
    if (!printed)
        std::cout << "No shapes contain this point!" << std::endl;
}

void ShapesContainer::printWithin(const Shape &big) const {
    for (int i = 0; i < size; ++i) {
        if (shapes[i]->isInShape(&big)) {
            shapes[i]->print();
        }
    }
}

void ShapesContainer::translate(unsigned index, double horizontal, double vertical) {
    if (index >= size)
        throw "No shape at this index!";

    shapes[index]->translate(horizontal, vertical);
}

void ShapesContainer::translate(double horizontal, double vertical) {
    for (int i = 0; i < size; ++i) {
        shapes[i]->translate(horizontal, vertical);
    }
}

void ShapesContainer::writeToSVG(std::ofstream &writeFile) const {
    writeFile << "<svg>" << std::endl;
    for (int i = 0; i < size; ++i) {
        shapes[i]->writeToFile(writeFile);
    }
    writeFile << "</svg>";
}

ShapesContainer::ShapesContainer(const ShapesContainer &other) {
    copy(other);
}

ShapesContainer &ShapesContainer::operator=(const ShapesContainer &other) {
    if (this != &other) {
        free();
        copy(other);
    }

    return *this;
}

void ShapesContainer::copy(const ShapesContainer &other) {
    size = other.size;
    capacity = other.capacity;

    shapes = new Shape*[capacity];
    for (int i = 0; i < size; ++i) {
        shapes[i] = other.shapes[i]->clone();
    }
}

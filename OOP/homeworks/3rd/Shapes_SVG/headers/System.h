//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_SYSTEM_H
#define SVG_FILES_SYSTEM_H

#include <fstream>

#include "ShapesContainer.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "serialize.h"
#include "../headers/file.h"

class System {
    ShapesContainer container;

    String filename;

public:
    void displayDialog();

    void loadFromFile(String &fileData);

    void createShapeDialog();

    void createCircleDialog();

    void createRectangleDialog();

    void createLineDialog();

    void eraseShapeDialog();

    void pointInDialog();

    void withinDialog();

    void withinCircleDialog();

    void withinRectangleDialog();

    Circle *getCircleDataDialog();

    Rectangle *getRectangleDataDialog();

    Line *getLineDataDialog();

    void translateDialog();

    unsigned getIndexDialog();

    void save();

};


#endif //SVG_FILES_SYSTEM_H

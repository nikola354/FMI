//
// Created by nikola354 on 28.05.22.
//

#ifndef SVG_FILES_SERIALIZE_H
#define SVG_FILES_SERIALIZE_H

#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"


Circle serializeCircle(String &fileData);

Rectangle serializeRectangle(String &fileData);

Line serializeLine(String &fileData);

#endif //SVG_FILES_SERIALIZE_H

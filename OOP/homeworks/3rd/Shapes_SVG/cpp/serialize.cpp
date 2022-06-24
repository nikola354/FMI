//
// Created by nikola354 on 28.05.22.
//
#include "../headers/serialize.h"

Circle serializeCircle(String &fileData) {
    //cx
    fileData.goTo("cx=\"");
    String cx = fileData.takeTo('"');

    //cy
    fileData.goTo("cy=\"");
    String cy = fileData.takeTo('"');

    //radius
    fileData.goTo("r=\"");
    String radius = fileData.takeTo('"');

    //fill
    fileData.goTo("fill=\"");
    String color = fileData.takeTo('"');

    if (!cx.isDouble() || !cy.isDouble() || !radius.isDouble())
        throw "Error occurred while reading a circle!";

    return Circle(radius.toDouble(), Point(cx.toDouble(), cy.toDouble()), color);
}

Rectangle serializeRectangle(String &fileData) {
    //x
    fileData.goTo("x=\"");
    String x = fileData.takeTo('"');

    //y
    fileData.goTo("y=\"");
    String y = fileData.takeTo('"');

    //width:
    fileData.goTo("width=\"");
    String width = fileData.takeTo('"');

    //height
    fileData.goTo("height=\"");
    String height = fileData.takeTo('"');

    //fill
    fileData.goTo("fill=\"");
    String color = fileData.takeTo('"');

    if (!x.isDouble() || !y.isDouble() || !width.isDouble() || !height.isDouble())
        throw "Error occurred while reading a rectangle!";


    return Rectangle(width.toDouble(), height.toDouble(), Point(x.toDouble(), y.toDouble()), color);
}

Line serializeLine(String &fileData) {
    //x1
    fileData.goTo("x1=\"");
    String x1 = fileData.takeTo('"');

    //y1
    fileData.goTo("y1=\"");
    String y1 = fileData.takeTo('"');

    //x2
    fileData.goTo("x2=\"");
    String x2 = fileData.takeTo('"');

    //y2
    fileData.goTo("y2=\"");
    String y2 = fileData.takeTo('"');

    //fill
    fileData.goTo("fill=\"");
    String color = fileData.takeTo('"');

    if (!x1.isDouble() || !y1.isDouble() || !x2.isDouble() || !y2.isDouble())
        throw "Error occurred while reading a line!";

    return Line(Point(x1.toDouble(), y1.toDouble()), Point(x2.toDouble(), y2.toDouble()), color);
}
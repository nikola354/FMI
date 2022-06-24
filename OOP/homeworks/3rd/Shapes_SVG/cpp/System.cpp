//
// Created by nikola354 on 27.05.22.
//

#include "../headers/System.h"


using std::cout;
using std::cin;
using std::endl;

void System::loadFromFile(String &filename) {
    this->filename = filename;

    String fileData = fileToString(filename);

    fileData.goTo("<svg>");
    while (true) {
        fileData.goTo('<');
        if (fileData.getSize() == 0)
            return;
        String tag = fileData.takeTo(' ');

        if (tag == RECT_TAG) {
            container.addShape(serializeRectangle(fileData));
        } else if (tag == CIRCLE_TAG) {
            container.addShape(serializeCircle(fileData));
        } else if (tag == LINE_TAG) {
            container.addShape(serializeLine(fileData));
        }
    }
}

void System::displayDialog() {
    cout << "Enter command:" << endl;
    String cmd;

    while (true) {
        cout << ">";
        cmd.getLine(cin);
        cmd.trim();

        if (cmd == "print") {
            container.print();
        } else if (cmd == "create") {
            createShapeDialog();
        } else if (cmd == "save") {
            save();
        } else if (cmd == "erase") {
            eraseShapeDialog();
        } else if (cmd == "translate") {
            translateDialog();
        } else if (cmd == "within") {
            withinDialog();
        } else if (cmd == "pointIn") {
            pointInDialog();
        } else if (cmd == "areas") {
            container.printAreas();
        } else if (cmd == "pers") {
            container.printPers();
        } else if (cmd == "exit") {
            return;
        } else {
            cout << "Unknown command!" << endl;
        }
    }
}

void System::createShapeDialog() {
    while (true) {
        cout << "Enter shape type: ";
        String shapeType;
        shapeType.getLine(cin);

        if (shapeType == "circle") {
            createCircleDialog();
            return;
        } else if (shapeType == "rect" || shapeType == "rectangle") {
            createRectangleDialog();
            return;
        } else if (shapeType == "line") {
            createLineDialog();
            return;
        } else {
            cout << "We don't support this shape!" << endl;
        }
    }
}

void System::createCircleDialog() {
    Circle *circle = getCircleDataDialog();

    cout << "color: ";
    String color;
    color.getLine(cin);

    circle->setColor(color);

    container.addShape(*circle);
    delete circle;
}

void System::createRectangleDialog() {
    Rectangle *rect = getRectangleDataDialog();

    cout << "color: ";
    String color;
    color.getLine(cin);

    rect->setColor(color);

    container.addShape(*rect);
    delete rect;
}

void System::createLineDialog() {
    Line *newLine = getLineDataDialog();

    cout << "color: ";
    String color;
    color.getLine(cin);

    newLine->setColor(color);

    container.addShape(*newLine);
    delete newLine;
}

void System::eraseShapeDialog() {
    unsigned index = getIndexDialog();
    container.eraseShape(index - 1);
}

void System::pointInDialog() {
    while (true) {
        cout << "Enter x: ";
        String x;
        x.getLine(cin);

        cout << "Enter y: ";
        String y;
        y.getLine(cin);

        if (!x.isDouble() || !y.isDouble()) {
            cout << "The x1 and y1 values must be (decimal) numbers!" << endl;
            continue;
        }

        container.printContaining(Point(x.toDouble(), y.toDouble()));
        return;
    }
}

void System::withinDialog() {
    while (true) {
        cout << "Enter shape type: ";
        String shapeType;
        shapeType.getLine(cin);

        if (shapeType == "circle") {
            withinCircleDialog();
            return;
        } else if (shapeType == "rect" || shapeType == "rectangle") {
            withinRectangleDialog();
            return;
        } else {
            cout << "We don't support this shape!" << endl;
        }
    }

}

void System::withinCircleDialog() {
    Circle *circle = getCircleDataDialog();
    container.printWithin(*circle);
    delete circle;
}

void System::withinRectangleDialog() {
    Rectangle *rect = getRectangleDataDialog();
    container.printWithin(*rect);
    delete rect;
}

Circle *System::getCircleDataDialog() {
    while (true) {
        cout << "cx: ";
        String cx;
        cx.getLine(cin);

        cout << "cy: ";
        String cy;
        cy.getLine(cin);

        cout << "radius: ";
        String radius;
        radius.getLine(cin);

        if (!cx.isDouble() || !cy.isDouble() || !radius.isPositiveDouble()) {
            cout << "The cx and cy must be (decimal) numbers! The radius must be a positive (decimal) number!" << endl;
            continue;
        }

        return new Circle(radius.toDouble(), Point(cx.toDouble(), cy.toDouble()));
    }
}

Rectangle *System::getRectangleDataDialog() {
    while (true) {
        cout << "x: ";
        String x;
        x.getLine(cin);

        cout << "y: ";
        String y;
        y.getLine(cin);

        cout << "width: ";
        String width;
        width.getLine(cin);

        cout << "height: ";
        String height;
        height.getLine(cin);

        if (!x.isDouble() || !y.isDouble() || !width.isPositiveDouble() || !height.isPositiveDouble()) {
            cout << "The x and y must be (decimal) numbers! The width and height must be positive (decimal) numbers!" << endl;
            continue;
        }

        return new Rectangle(width.toDouble(), height.toDouble(), Point(x.toDouble(), y.toDouble()));
    }
}

Line *System::getLineDataDialog() {
    while (true) {
        cout << "x1: ";
        String x1;
        x1.getLine(cin);

        cout << "y1: ";
        String y1;
        y1.getLine(cin);

        cout << "x2: ";
        String x2;
        x2.getLine(cin);

        cout << "y2: ";
        String y2;
        y2.getLine(cin);

        if (!x1.isDouble() || !y1.isDouble() || !x2.isDouble() || !y2.isDouble()) {
            cout << "The x1, y1, x2 and y2 must be (decimal) numbers!" << endl;
            continue;
        }

        return new Line(Point(x1.toDouble(), y1.toDouble()), Point(x2.toDouble(), y2.toDouble()));
    }
}

void System::translateDialog() {
    while (true) {
        cout << "horizontal = ";
        String horizontal;
        horizontal.getLine(cin);

        cout << "vertical = ";
        String vertical;
        vertical.getLine(cin);

        if (!horizontal.isDouble() || !vertical.isDouble()) {
            cout << "The values must be (decimal) numbers!" << endl;
            continue;
        }


        cout << "Do you want to translate all shapes? ";
        String cmd;
        cmd.getLine(cin);

        if (cmd == "y" || cmd == "yes" || cmd == "Yes" || cmd == "YES") {
            container.translate(horizontal.toDouble(), vertical.toDouble());
        } else if (cmd == "n" || cmd == "no" || cmd == "No" || cmd == "NO") {
            unsigned index = getIndexDialog();
            container.translate(index - 1, horizontal.toDouble(), vertical.toDouble());
        } else {
            cout << "Please give a clear answer!" << endl;
            continue;
        }
        return;
    }
}

unsigned System::getIndexDialog() {
    while (true) {
        cout << "Enter index (1-" << container.getSize() << "): ";
        String input;
        input.getLine(cin);

        if (!input.isPositiveNumber()) {
            cout << "The index must be a positive number!" << endl;
            continue;
        }

        unsigned index = input.toNumber();

        if (index > container.getSize() || index <= 0) {
            cout << "There is no shape at this index!" << endl;
            continue;
        }

        return index;
    }
}

void System::save() {
    std::ofstream writeFile(filename.c_str());

    writeFile << FILE_PREFIX << endl;
    container.writeToSVG(writeFile);
    writeFile.close();
}

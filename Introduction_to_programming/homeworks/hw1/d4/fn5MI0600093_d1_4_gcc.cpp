/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 4
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

bool areEqual(double a, double b);

bool firstIsGreater(double a, double b);

//If the absolute difference between 2 numbers is less than the comparison index, I consider them to be equal
const double COMPARISON = 0.000001;
const double QUADRATSIZE = 4;
/*The radius is squared because we compare it to the squared distance between 2 points in the coordinate geometry
 * the formula for the squared distance is:
 * (x1 - x2)^2 + (y1 - y2)^2
 * */
const double SMALLRADIUS = 1 * 1;
const double MIDDLERADIUS = 2 * 2;
const double BIGRADIUS = 4 * 4;

int main() {
    double x, y;
    cin >> x >> y;

    //check if x or y are outside the interval [-4, 4]
    if (firstIsGreater(x, QUADRATSIZE) || firstIsGreater(y, QUADRATSIZE) || firstIsGreater(-QUADRATSIZE, x) ||
        firstIsGreater(-QUADRATSIZE, y)) {
        cout << "Outside";
        return 0;
    }

    //check if x or y are on the border of the square
    if (areEqual(x, QUADRATSIZE) || areEqual(x, -QUADRATSIZE) || areEqual(y, QUADRATSIZE) ||
        areEqual(y, -QUADRATSIZE)) {
        cout << "Undefined";
        return 0;
    }

    //1st QUADRANT
    if (firstIsGreater(x, 0) && firstIsGreater(y, 0)) {
        /*we have SMALL black circle:
         *      center -> point(2, 0)
         *      radius = 1
         */



        double distance = (x - 2) * (x - 2) + y * y; //squared distance between the center (2, 0) and the input point

        if (firstIsGreater(distance, SMALLRADIUS)) {
            cout << "White";
        } else if (areEqual(distance, SMALLRADIUS)) {
            cout << "Undefined";
        } else {
            cout << "Black";
        }

        return 0;
    }

    //2nd QUADRANT
    if ((firstIsGreater(0, x) || areEqual(x, 0)) && (firstIsGreater(y, 0) || areEqual(y, 0))) {
        /*
         * we have black circle with:
         *      middle radius = 2
         *      center -> point(-2, 0)
         * and white circle inside it with:
         *      small radius = 1
         *      center -> point(-2, 0)
         * */

        double distance =
                (x - (-2)) * (x - (-2)) + y * y; //squared distance between the center (-2, 0) and the input point

        if (firstIsGreater(distance, SMALLRADIUS) && firstIsGreater(MIDDLERADIUS, distance)) {
            cout << "Black";
        } else if (areEqual(distance, SMALLRADIUS) || areEqual(distance, MIDDLERADIUS)) {
            cout << "Undefined";
        } else {
            cout << "White";
        }

        return 0;
    }

    //3rd QUADRANT
    if (firstIsGreater(0, x) && firstIsGreater(0, y)) {
        /*
         * we have SMALL white circle with:
         *      radius = 1
         *      center -> point A = (-2, 0)
         * and BIG black circle with:
         *      center -> point O = (0, 0)
         *      radius = 4
         * */

        double distanceFromO = x * x + y * y; //squared distance between the center (0, 0) and the input point
        double distanceFromA =
                (x - (-2)) * (x - (-2)) + y * y; //squared distance between the center A (-2, 0) and the input point

        if (firstIsGreater(SMALLRADIUS, distanceFromA) || firstIsGreater(distanceFromO, BIGRADIUS)) {
            cout << "White";
        } else if (areEqual(SMALLRADIUS, distanceFromA) || areEqual(BIGRADIUS, distanceFromO)) {
            cout << "Undefined";
        } else {
            cout << "Black";
        }

        return 0;
    }

    //4th QUADRANT
    if ((firstIsGreater(x, 0) || areEqual(x, 0)) && (firstIsGreater(0, y) || areEqual(y, 0))) {
        /*
         * we have MIDDLE white circle with:
         *      radius = 2
         *      center -> point A(2, 0)
         * and SMALL black circle inside with:
         *      radius = 1
         *      center -> point A(2, 0)
         *
         * and BIG black circle with:
         *      radius = 4
         *      center -> point O(0, 0)
         * */

        double distanceFromO = x * x + y * y; //squared distance between the center (0, 0) and the input point
        double distanceFromA =
                (x - 2) * (x - 2) + y * y; //squared distance between the center A (2, 0) and the input point

        if (firstIsGreater(SMALLRADIUS, distanceFromA) ||
            (firstIsGreater(distanceFromA, MIDDLERADIUS) && firstIsGreater(BIGRADIUS, distanceFromO))) {
            cout << "Black";
        } else if (areEqual(SMALLRADIUS, distanceFromA) || areEqual(MIDDLERADIUS, distanceFromA) ||
                   areEqual(BIGRADIUS, distanceFromO)) {
            cout << "Undefined";
        } else {
            cout << "White";
        }

        return 0;
    }

    return 0;
}

bool areEqual(double a, double b) {
    if ((a - b) < COMPARISON && (b - a) < COMPARISON) return true;
    return false;
}

bool firstIsGreater(double a, double b) {
    if ((a - b) >= COMPARISON) return true;
    return false;
}
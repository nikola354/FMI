#include <iostream>
#include <cmath>

using namespace std;

const int MAX_X = 10;
const int MIN_X = -10;
const int MAX_Y = 10;
const int MIN_Y = -10;

struct Point {
private:
    double x;
    double y;

public:
    Point(){
        x = -1;
        y = -1;
    }
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    //setters:
    void setX(double x) {
        if (x > MAX_X || x < MIN_X) {
            cout << "ERROR!" << endl;
        }

        this->x = x;
    }

    void setY(double y) {
        if (y > MAX_Y || y < MIN_Y) {
            cout << "ERROR!" << endl;
        }

        this->y = y;
    }

    //getters:
    double getX() const{
        return x;
    }

    double getY() const{
        return y;
    }

    double distanceTo(const Point &p) const {
        double firstDist = p.x - this->x;
        double secondDist = p.y - this->y;

        return sqrt(firstDist * firstDist + secondDist * secondDist);
    }

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

struct Triangle {
    Point A;
    Point B;
    Point C;
    double perimeter;

    Triangle(Point A, Point B, Point C){
        this->A = A;
        this->B = B;
        this->C = C;
        this->perimeter = this->getPerimeter();
    }

    double getPerimeter() const{
        double a = B.distanceTo(C);
        double b = A.distanceTo(C);
        double c = A.distanceTo(B);
        
        return a + b + c;
    }
};

int main() {
    Point A(6, 6);

    Point B(0, 0);

    cout << A.distanceTo(B) << endl;

    cout << "A:" << endl;
    A.print();

    A.setX(-1);
    A.setY(5);

    A.print();

    cout << "B:" << endl;

    B.print();

    B.setX(A.getX());
    B.setY(A.getY());

    B.print();

    return 0;
}

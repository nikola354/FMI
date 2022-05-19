#include <iostream>
#include "cmath"

using namespace std;

struct Point {
    int x, y;

    void read() {
        cin >> this->x >> this->y;
    }

    void print() const {
        cout << "(" << this->x << ", " << this->y << ")";
    }
};

double distance(const Point &a, const Point &b);

struct Triangle {
    Point A, B, C;

private:
    double a, b, c;
    void calcArea() {
        double p = (a + b + c) / 2; // semi-perimeter

        area = sqrt(p * (p - a) * (p - b) * (p - c));
    }

public:
    double area = 0;

    bool isReal() {
        return (a + b > c && b + c > a && a + c > b);
    }

    void read() {
        A.read();
        B.read();
        C.read();

        a = distance(B, C);
        b = distance(A, C);
        c = distance(A, B);

        if (!isReal()) {
            cout << endl << "Not a real triangle!" << endl;
            return;
        }

        calcArea();
    }

    void print() const {
        cout << "A: ";
        A.print();
        cout << ", B: ";
        B.print();
        cout << ", C: ";
        C.print();
    }
};

void readTriangles(Triangle *ts, int N);

void printTriangles(const Triangle *ts, int N);

void sortByAreaASC(Triangle *ts, int N);

int main() {
    int N;
    cin >> N;

    Triangle *triangles = new Triangle[N];
    readTriangles(triangles, N);

    sortByAreaASC(triangles, N);

    printTriangles(triangles, N);

    return 0;
}

void readTriangles(Triangle *ts, int N) {
    for (int i = 0; i < N; ++i) {
        ts[i].read();
    }
}

void printTriangles(const Triangle *ts, int N) {
    for (int i = 0; i < N; ++i) {
        ts[i].print();
        cout << endl;
    }
}

//Eucledian Distance
double distance(const Point &a, const Point &b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    return sqrt(dx * dx + dy * dy);
}

void swap(Triangle &a, Triangle &b) {
    Triangle temp = a;
    a = b;
    b = temp;
}

void sortByAreaASC(Triangle *ts, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (ts[j].area < ts[i].area)
                swap(ts[i], ts[j]);
        }
    }
}

#include <math.h>

class Shape {
public:
    int shape;
    int a;
    int b;
    int c;
    double getPerimeter();
};

class Circle: public Shape {
public:
    Circle(int r) {
        this->shape = 1;
        this->a = r;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int a, int b) {
        this->shape = 2;
        this->a = a;
        this->b = b;
    }
};

class Triangle: public Shape {
public:
    Triangle(int a, int b, int c) {
        this->shape = 3;
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

double Shape::getPerimeter() {
    double result = 0;
    if (shape == 1) {
        const double PI = acos(-1);
        result = 2 * PI * a;
    }
    if (shape == 2) {
        result = a + a + b + b;
    }
    if (shape == 3) {
        if (a < (b + c) && b < (a + c) && c < (a + b)) {
            result = a + b + c;
        }
    }
    return result;
}

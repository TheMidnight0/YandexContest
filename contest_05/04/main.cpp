#include <math.h>

class Point {
public:
    double x;
    double y;
    double r;
    double a;
    void set_x(double value) {
        x = value;
        count_r();
        count_a();
    }
    void set_y(double value) {
        y = value;
        count_r();
        count_a();
    }
    void set_r(double value) {
        r = value;
        count_x();
        count_y();
    }
    void set_a(double value) {
        a = value;
        count_x();
        count_y();
    }
    double get_x() {
        return x;
    }
    double get_y() {
        return y;
    }
    double get_r() {
        return r;
    }
    double get_a() {
        return a;
    }
    void count_x() {
        x = r * cos(a);
    }
    void count_y() {
        y = r * sin(a);
    }
    void count_r() {
        r = sqrt(pow(x, 2) + pow(y, 2));
    }
    void count_a() {
        a = atan2(y, x);
    }
    Point(double coord_x, double coord_y) {
        x = coord_x;
        y = coord_y;
    }
};

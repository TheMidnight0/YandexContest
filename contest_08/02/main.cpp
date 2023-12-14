class Point {
public:
    int x;
    int y;
    void move(Point vec) {
        x += vec.x;
        y += vec.y;
    }
    Point(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }
};

class Vector {
public:
    int x;
    int y;
    operator Point() {
        return Point(x, y);
    }
    Vector(Point start, Point end) {
        x = end.x - start.x;
        y = end.y - start.y;
    }
};
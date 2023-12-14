#include <math.h>
#include <time.h>

class Cat {
public:
    bool state;
    bool is_alive();
};

class Box {
public:
    Cat open();
};

bool Cat::is_alive() {
    return state;
}

Cat Box::open() {
    Cat cat;
    cat.state = rand() % 2;
    return cat;
}
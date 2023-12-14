class Water {
public:
    int temperature;
    Water() {};
    Water(int t) {
        temperature = t;
    }
};

class Teapot {
public:
    Water water;
    void heat_up(int grad) {
        this->water.temperature += grad;
    }
    bool is_boiling() {
        if (this->water.temperature > 99) {
            return true;
        }
        else {
            return false;
        }
    }
    Teapot(Water w) {
        water = w;
    }
};

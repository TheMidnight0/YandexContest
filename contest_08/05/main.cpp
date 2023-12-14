class IntSharedPointer {
    int* count;
public:
    int* pointer;
    IntSharedPointer& operator=(IntSharedPointer& obj) {
        count--;
        if (count == 0) {
            delete pointer;
        }
        pointer = obj.pointer;
        count = obj.count;
        count++;
        return *this;
    }
    IntSharedPointer(int* point) {
        pointer = point;
        count = new int(1);
    }
    IntSharedPointer(IntSharedPointer& obj) {
        pointer = obj.pointer;
        count = obj.count;
        count++;
    }
    ~IntSharedPointer() {
        count--;
        if (count == 0) {
            delete pointer;
        }
    }
};

int& operator*(IntSharedPointer& obj) {
    return *obj.pointer;
}
#include <math.h>

class Employee {
public:
    std::string name;
    std::string state;
    int money;
    void bonus(double percent) {
        if (state == "manager" && percent < 0.1) percent = 0.1;
        salary(money * percent);
    }
    void salary(int up) {
        money = money + up;
    }
    Employee(std::string name1, std::string state1, int money1) {
        name = name1;
        state = state1;
        money = money1;
        bonus(bonuses[state]);
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, int money = 16242)
        :Employee(name, "manager", money) {
    }
};

std::ostream& operator <<(std::ostream& os, Employee& employ) {
    os << employ.name << " (" << employ.state << "): " << employ.money;
    return os;
}

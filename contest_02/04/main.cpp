#include <iostream>
#include <tuple>

std::tuple<int, int> reduce (int chisl, int znam) {
    int reducer = 1;
    for (int i = 1; i <= znam; i+= 1) {
        if (chisl%i == 0 and znam%i == 0) {
            reducer = i;
        }
    }
    chisl = chisl/reducer;
    znam = znam/reducer;
    return std::make_tuple(chisl, znam);
}

std::tuple<int, int, int> find_lcm(int fir, int sec) {
    int lcm = 0, num1 = 0, num2 = 0;
    for (int i = fir; i > -1; i+=1) {
        if (i%fir == 0 and i%sec == 0) {
            lcm = i;
            i = -2;
        }
    }
    for (int i = 1; i <= lcm; i+=1) {
        if (fir*i==lcm and num1 == 0) {
            num1 = i;
        }
        if (sec*i==lcm and num2 == 0) {
            num2 = i;
        }
        if (num1!=0 and num2!=0) {
            i = lcm;
        }
    }
    return std::make_tuple(lcm, num1, num2);
}

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}
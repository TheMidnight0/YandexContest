#include <iostream>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num%2 == 0) {
        return 0;
    }
    for (int i=3; i<=sqrt(num); i+=2) {
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
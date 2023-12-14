#include <math.h>

class Complex {
public:
    double re;
    double im;
    Complex() {}
    Complex(std::string number) {
        std::string temp;
        for (int i = 0; i <= number.length(); i++) {
            if (i == number.length()) {
                this->im = std::stod(temp);
                break;
            }
            if (number[i] == '+') {
                if (temp != "" && temp != "-") {
                    this->re = std::stod(temp);
                    temp = "";
                }
            }
            if (number[i] == '-') {
                if (temp != "" && temp != "-") {
                    this->re = std::stod(temp);
                    temp = "-";
                }
                else {
                    if (temp == "-") {
                        temp = "";
                    }
                    else {
                        temp = "-";
                    }
                }
            }
            if (number[i] != ' ' && number[i] != '+' && number[i] != '-') {
                temp += number[i];
            }
        }
    }
};

Complex operator +(Complex first, Complex second) {
    Complex result;
    result.re = first.re + second.re;
    result.im = first.im + second.im;
    return result;
}

Complex operator -(Complex first, Complex second) {
    Complex result;
    result.re = first.re - second.re;
    result.im = first.im - second.im;
    return result;
}

Complex operator *(Complex first, Complex second) {
    Complex result;
    result.re = first.re * second.re - first.im * second.im;
    result.im = first.im * second.re + first.re * second.im;
    return result;
}

Complex operator /(Complex first, Complex second) {
    Complex result;
    result.re = (first.re * second.re + first.im * second.im) / (pow(second.re, 2) + pow(second.im, 2));
    result.im = (first.im * second.re - first.re * second.im) / (pow(second.re, 2) + pow(second.im, 2));
    return result;
}

std::ostream& operator<<(std::ostream& out, const Complex& num) {
    out << (num.re == 0.0 ? 0.0 : num.re)
        << (num.im < 0 ? "" : "+")
        << (num.im == 0.0 ? 0.0 : num.im) << 'j';
    return out;
}

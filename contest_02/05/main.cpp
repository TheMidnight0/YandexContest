#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

#include <math.h>

Complex make_complex(std::string num) {
    Complex number;
    int check = 0, j;
    std::string temp;
    for (int i = 0; i < num.length(); i += 1) {
        if (num[i] == '+' or num[i] == '-') {
            if (check != 1) {
                if (num[i] == '-') {
                    if (temp == "") {
                        temp = num[i];
                    } else {
                        temp = "";
                    }
                }
            } else {
                j = i;
                i = num.length();
                number.re = stod(temp);
                
            }
        } else {
            if (num[i] != ' ') {
                temp = temp + num[i];
                check = 1;
            }
        }
    }
    temp = "";
    check = 0;
    for (int i = j; i < num.length(); i += 1) {
        if (num[i] == '+' or num[i] == '-') {
            if (check != 1) {
                if (num[i] == '-') {
                    if (temp == "") {
                        temp = num[i];
                    } else {
                        temp = "";
                    }
                }
            }
        } else {
            if (num[i] != ' ') {
                temp = temp + num[i];
                check = 1;
            }
        }
    }
    number.im = stod(temp);
    return number;
}
Complex sum(Complex c1, Complex c2) {
    Complex c3;
    c3.re = c1.re + c2.re;
    c3.im = c1.im + c2.im;
    return c3;
}
Complex sub(Complex c1, Complex c2) {
    Complex c3;
    c3.re = c1.re - c2.re;
    c3.im = c1.im - c2.im;
    return c3;
}
Complex mul(Complex c1, Complex c2) {
    Complex c3;
    c3.re = c1.re * c2.re - c1.im * c2.im;
    c3.im = c1.im * c2.re + c1.re * c2.im;
    return c3;
}
Complex div(Complex c1, Complex c2) {
    Complex c3;
    c3.re = (c1.re * c2.re + c1.im * c2.im) / (pow(c2.re, 2) + pow(c2.im, 2));
    c3.im = (c1.im * c2.re - c1.re * c2.im) / (pow(c2.re, 2) + pow(c2.im, 2));
    return c3;
}
void print(Complex num) {
    if (num.re == -0) {
        num.re = 0;
    }
    if (num.im == -0) {
        num.im = 0;
    }
    if (std::to_string(num.im)[0] == '-') {
        std::cout<<num.re<<num.im<<"j\n";
    } else {
        std::cout<<num.re<<"+"<<num.im<<"j\n";
    }
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
#include <vector>
#include <iomanip>

static const int BASE = 6;
static const int BASE10 = 1000000;

class Bigint {
private:
    std::vector<int> chunks;
    int sign;
public:
    Bigint operator + (Bigint num);
    Bigint operator - (Bigint num);
    Bigint operator * (Bigint num);
    Bigint operator / (Bigint num);
    int operator > (Bigint num);
    int operator < (Bigint num);
    int operator == (Bigint num);
    friend std::ostream& operator << (std::ostream& os, Bigint num);
    Bigint(std::string line) {
        int i;
        for (i = int(line.size()) - BASE; i >= 1; i -= BASE) {
            chunks.push_back(std::stoi(line.substr(i, BASE)));
        }
        if (line[0] == '-') {
            sign = -1;
            if (i + BASE - 1 != 0) {
                chunks.push_back(stoi(line.substr(1, i + BASE - 1)));
            }
        }
        else {
            sign = 1;
            chunks.push_back(stoi(line.substr(0, i + BASE)));
        }
    }
    Bigint(int num) {
        Bigint temp(std::to_string(num));
        chunks = temp.chunks;
        sign = temp.sign;
    }
    Bigint(std::vector<int> chunks_new, int sign_new) {
        chunks = chunks_new;
        sign = sign_new;
    }
    Bigint() {
        chunks.push_back(0);
        sign = 1;
    }
};

Bigint Bigint::operator + (Bigint second) {
    Bigint first(this->chunks, this->sign);
    int left = 0;
    if (first.sign == -1 && second.sign == 1 || first.sign == 1 && second.sign == -1) {
        second.sign = -second.sign;
        return operator -(second);
    }
    for (size_t i = 0; i < std::max(first.chunks.size(), second.chunks.size()) || left; ++i) {
        if (i == first.chunks.size())
            first.chunks.push_back(0);
        first.chunks[i] += left + (i < second.chunks.size() ? second.chunks[i] : 0);
        left = first.chunks[i] >= BASE10;
        if (left)  first.chunks[i] -= BASE10;
    }
    return first;
}

Bigint Bigint::operator - (Bigint second) {
    Bigint first(this->chunks, this->sign);
    int left = 0;
    if (first.sign == -1 && second.sign == 1 || first.sign == 1 && second.sign == -1) {
        second.sign = -second.sign;
        return operator +(second);
    }
    for (size_t i = 0; i < std::max(first.chunks.size(), second.chunks.size()); i++) {
        first.chunks[i] -= (i < second.chunks.size() ? second.chunks[i] : 0);
    }
    left = 0;
    if (first.chunks[first.chunks.size() - 1] < 0) {
        sign = -sign;
        for (int i = 0; i < first.chunks.size(); i++) {
            if (first.chunks[i] >= 0) {
                first.chunks[i] -= BASE10;
            }
            first.chunks[i] = abs(first.chunks[i]);
        }
    }
    else {
        for (int i = 0; i < first.chunks.size(); i++) {
            first.chunks[i] -= left;
            left = 0;
            if (first.chunks[i] < 0) {
                first.chunks[i] += BASE10;
                left = 1;
            }
        }
    }
    while (first.chunks.size() > 1 && first.chunks.back() == 0)
        first.chunks.pop_back();
    left = 0;
    for (int i = 0; i < first.chunks.size(); i++) {
        first.chunks[i] += left;
        left = first.chunks[i] / BASE10;
        first.chunks[i] %= BASE10;
        if (left > 0 && size_t(i + 1) == first.chunks.size()) {
            chunks.push_back(left);
            left = 0;
        }
    }
    return first;
}

Bigint Bigint::operator * (Bigint second) {
    Bigint first(this->chunks, this->sign);
    std::vector<int> temp(first.chunks.size() + second.chunks.size());
    Bigint result;
    result.chunks = temp;
    if (first.sign == -1 && second.sign == 1 || first.sign == 1 && second.sign == -1) {
        result.sign = -1;
    }
    for (size_t i = 0; i < first.chunks.size(); i++) {
        for (int j = 0, left = 0; j < int(second.chunks.size()) || left; j++) {
            long long current = result.chunks[i + j] + first.chunks[i] * 1ll * (j < int(second.chunks.size()) ? second.chunks[j] : 0) + left;
            result.chunks[i + j] = int(current % BASE10);
            left = int(current / BASE10);
        }
    }
    while (result.chunks.size() > 1 && result.chunks.back() == 0)
        result.chunks.pop_back();
    return result;
}

Bigint Bigint::operator / (Bigint second) {
    Bigint first(this->chunks, this->sign);
    if (second.chunks.size() < 2) {
        int left = 0;
        for (int i = (int)first.chunks.size() - 1; i >= 0; --i) {
            long long cur = first.chunks[i] + left * 1ll * BASE10;
            first.chunks[i] = int(cur / second.chunks[0]);
            left = int(cur % second.chunks[0]);
        }
        while (first.chunks.size() > 1 && first.chunks.back() == 0)
            first.chunks.pop_back();
        if (first.sign == -1 && second.sign == 1 || first.sign == 1 && second.sign == -1) {
            first.sign = -1;
        }
        else {
            first.sign = 1;
        }
    }
    else {
        Bigint result = second;
        Bigint count(1);
        if (first.sign == -1 && second.sign == 1 || first.sign == 1 && second.sign == -1) {
            count.sign = -1;
        }
        else {
            count.sign = 1;
        }
        Bigint plus(count.sign);
        while (result < first || result == first) {
            count = count + plus;
            result = second * count;
        }
        count = count - plus;
        first = count;
    }
    return first;
}

int Bigint::operator > (Bigint second) {
    if (this->sign == -1 && second.sign == 1) {
        return 0;
    }
    if (this->sign == 1 && second.sign == -1) {
        return 1;
    }
    for (int i = (int)this->chunks.size() - 1; i > -1; i--) {
        if (i < second.chunks.size()) {
            if (this->chunks[i] != second.chunks[i]) {
                if (this->chunks[i] > second.chunks[i]) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        else {
            return 1;
        }
    }
    return 0;
}

int Bigint::operator < (Bigint second) {
    if (this->sign == -1 && second.sign == 1) {
        return 1;
    }
    if (this->sign == 1 && second.sign == -1) {
        return 0;
    }
    for (int i = (int)this->chunks.size() - 1; i > -1; i--) {
        if (i < second.chunks.size()) {
            if (this->chunks[i] != second.chunks[i]) {
                if (this->chunks[i] < second.chunks[i]) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        else {
            return 0;
        }
    }
    return 0;
}

int Bigint::operator == (Bigint second) {
    if (this->sign == -1 && second.sign == 1 || this->sign == 1 && second.sign == -1) {
        return 0;
    }
    for (int i = (int)this->chunks.size() - 1; i > -1; i--) {
        if (i < second.chunks.size()) {
            if (this->chunks[i] != second.chunks[i]) {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    return 1;
}

std::ostream& operator << (std::ostream& os, Bigint num) {
    if (num.sign == -1) {
        os << '-';
    }
    os << num.chunks[num.chunks.size() - 1];
    for (int i = (int)num.chunks.size() - 2; i > -1; i--) {
        os << std::setw(BASE) << std::setfill('0') << num.chunks[i];
    }
    return os;
}

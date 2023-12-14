#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int total1, total2;

bool compare(std::string left, std::string right) {
    total1 = 0;
    total2 = 0;
    for (int i = 0; i < left.length(); i+= 1) {
        if (left[i] == '1') {
            total1 += 1;
        }
    }
    for (int j = 0; j < right.length(); j+= 1) {
        if (right[j] == '1') {
            total2 += 1;
        }
    }
    if (total1 > total2) {
        return true;
    }
    if (total1 < total2) {
        return false;
    }
    return stoi(left) < stoi(right);
}


int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};


Student make_student(std::string info) {
    Student result;
    std::string temp = "";
    int j;
    for (int i = 0; i < info.length(); i+= 1) {
        if (info[i] != ';') {
            temp = temp + info[i];
        } else {
            j = i;
            i = info.length();
        }
    }
    result.name = temp;
    temp = "";
    for (int i = j+1; i < info.length(); i+= 1) {
        temp = temp + info[i];
    }
    result.group = temp;
    return result;
}
bool is_upper(Student fir, Student sec) {
    if (fir.group != sec.group) {
        return fir.group < sec.group;
    } else {
        return fir.name < sec.name;
    }
}
void print(std::vector<Student> students) {
    std::string temp;
    if (students.size() == 0) {
        std::cout<<"Empty list!";
    } else {
        for (int i = 0; i < students.size(); i += 1) {
            if (temp != students[i].group) {
                temp = students[i].group;
                std::cout<<students[i].group<<"\n";
            }
            std::cout<<"- "<<students[i].name<<"\n";
        }
    }
}

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}
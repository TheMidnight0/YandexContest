#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

Student make_student(std::string info) {
    Student student;
    Course temp2;
    std::string temp;
    int info_ind = 1, course = 0;
    for (int i = 0; i <= info.length(); i+= 1) {
        if (info[i] == ';' or i == info.length()) {
            if (info_ind == 3 and course != 0) {
                temp2.finished = (bool)stoi(temp);
                student.courses.push_back(temp2);
                info_ind = 1;
                course += 1;
            } else {
                if (info_ind == 2 and course != 0) {
                    temp2.semester = stoi(temp);
                    info_ind += 1;
                } else {
                    if (info_ind == 1 and course != 0) {
                        temp2.name = temp;
                        info_ind += 1;
                    } else {
                        if (info_ind == 2 and course == 0) {
                            student.group = temp;
                            info_ind = 1;
                            course += 1;
                        } else {
                            student.name = temp;
                            info_ind += 1;
                        }
                    }
                }
            }
            temp = "";
        } else {
            temp = temp + info[i];
        }
    }
    return student;
}
bool is_upper(Student fir, Student sec) {
    if (fir.group != sec.group) {
        return fir.group < sec.group;
    } else {
        return fir.name < sec.name;
    }
}
bool is_debtor(Student student, int cur_sem, int max_deb) {
    int deb = 0;
    for (int i = 0; i < student.courses.size(); i += 1) {
        if (student.courses[i].semester < cur_sem and student.courses[i].finished == false) {
            deb += 1;
        }
    }
    if (deb > max_deb) {
        return true;
    } else {
        return false;
    }
}
void print(std::vector<Student> candidates) {
    std::string temp;
    if (candidates.size() == 0) {
        std::cout<<"Empty list!";
    } else {
        for (int i = 0; i < candidates.size(); i += 1) {
            if (temp != candidates[i].group) {
                std::cout<<candidates[i].group<<"\n";
                temp = candidates[i].group;
            }
            std::cout<<"- "<<candidates[i].name<<"\n";
        }
    }
}


int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
                 students.end(),
                 std::back_inserter(expulsion_candidates),
                 [cur_semester, max_debt](const Student& student){
                     return is_debtor(student, cur_semester, max_debt);
                 });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}
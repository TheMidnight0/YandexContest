#include <iostream>
#include <vector>
using namespace std;

bool check(string line) {
    vector<char> temp;
    char end = ' ';
    for (int i = 0; i < line.length(); i += 1) {
        if (line[i] == '(' or line[i] == '[' or line[i] == '{') {
            temp.push_back(line[i]);
            end = line[i];
        }
        if (line[i] == ')' or line[i] == ']' or line[i] == '}') {
            if (line[i] == ')' and end == '(' or line[i] == ']' and end == '[' or line[i] == '}' and end == '{') {
                temp.erase(temp.end()-1);
                end = temp[temp.size()-1];
            } else {
                return false;
            }
        }
    }
    if (temp.size() > 0) {
        return false;
    }
    return true;
}

int main()
{
    string line;
    getline(cin, line, '!');
    if (check(line)) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}
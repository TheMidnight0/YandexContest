#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> add(string line, int size) {
    vector<int> result;
    string temp = "";
    int check = 0, ind = 0;
    line = line + " ";
    for (int i = 0; i < line.length(); i += 1) {
        if (line[i] != ' ') {
            temp = temp + line[i];
            check = 1;
        } else {
            if (check == 1) {
                result.push_back(stoi(temp));
                temp = "";
                ind += 1;
                check = 0;
                if (ind+1 > size) {
                    break;
                }
            }
        }
    }
    return result;
}

int main()
{
    int size;
    string line;
    vector<int> a, b, c;
    cin>>size;
    cin.ignore(1);
    getline(cin, line);
    a = add(line, size);
    cin>>size;
    cin.ignore(1);
    getline(cin, line);
    b = add(line, size);
    for (int i = 0; i < a.size(); i += 1) {
        c.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i += 1) {
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i += 1) {
        cout<<c[i]<<" ";
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ifstream data("data.txt");
    map<string, int> words;
    map<int, string> place;
    int col[3] = { 0, 0, 0 };
    string target;
    int tumb = 0;
    cin >> target;
    string line;
    while (line != "stopword") {
        if (target == line) {
            getline(data, line, ' ');
            if (line == "stopword") {
                break;
            }
            words[line] += 1;
        }
        getline(data, line, ' ');
    }
    for (map<string, int>::iterator it = words.begin(); it != words.end(); ++it) {
        if (it->second > col[0]) {
            place[3] = place[2];
            col[2] = col[1];
            place[2] = place[1];
            col[1] = col[0];
            place[1] = it->first;
            col[0] = it->second;
        }
        else {
            if (it->second > col[1]) {
                place[3] = place[2];
                col[2] = col[1];
                place[2] = it->first;
                col[1] = it->second;
            }
            else {
                if (it->second > col[2]) {
                    place[3] = it->first;
                    col[2] = it->second;
                }
            }
        }
    }
    if (place.size() > 0) {
        for (map<int, string>::iterator it = place.begin(); it != place.end(); ++it) {
            cout << it->second << " ";
        }
    }
    else {
        cout << "-" << endl;
    }
}
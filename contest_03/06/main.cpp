#include <iostream>
#include <sstream>
#include <map>
#include <list>
using namespace std;

int main()
{
    int col;
    stringstream ss;
    string line, line2;
    map<string, string> users;
    list<string> search;
    cin >> col;
    cin.ignore(1);
    for (int i = 0; i < col; i++) {
        getline(cin, line);
        ss << line;
        getline(ss, line, ';');
        getline(ss, line2, ' ');
        users[line] = line2;
        ss.clear();
    }
    cin >> col;
    cin.ignore(1);
    getline(cin, line);
    ss << line;
    while (col != 0) {
        getline(ss, line, ' ');
        search.push_back(line);
        --col;
    }
    list<string>::iterator it;
    map<string, string>::iterator mp;
    while (search.size() != 0) {
        it = search.begin();
        cout << users.find(*it)->second << " ";
        search.pop_front();
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

set<string> make_vec(string line, int s) {
    set<string> result;
    string temp;
    stringstream ss(line);
    int i = 0;
    while ( i != s) {
        getline(ss, temp, ' ');
        result.insert(temp);
        i+= 1;
    }
    return result;
}

set<string> check(set<string> a, set<string> b) {
    set<string> result;
    set<string>::iterator it, f;
    for (it = a.begin(); it != a.end(); ++it) {
        if (b.find(*it) != b.end()) {
            result.insert(*it);
        }
    }
    return result;
}

int main()
{
    int s1, s2;
    string line;
    set<string>::iterator it;
    set<string> a, b, c;
    cin>>s1;
    cin.ignore(1);
    getline(cin, line);
    a = make_vec(line, s1);
    cin>>s2;
    cin.ignore(1);
    getline(cin, line);
    b = make_vec(line, s2);
    c = check(a, b);
    if (c.size() > 0) {
        for (it = c.begin(); it != c.end(); ++it) {
            cout<<*it<<" ";
        }
    } else {
        cout<<-1;
    }
    return 0;
}
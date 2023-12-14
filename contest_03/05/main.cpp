#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    int size, max = 0;
    string line;
    map<string, int> con;
    cin>>size;
    cin.ignore(1);
    getline(cin, line);
    stringstream ss(line);
    while (size != 0) {
        getline(ss, line, ' ');
        con[line] += 1;
        if (con[line] > max) {
            max = con[line];
        }
        --size;
    }
    for (map<string, int>::iterator it = con.begin(); it != con.end(); ++it) {
        if (it->second == max) {
            cout<< it->first <<" ";
        }
    }
    return 0;
}
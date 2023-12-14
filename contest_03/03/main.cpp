#include <iostream>
#include <vector>
using namespace std;

string do_polsk(string line) {
    vector<char> stek;
    string out, result;
    int checked = 0, j, num = 0;
    for (int i = 0; i < line.length(); i += 1) {
        if (line[i] == '+' or line[i] == '-') {
            j = stek.size()-1;
            while (j > -1) {
                if (stek[j] == '-' or stek[j] == '+' or stek[j] == '*' or stek[j] == '/' or stek[j] == '%' or stek[j] == '^') {
                    out = out + " " + stek[j];
                    stek.erase(stek.end()-1);
                } else {
                    j = -1;
                }
                j -= 1;
            }
            stek.push_back(line[i]);
            checked = 1;
        }
        if (line[i] == '*' or line[i] == '/' or line[i] == '%') {
            j = stek.size()-1;
            while (j > -1) {
                if (stek[j] == '*' or stek[j] == '/' or stek[j] == '%' or stek[j] == '^') {
                    out = out + " " + stek[j];
                    stek.erase(stek.end()-1);
                } else {
                    j = -1;
                }
                j -= 1;
            }
            stek.push_back(line[i]);
            checked = 1;
        }
        if (line[i] == '^' or line[i] == '(') {
            stek.push_back(line[i]);
            checked = 1;
        }
        if (line[i] == ')') {
            j = stek.size()-1;
            while (j > -1) {
                out = out + " " + stek[j];
                stek.erase(stek.end()-1);
                j -= 1;
                if (stek[j] == '(') {
                    stek.erase(stek.end()-1);
                    j = -1;
                }
            }
            checked = 1;
        }
        if (line[i] == '=') {
            for (int i = stek.size()-1; i > -1; i -= 1) {
                out = out + " " + stek[i];
                stek.erase(stek.end()-1);
            }
            out = out + " " + line[i];
            checked = 1;
        }
        if (checked == 0) {
            if (num == 1) {
                out = out + line[i];
            } else {
                out = out + " " + line[i];
                num = 1;
            }
        } else {
            num = 0;
        }
        checked = 0;
    }
    for (int i = stek.size()-1; i > -1; i -= 1) {
        out = out + " " + stek[i];
        stek.erase(stek.end()-1);
    }
    
    for (int i = 1; i < out.length(); i += 1) {
        result = result + out[i];
    }
    return result;
}

int main()
{
    string line, result;
    getline(cin, line);
    result = do_polsk(line);
    cout<<result;
    return 0;
}
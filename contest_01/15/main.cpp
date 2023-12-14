#include <iostream>
#include <string>
using namespace std;

int counter = 1;
string text, n, current, result;

int main()
{
    cin>>text;
    for (int i = 0; i<text.length()+1; i++) {
        n = text[i];
        if (n!=current) {
            if (counter != 1) {
                result = result + current + to_string(counter);
            }
            else {
                result = result + current;
            }
            current = n;
            counter = 1;
        }
        else {
            counter++;
        }
    }
    cout<<result;
}
#include <iostream>
#include <string>
using namespace std;

int maxh = 2, dir = 1, h, N, n, i;
string str;

int main()
{
    cin>>N;
    if (N<1 or N>1000) {
        cout<<"N cannot be less than 1 or more than 1000!";
        return 0;
    }
    while (n!=N) {
        if (h==maxh) {
            dir = 0;
            maxh++;
        }
        if (h==1) {
            dir = 1;
        }
        if (dir==1) {
            h++;
        }
        else {
            h--;
        }
        str = "";
        i = 0;
        while (i!=h) {
            n++;
            str = str + to_string(n) + " ";
            i++;
            if (n==N) {
                cout<<str;
                return 0;
            }
        }
        cout<<str<<"\n";
    }
}
#include <iostream>
using namespace std;

double a;
double b;

int main()
{
    cin>>a>>b;
    if (b == 0) {
        cout<<"b = 0!";
    }
    else {
        cout<<a / b;
    }
}
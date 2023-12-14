#include <iostream>
#include <math.h>
using namespace std;

int A, B, C, AB, AC;

int main()
{
    cin>>A>>B>>C;
    AB = abs(A-B);
    AC = abs(A-C);
    if (AB<AC) {
        cout<<"B "<<AB;
    }
    else {
        cout<<"C "<<AC;
    }
}
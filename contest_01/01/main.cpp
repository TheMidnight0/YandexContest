#include <math.h>
#include <stdio.h>

double result;

int main()
{
    result = sqrt(12)*(1.0 - (1.0/(3*3)) + (1.0/(5*pow(3,2))) - (1.0/(7*pow(3,3))) + (1.0/(9*pow(3,4))) - (1.0/(11*pow(3,5))));
    printf("%f\n",result);
}
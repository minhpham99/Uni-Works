#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    for(i = 0; i <=10; i++)
    {
        printf("2^%i = %lf\n", pow(2.0,i));
    }
}
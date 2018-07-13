#include <stdio.h>
#include <math.h>

int main()
{ 
    int a, v, ta, d1, tc, d2, d;
    
    printf("Enter the constant acceleration:");
    scanf("%i", &a);

    printf("Enter the time for this phase:");
    scanf("%i", &ta);

    d1 = (a*pow(ta,2)/2);
    
    printf("The distance for this phase is %i meters \n", d1);

    printf("Enter the constant speed for second phase:");
    scanf("%i", &v);

    printf("Enter the time for this phase:");
    scanf("%i", &tc);
    
    d2 = v*tc;

    printf("The distance for this phase is %i meters \n", d2);

    d = d1 + d2;

    printf("The total distance travelled is %i meters \n", d);

    return 0;
}
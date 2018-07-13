#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, x2, y2, distance;
    printf("Enter the first x coordinate here:");
    scanf("%f", &x1);

    printf("Enter the first y coordinate here:");
    scanf("%f", &y1);

    printf("Enter the second x coordinate here:");
    scanf("%f", &x2);

    printf("Enter the second y coordinate here:");
    scanf("%f", &y2);

    distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

    printf("The distance between these coordinates are %f units\n",distance);
    return 0;
}
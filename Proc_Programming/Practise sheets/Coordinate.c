int main(){

#include <stdio.h>
#include<math.h>

int x1, y1, x2, y2, distance;

printf("Enter the first x coordinate:");
scanf("%i", x1);
printf("Enter the first y coordinate:");
scanf("%i", y1);

printf("Enter the second x coordinate:");
scanf("%i", x2);
printf("Enter the second y coordinate:");
scanf("%i", y2);

distance = sqrt((pow((x2 - x1),2)) + (pow((y2 - y1),2)));

printf("The distance between the coordinate is %i units", distance);

return 0;
}

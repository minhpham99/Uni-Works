float main(){

#include <stdio.h>
#include<math.h>

float Diameter, Area, Perimeter;

printf("Enter the diameter:");
scanf("%f", &Diameter);

Area = pow((Diameter/2),2)*(22/7);
Perimeter = Diameter*(22/7);

printf("The area of the circle is %f square meters \n", Area);
printf("The perimeter of the circle is %f meters \ngc", Perimeter);

return 0;
}

int main()
{
#include<stdio.h>
#include<math.h>
int f, g, m1, m2, r;

printf("Enter the mass of the first object:");
scanf("%i", m1);

printf("Enter the mass of the second object:");
scanf("%i", m2);

printf("Enter the distance between them:");
scanf("%i", r);

g = 6.674*10e-11;

f = g*(m1*m2/pow(r,2));

printf("The gravitation force between the masses is %i N \n", f);

return 0;
}

int main ()
{
#include <stdio.h>
int Celsius, Farenheit;

printf("Enter the temperature in Celsius:");
scanf("%i", &Celsius);

Farenheit = (9.0/5)*Celsius+32;

printf("The temperature in Farenheit is %i F \n", Farenheit);

return 0;
}

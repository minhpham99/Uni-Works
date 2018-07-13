#include <stdio.h>

int main()
{ 
   
int number;

printf("Enter your number here:");
scanf("%i", &number);

while (number)
{
    if (number%2==0)
 {
     printf("The number is even\n");
     break;
 }   
    else
{ 
    printf("The number is odd\n");
    break;
}
}
return 0;
}
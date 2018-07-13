int main(){

#include<stdio.h>
#include<math.h>

int number;

printf("Enter your number:");
scanf("%i", number);


while (number %2) 
{
  printf("The number is even");
}
else
{
  printf("The number is odd");
}
return 0;
}

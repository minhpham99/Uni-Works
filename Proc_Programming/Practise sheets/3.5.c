#include<stdio.h>

int main()
{
  #define a (.)
  #define e (.)
  #define i (.)
  #define o (.)
  #define u (.)

  char array[50];

  printf("Enter an array:");
  scanf("%s", array);

  printf(array);

  return 0;
}

#include<stdio.h>
#include<math.h>

int sigma(int a, int b, int c)
{
  int s;

  s = a + b +c;
  return(s);
}


void main()
{
  int a,b,c;

  printf("Enter 3 arguments:");
  scanf("%i %i %i", &a,&b,&c);
  printf("The sum of all arguments is %i\n", sigma(a,b,c));
}

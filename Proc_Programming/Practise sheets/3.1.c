#include<stdio.h>

int main()
{
  int a [20];
  int n, i;

  printf("How many numbers are in your sequence?:");
  scanf("%i", &n);

  printf("Enter your sequence here, and enter -99 at the end of your sequence:");

  for (i = 0; i<n; i++)
    scanf("%i", &a[i]);

  for (i =n-1; i>=0; i--)
{
  if ( i == -99)
  break;

  else
  printf("%i,", a[i]);

}
  return 0;
}

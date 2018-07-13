#include<stdio.h>

int sigma( int a[30]; int i,n,largest; i = n = largest = 0;)
{
  printf("How many numbers are in your sequence?:");
  scanf("%i", &n);

  printf("Enter your sequence here:");

  for ( i = 0; i < n; i++)
  {
    scanf("%i", &a[i]);    
  }

  for(i = 0; i < n; i++)
  {
    if(a[i]>largest)
    {
      largest = a[i];      
    }
  }
}

int main()
{
  int largest;
  return sigma;

  printf("The largest element is %i\n", largest);

  return 0;
}

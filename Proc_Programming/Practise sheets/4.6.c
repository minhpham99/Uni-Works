#include <stdio.h>

int sigma(double a[50], int i, int n, int sum, int average)
{
    printf("How many numbers are in your sequence?:");
    scanf("%i", &n);
  
    printf("Enter your sequence here:");
  
    for ( i = 0; i < n; i++)
    {
      scanf("%lf", &a[i]);  
      sum += a[i];
      average = sum/n;
    }
}
int main()
{
    double a[50];
    int n, average, sum = 0;

    return sigma;
    printf("The average of the sequence is %i\n", average);

    return 0;
}

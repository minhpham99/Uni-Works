#include<stdio.h>
#include<math.h>

int main()
{
  int a[30];
  int i, sum, x, N;
  double mean, d, sd;

  printf("How many numbers are in your series?:");
  scanf("%i", &N);

  printf("Enter your series here:");
  for(i=1; i<=N; i++)
  {
    scanf("%i", &a[i]);
  }
  sum = 0;

  for (i=1; i<=N; i++)
  {
    sum = sum+ a[i];
    mean = (double) sum/(double) N;
    d = (1/(double)N)*pow((a[i]-mean),2);
    sd = sqrt(d);

  }
  printf("The standard deviation for the series is %.2lf\n", sd);
  return 0;
}

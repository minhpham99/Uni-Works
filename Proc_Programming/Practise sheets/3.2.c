#include<stdio.h>
#include<math.h>

int main()
{
  int a[30];
  int n, i, sum;
  float average;

  printf("How many students took the exam?:");
  scanf("%i", &n);

  printf("Enter the marks here:");
  for(i = 0; i<n; i++)
  {
    scanf("%i", &a[i]);
    sum = sum+ a[i];
    average = sum/n;

  }
  printf("The average mark is %.2f\n", average);
return 0;
}

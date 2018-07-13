#include<stdio.h>
#include<math.h>

int sigma(int x, int n, int i, int s)
{
  if(n%2 == 0)
  {
    for(i = 0; i <= n; i++)
    {
      n = n+2;      
      s += pow(x,n);
      n++;
      return (s);
    }
  }
  else
  {
    for(i = 1; i <=n; i++)
    {
      n = n+2;      
      s +=pow(x,n);
      return(s);
    }
  }
}

int main()
{
  int x, n,s,i;
  x = n = i = s = 0;

  printf("Enter x and n here:");
  scanf("%i%i", &x, &n);

  printf("The sum of series is %i\n", sigma(x,n,i,s));
}

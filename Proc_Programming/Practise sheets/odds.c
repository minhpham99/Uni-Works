#include <stdio.h>

int main()
{
int n,m,i;

    printf("Enter your first integer here:");
    scanf("%i", &n);

    printf("Enter your second integer here:");
    scanf("%i", &m);

    for (i=n; i<m; i++);
    {
        if (i%2!=0)
        { 
            printf("The odd numbers are: %i", i);
        }
    }
return 0;
}
    
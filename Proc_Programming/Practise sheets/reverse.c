#include<stdio.h>
#include<math.h>

int main()
{
    int n, reverse, remainder;

    printf("Enter an integer here:");
    scanf("%i", &n);

    while (n!=0)
    {
         remainder = n%10;
        reverse = reverse*10 + remainder;
        n /= 10;


    printf("Reversed Number = %i", reverse);

    return 0;
    }
}

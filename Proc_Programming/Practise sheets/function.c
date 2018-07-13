int main()
{
#include<stdio.h>
#include<math.h>

int y;
int x = 0.0;

y = pow(x,2) + 1;

while (x<=3)
{
    printf("x:\n",x);
    printf("y:\n",y);
    x++;
}
return 0;
}

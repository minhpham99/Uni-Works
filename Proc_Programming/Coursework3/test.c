#include<stdio.h>
#include<string.h>
void pointer_sampl(int *ptr)
{
    *ptr = *ptr +1;
}
int main()
{
    int a, b;
    a = 5;
    b = 7;
    pointer_sampl(&a);
    printf("gia tri a: %d\n", a);

    pointer_sampl(&b);
    printf("gia tri b: %d\n", b);


}
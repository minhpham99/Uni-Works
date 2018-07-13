#include <stdio.h>

typedef struct Complex
{
   double a; //real
   double b; //imaginary
}Complex; 

struct Complex ComplexMake(double real, double imaginary) //make an imaginary number from 2 parts
{
    struct Complex x;
    x.a = real; //declare the real value
    x.b = imaginary; //declare the imaginary value
    return x; 
}

// these functions calculate the real and imaginary part when performing mathematical operations with complex number
struct Complex ComplexAdd(struct Complex a, struct Complex b)
{
    struct Complex x;
    x.a = a.a + b.a;
    x.b = a.b + b.b;
    return x;
}

struct Complex ComplexMult(struct Complex a, struct Complex b)
{
    struct Complex x;
    x.a = a.a*b.a;
    x.b = a.b*b.b;
    return x;
}

struct Complex ComplexSub(struct Complex a, struct Complex b)
{
    struct Complex x;
    x.a = a.a - b.a;
    x.b = a.b - b.b;
    return x;
}

void ComplexPrint(struct Complex c) //print the imaginary number from two parts
{
    printf("%lf + %lfi",c.a,c.b);
}

int main()
{
    struct Complex t,x,y,z,w, complex_sum, complex_product, complex_sub;

    //input and read the complex numbers
    printf("For complex number t, enter the real and imaginary part:");
    scanf("%lf%lf", &t.a,&t.b);

    printf("For complex number x, enter the real and imaginary part:");
    scanf("%lf%lf", &x.a,&x.b);

    printf("For complex number y, enter the real and imaginary part:");
    scanf("%lf%lf", &y.a,&y.b);

    printf("For complex number z, enter the real and imaginary part:");
    scanf("%lf%lf", &z.a,&z.b);

    // declare and call the math functions
    complex_sum = ComplexAdd(z,t);
    complex_sub = ComplexSub(x,y);
    w = ComplexMult(complex_sum, complex_sub);
    // 
    printf("The complex number w is\n");
    ComplexPrint(w); //call the print function

}




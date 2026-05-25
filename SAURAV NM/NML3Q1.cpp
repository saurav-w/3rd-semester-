//1. Write a program to calculate integration using Trapezoidal rule.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x*x+2;
}

int main()
{
    float a, b, h, result;
	printf("---Trapezoidal  Method---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    h = b - a;

    result = (h/2) * (f(a) + f(b));

    printf("Integration = %f", result);

    return 0;
}

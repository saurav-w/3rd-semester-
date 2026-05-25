//7. Write a program to evaluate integration of a function using Gauss integration algorithm.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(-x/2);
}

int main()
{
    float a, b, x1, x2, result;
	printf("---Gauss integration---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    x1 = -0.577;
    x2 =  0.577;

    result = (b - a)/2 * ( f(((b-a)/2)*x1 + (a+b)/2)
                          + f(((b-a)/2)*x2 + (a+b)/2) );

    printf("Integration = %f", result);

    return 0;
}

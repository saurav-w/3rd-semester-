//5. Write a program to evaluate integration of a function using Simpson’s 3/8 rule.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 2+cos(2*sqrt(x));
}

int main()
{
    float a, b, h, result;
	printf("---Simpson's 3/8 Rule---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    h = (b - a)/3;

    result = (3*h/8) * (f(a) + 3*f(a+h) + 3*f(a+2*h) + f(b));

    printf("Integration = %f", result);

    return 0;
}

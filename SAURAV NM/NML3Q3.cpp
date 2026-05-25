//3. Write a program to calculate integration using Simpson’s 1/3 rule.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*x*x+2;
}

int main()
{
    float a, b, h, result;
	printf("---Simpson's 1/3 Rule---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    h = (b - a)/2;

    result = (h/3) * (f(a) + 4*f(a+h) + f(b));

    printf("Integration = %f", result);

    return 0;
}

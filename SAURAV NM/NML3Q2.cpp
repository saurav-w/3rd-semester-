//2. Write a program to calculate integration using composite Trapezoidal rule.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x);
}

int main()
{
    float a, b, h, sum = 0, result;
    int n, i;
	printf("---Composite Trapezoidal Method---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);
    printf("Enter number of subintervals: ");
    scanf("%d", &n);

    h = (b - a)/n;

    sum = f(a) + f(b);

    for(i = 1; i < n; i++)
        sum += 2 * f(a + i*h);

    result = (h/2) * sum;

    printf("Integration = %f", result);

    return 0;
}

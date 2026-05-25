//6. Write a program to evaluate integration of a function using composite Simpson’s 3/8 rule.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1/(1 + x*x);
}

int main()
{
    float a, b, h, sum = 0, result;
    int n, i;
	printf("---Composite Simpson's 3/8 Rule---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);
    printf("Enter number of subintervals (multiple of 3): ");
    scanf("%d", &n);

    h = (b - a)/n;

    sum = f(a) + f(b);

    for(i = 1; i < n; i++)
    {
        if(i % 3 == 0)
            sum += 2 * f(a + i*h);
        else
            sum += 3 * f(a + i*h);
    }

    result = (3*h/8) * sum;

    printf("Integration = %f", result);

    return 0;
}

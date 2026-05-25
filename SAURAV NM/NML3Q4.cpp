 //4. Write a program to calculate integration using composite Simpson’s 1/3 rule.
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
	printf("---Composite Simpson's 1/3 Rule---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);
    printf("Enter even number of subintervals: ");
    scanf("%d", &n);

    h = (b - a)/n;

    sum = f(a) + f(b);

    for(i = 1; i < n; i++)
    {
        if(i % 2 == 0)
            sum += 2 * f(a + i*h);
        else
            sum += 4 * f(a + i*h);
    }

    result = (h/3) * sum;

    printf("Integration = %f", result);

    return 0;
}

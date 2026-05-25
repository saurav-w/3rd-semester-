//8. Write a program to evaluate integration of a function using Romberg integration formula.
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1/(1 + x*x);
}

int main()
{
    float a, b, h, R[10][10];
    int i, j, k;
	printf("---Romberg Integration---\n");
    printf("Enter lower limit: ");
    scanf("%f", &a);
    printf("Enter upper limit: ");
    scanf("%f", &b);

    R[0][0] = (b-a)/2 * (f(a) + f(b));

    for(i = 1; i < 4; i++)
    {
        h = (b-a)/pow(2,i);
        float sum = 0;

        for(k = 1; k <= pow(2,i-1); k++)
            sum += f(a + (2*k-1)*h);

        R[i][0] = 0.5*R[i-1][0] + h*sum;

        for(j = 1; j <= i; j++)
            R[i][j] = R[i][j-1] +
            (R[i][j-1] - R[i-1][j-1])/(pow(4,j)-1);
    }

    printf("Integration = %f", R[3][3]);

    return 0;
}

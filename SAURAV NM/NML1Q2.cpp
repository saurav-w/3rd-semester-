#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^4 + x^3 - 3x - 1
double f(double x)
{
    return x*x*x*x + x*x*x - 3*x - 1;
}

// Define the derivative f'(x)
double df(double x)
{
    return 4*x*x*x + 3*x*x - 3;
}

int main()
{
    double x0, x1;
    int iteration = 0;

    printf("To find the root of x^4 + x^3 - 3x - 1 using Newton-Raphson Method\n");
    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("\nIteration\t x_n\t\t f(x_n)\t\t x_{n+1}\n");
    printf("-------------------------------------------------------------\n");

    while (1)
    {
        if (df(x0) == 0)
        {
            printf("Derivative is zero. Method fails.\n");
            return 1;
        }

        x1 = x0 - f(x0) / df(x0);
        iteration++;

        printf("%3d\t\t %.6f\t %.6f\t %.6f\n",
               iteration, x0, f(x0), x1);

        if (fabs(x1 - x0) < 0.0001)
            break;

        x0 = x1;
    }

    printf("\nThe approximate root after %d iterations: %.4f\n", iteration, x1);
    printf("Functional value at root f(x) = %.6f\n", f(x1));

    return 0;
}


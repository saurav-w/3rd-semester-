/* Fixed Point Iteration Method
   f(x) = x^4 + x^3 - 3x - 1
   Stopping condition: 4 decimal accuracy */

#include <stdio.h>
#include <math.h>

// g(x)
double g(double x)
{
    return pow(3*x + 1 - x*x*x, 0.25);
}

// f(x)
double f(double x)
{
    return x*x*x*x + x*x*x - 3*x - 1;
}

int main()
{
    double x0, x1;
    int iteration = 0;

    printf("To find the root of x^4 + x^3 - 3x - 1 using Fixed Point Iteration Method\n");
    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("\nIteration\t x_n\t\t x_{n+1}\t f(x)\n");
    printf("-------------------------------------------------------------\n");

    while (1)
    {
        x1 = g(x0);
        iteration++;

        printf("%3d\t\t %.6f\t %.6f\t %.6f\n",
               iteration, x0, x1, f(x1));

        if (fabs(x1 - x0) < 0.0001)
            break;

        x0 = x1;
    }

    printf("-------------------------------------------------------------\n");
    printf("Estimated Root = %.4f\n", x1);
    printf("Functional value at root f(x) = %.6f\n", f(x1));
    printf("Number of iterations = %d\n", iteration);

    return 0;
}


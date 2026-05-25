#include <stdio.h>
#include <math.h>

// Defining the function f(x)= x^4 + x^3 - 3x - 1
double f(double x)
{
    return (x*x*x*x) + (x*x*x) - 3*x - 1;
}

int main()
{
    double x0, x1, x2, f0, f1;
    int itr = 0, max_itr = 100;
    double tol = 0.00001;
    
    printf("To find the root of x^4 + x^3 - 3x - 1 using  Secant Method\n");

    printf("Enter first initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter second initial guess x1: ");
    scanf("%lf", &x1);

    printf("\nIteration\t x2\t\t f(x2)\n");

    do
    {
        f0 = f(x0);
        f1 = f(x1);

        if (f1 - f0 == 0)
        {
            printf("Mathematical error.\n");
            return 0;
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        printf("%d\t\t %lf\t %lf\n", itr+1, x2, f(x2));

        x0 = x1;
        x1 = x2;

        itr++;

    } while (fabs(f(x2)) > tol && itr < max_itr);

    printf("\n----- Result -----\n");
    printf("Estimated Root = %lf\n", x2);
    printf("Functional Value f(root) = %lf\n", f(x2));
    printf("Number of Iterations = %d\n", itr);

    return 0;
}

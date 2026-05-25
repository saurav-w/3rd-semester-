/* 1. Solve the equation?
2f = 3x2y
over the square domain 0 = x = 1.5 and 0 = y = 1.5 with f=0 on the boundary.
Take (h=0.5)*/
#include <stdio.h>
#include <math.h>

int main() {

    int k = 1, max_iter = 1000;
    double h = 0.5;
    double tol = 0.0001;

    // Interior grid coordinates
    double x1 = 0.5, y1 = 0.5;
    double x2 = 1.0, y2 = 0.5;
    double x3 = 0.5, y3 = 1.0;
    double x4 = 1.0, y4 = 1.0;

    // Unknowns
    double f1 = 0.0, f2 = 0.0, f3 = 0.0, f4 = 0.0;
    double pf1, pf2, pf3, pf4;
    double e1, e2, e3, e4;

    // Compute RHS automatically
    double R1 = h*h * 3 * x1*x1 * y1;
    double R2 = h*h * 3 * x2*x2 * y2;
    double R3 = h*h * 3 * x3*x3 * y3;
    double R4 = h*h * 3 * x4*x4 * y4;

	printf("---Poisson Equation---\n");
    printf("\nIter\tf1\t\tf2\t\tf3\t\tf4\n");
    printf("-------------------------------------------------------------\n");

    do {

        pf1 = f1;
        pf2 = f2;
        pf3 = f3;
        pf4 = f4;

        // Gauss-Seidel update
        f1 = 0.25 * (f2 + f3 - R1);
        f2 = 0.25 * (f1 + f4 - R2);
        f3 = 0.25 * (f1 + f4 - R3);
        f4 = 0.25 * (f2 + f3 - R4);

        e1 = fabs(f1 - pf1);
        e2 = fabs(f2 - pf2);
        e3 = fabs(f3 - pf3);
        e4 = fabs(f4 - pf4);

        printf("%d\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", k, f1, f2, f3, f4);

        k++;

    } while ((e1 > tol || e2 > tol || e3 > tol || e4 > tol) && k <= max_iter);

    printf("\nConverged Solution:\n");
    printf("f1 = %.6lf\n", f1);
    printf("f2 = %.6lf\n", f2);
    printf("f3 = %.6lf\n", f3);
    printf("f4 = %.6lf\n", f4);

    return 0;
}

/*2. Solve the following Laplace equation
?
2u/?x2 + ?2 u/?y2 = 0
within 0 = x = 3, 0 = y = 3
For the rectangular plate given as: */
#include <stdio.h>
#include <math.h>

int main() {

    float U1 = 0, U2 = 0, U3 = 0, U4 = 0;
    float oldU1, oldU2, oldU3, oldU4;
    float tol = 0.01;
    float maxError;
    int iter = 0;
    
    printf("\n----Laplace equation----\n");
    printf("\n");

    printf("Iter\tU1\t\tU2\t\tU3\t\tU4\n");

    do {
        oldU1 = U1;
        oldU2 = U2;
        oldU3 = U3;
        oldU4 = U4;

        // Gauss-Seidel Updates (correct Laplace positions)

        U1 = 0.25 * (200 + U2 + U3 + 100);
        U2 = 0.25 * (U1 + 100 + U4 + 100);
        U3 = 0.25 * (200 + U4 + 200 + U1);
        U4 = 0.25 * (U3 + 100 + 200 + U2);

        iter++;

        printf("%d\t%.4f\t%.4f\t%.4f\t%.4f\n",
               iter, U1, U2, U3, U4);

        maxError = fabs(U1 - oldU1);
        if (fabs(U2 - oldU2) > maxError)
            maxError = fabs(U2 - oldU2);
        if (fabs(U3 - oldU3) > maxError)
            maxError = fabs(U3 - oldU3);
        if (fabs(U4 - oldU4) > maxError)
            maxError = fabs(U4 - oldU4);

    } while (maxError > tol);

    printf("\nFinal Solution:\n");
    printf("U1 = %.4f\n", U1);
    printf("U2 = %.4f\n", U2);
    printf("U3 = %.4f\n", U3);
    printf("U4 = %.4f\n", U4);

    return 0;
}

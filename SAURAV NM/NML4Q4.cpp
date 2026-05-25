//4. Write a program to find a solution of linear algebraic equations using Gauss Seidel Method.
#include <stdio.h>
#include <math.h>

#define MAX 20
#define EPS 1e-6
#define MAX_ITER 1000

int main() {
    int n, i, j, iter;
    double a[MAX][MAX], x[MAX];
    double sum, error, max_error;
    int diagonally_dominant = 1;
                printf("----Gauss Seidel method---- \n");


    printf("\nEnter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix (row-wise):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Check diagonal dominance
    for(i = 0; i < n; i++) {
        sum = 0.0;
        for(j = 0; j < n; j++) {
            if(i != j)
                sum += fabs(a[i][j]);
        }

        if(fabs(a[i][i]) < sum)
            diagonally_dominant = 0;
    }

    if(diagonally_dominant)
        printf("\nSystem is diagonally dominant.\n");
    else
        printf("\nWarning: System is not diagonally dominant. Convergence not guaranteed.\n");

    // Check zero diagonal elements
    for(i = 0; i < n; i++) {
        if(a[i][i] == 0.0) {
            printf("Error: Zero found on diagonal. Cannot proceed.\n");
            return 1;
        }
    }

    // Initial guess
    printf("Enter initial guesses:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    // Gauss-Seidel Iteration
    for(iter = 1; iter <= MAX_ITER; iter++) {

        max_error = 0.0;

        for(i = 0; i < n; i++) {
            sum = 0.0;

            for(j = 0; j < n; j++) {
                if(j != i)
                    sum += a[i][j] * x[j];   // Uses updated values immediately
            }

            double x_old = x[i];
            x[i] = (a[i][n] - sum) / a[i][i];

            error = fabs(x[i] - x_old);
            if(error > max_error)
                max_error = error;
        }

        if(max_error < EPS)
            break;
    }

    if(iter > MAX_ITER) {
        printf("\nSolution did not converge within %d iterations.\n", MAX_ITER);
    } else {
        printf("\nSolution converged in %d iterations.\n", iter);
        printf("Final Solution:\n");
        for(i = 0; i < n; i++) {
            printf("x%d = %.6lf\n", i + 1, x[i]);
        }
    }

    return 0;
}

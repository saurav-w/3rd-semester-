//5. Write a program to find Eigen values using Power method.
#include <stdio.h>
#include <math.h>

#define MAX 20
#define EPS 1e-6
#define MAX_ITER 1000

int main() {
    int n, i, j, iter;
    double A[MAX][MAX], X[MAX], Y[MAX];
    double lambda_old = 0.0, lambda_new = 0.0, error;
                    printf("----Eigen values using Power method---- \n");


    printf("\nEnter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements row-wise:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter initial vector:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &X[i]);
    }

    for(iter = 1; iter <= MAX_ITER; iter++) {

        // Y = A * X
        for(i = 0; i < n; i++) {
            Y[i] = 0.0;
            for(j = 0; j < n; j++) {
                Y[i] += A[i][j] * X[j];
            }
        }

        // Find maximum absolute value in Y
        lambda_new = fabs(Y[0]);
        for(i = 1; i < n; i++) {
            if(fabs(Y[i]) > lambda_new)
                lambda_new = fabs(Y[i]);
        }

        // Normalize vector
        for(i = 0; i < n; i++) {
            X[i] = Y[i] / lambda_new;
        }

        error = fabs(lambda_new - lambda_old);

        if(error < EPS)
            break;

        lambda_old = lambda_new;
    }

    if(iter > MAX_ITER) {
        printf("\nMethod did not converge.\n");
    } else {
        printf("\nLargest Eigenvalue = %.6lf\n", lambda_new);
        printf("Corresponding Eigenvector:\n");
        for(i = 0; i < n; i++) {
            printf("x%d = %.6lf\n", i + 1, X[i]);
        }
        printf("Number of iterations = %d\n", iter);
    }

    return 0;
}

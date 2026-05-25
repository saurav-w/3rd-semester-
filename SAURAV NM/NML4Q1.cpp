/*1. Write a program to find a solution of linear algebraic equations using Gauss
elimination method.*/
#include <stdio.h>
#include <math.h>

#define MAX 20

int main() {
    int i, j, k, n;
    float a[MAX][MAX], x[MAX], sum;
        printf("----Gauss elimination method---- \n");


    printf("\nEnter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    // Forward Substitution
    for(i = 0; i < n - 1; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error! (Division by zero)\n");
            return 0;
        }

        for(j = i + 1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for(k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for(i = n - 2; i >= 0; i--) {
        sum = 0;
        for(j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Display Solution
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, x[i]);
    }

    return 0;
}

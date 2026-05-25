//2. Write a program to find a solution of linear algebraic equations using Gauss Jordan method.
#include <stdio.h>
#include <math.h>

#define MAX 20

int main() {
    int i, j, k, n;
    float a[MAX][MAX], ratio;
            printf("----Gauss Jordan method---- \n");


    printf("\nEnter number of unknowns: ");
    scanf("%d", &n);

    printf("Enter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for(i = 0; i < n; i++) {

        if(a[i][i] == 0.0) {
            printf("Mathematical Error! (Division by zero)\n");
            return 0;
        }

        // Make the diagonal element 1
        float pivot = a[i][i];
        for(j = 0; j <= n; j++) {
            a[i][j] = a[i][j] / pivot;
        }

        // Make other elements in column zero
        for(j = 0; j < n; j++) {
            if(j != i) {
                ratio = a[j][i];
                for(k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Display Solution
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, a[i][n]);
    }

    return 0;
}

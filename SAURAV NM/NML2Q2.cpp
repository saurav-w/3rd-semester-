/* Write a program to approximate the functional value at any given point x
   from given n number of data using Newton's Forward Interpolation */

#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20];
    float xp, h, u, sum, term;
    printf("----Newton's Forward Interpolation-----\n'");

    printf("\nEnter number of data points: ");
    scanf("%d", &n);

    printf("\nEnter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i][0]);
    }

    /* Forward difference table */
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    printf("\nEnter the value of x to find f(x): ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    u = (xp - x[0]) / h;

    sum = y[0][0];
    term = 1;

    for (i = 1; i < n; i++) {
        term = term * (u - (i - 1)) / i;
        sum = sum + term * y[0][i];
    }

    printf("\nApproximate value of f(%.2f) = %.4f\n", xp, sum);

    return 0;
}


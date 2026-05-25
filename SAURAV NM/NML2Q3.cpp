#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20];
    float xp, h, u, yp, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("\nEnter values of x (equally spaced):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("\nEnter corresponding values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    /* Construct Backward Difference Table */
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    printf("\nBackward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f", y[i][0]);
        for (j = 1; j <= i; j++) {
            printf("\t%.2f", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter value of x to interpolate: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    u = (xp - x[n - 1]) / h;

    yp = y[n - 1][0];
    term = 1;

    for (i = 1; i < n; i++) {
        term = term * (u + (i - 1)) / i;
        yp = yp + term * y[n - 1][i];
    }

    printf("\nInterpolated value at x = %.3f is y = %.6f\n", xp, yp);

    return 0;
}

//5. Write a program to approximate the functional value at any given x from given n no. of 
//data using Cubic Spline interpolation.
#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], h[20], a[20], b[20], c[20], d[20];
    float alpha[20], l[20], mu[20], z[20];
    float xp, result;

    printf("--- Cubic Spline Interpolation---\n");

    printf("\nEnter number of data points: ");
    scanf("%d", &n);

    printf("\nEnter x values:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = ", i);
        scanf("%f", &x[i]);
    }

    printf("\nEnter corresponding y values:\n");
    for (i = 0; i < n; i++) {
        printf("f(x%d) = ", i);
        scanf("%f", &y[i]);
    }


    for (i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

 
    for (i = 1; i < n - 1; i++) {
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) -
                   (3 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for (i = 1; i < n - 1; i++) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;


    for (j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] -
               h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
        a[j] = y[j];
    }

    printf("\nEnter the value of x to find f(x): ");
    scanf("%f", &xp);

   for (i = 0; i < n - 1; i++) {
        if (xp >= x[i] && xp <= x[i + 1]) {
            result = a[i]
                   + b[i] * (xp - x[i])
                   + c[i] * (xp - x[i]) * (xp - x[i])
                   + d[i] * (xp - x[i]) * (xp - x[i]) * (xp - x[i]);
            break;
        }
    }

    printf("\nApproximate value at x = %.3f is f(x) = %.3f\n", xp, result);

    return 0;
}

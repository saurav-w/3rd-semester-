//8. Write a program to implement least square approximation for non- linear data.
#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float x[10], y[10];
    float sx = 0, sY = 0, sxY = 0, sx2 = 0;
    float a, b, A;
    float x0, y0;
	printf("\n---Least Square Approximation (Non-Linear)---\n");
    printf("Enter number of points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    for (i = 0; i < n; i++) {
        float Y = log(y[i]);   // ln(y)
        sx += x[i];
        sY += Y;
        sxY += x[i] * Y;
        sx2 += x[i] * x[i];
    }

    b = (n * sxY - sx * sY) / (n * sx2 - sx * sx);
    A = (sY - b * sx) / n;

    a = exp(A);

    printf("\nExponential fitted curve:\n");
    printf("y = %.3f * e^(%.3f x)\n", a, b);

    printf("\nEnter value of x: ");
    scanf("%f", &x0);

    y0 = a * exp(b * x0);
    printf("Value of y = %.3f\n", y0);

    return 0;
}

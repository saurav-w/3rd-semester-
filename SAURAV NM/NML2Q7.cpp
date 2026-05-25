//7. Write a program to implement least square approximation for linear data.
#include <stdio.h>

int main() {
    int n, i;
    float x[10], y[10];
    float sx = 0, sy = 0, sxy = 0, sx2 = 0;
    float a, b, x0, y0;
    printf("\n---Least Square Approximation (Linear)---\n");

    printf("Enter number of points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++) {
    	printf("x(%d)=",i);
        scanf("%f", &x[i]);
        sx += x[i];
        sx2 += x[i] * x[i];
    }

    printf("Enter corresponding y values:\n");
    for (i = 0; i < n; i++) {
    	printf("f(x%d)=",i);
        scanf("%f", &y[i]);
        sy += y[i];
        sxy += x[i] * y[i];
    }

    b = (n * sxy - sx * sy) / (n * sx2 - sx * sx);
    a = (sy - b * sx) / n;

    printf("\nEquation of line: y = %.2f + %.2f x\n", a, b);

    printf("Enter value of x: ");
    scanf("%f", &x0);

    y0 = a + b * x0;
    printf("Value of y = %.2f\n", y0);

    return 0;
}

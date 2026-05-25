//9. Write a program to implement least square approximation polynomial data.
#include <stdio.h>

int main() {
    int n, i;
    float x[10], y[10];
    float sx = 0, sx2 = 0, sx3 = 0, sx4 = 0;
    float sy = 0, sxy = 0, sx2y = 0;
    float a, b, c;
    float x0, y0;
    	printf("\n---Least Square Approximation (Polynomial)---\n");


    printf("\nEnter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);

    for (i = 0; i < n; i++) {
        sx   += x[i];
        sx2  += x[i] * x[i];
        sx3  += x[i] * x[i] * x[i];
        sx4  += x[i] * x[i] * x[i] * x[i];
        sy   += y[i];
        sxy  += x[i] * y[i];
        sx2y += x[i] * x[i] * y[i];
    }

    float d  = n*(sx2*sx4 - sx3*sx3)
             - sx*(sx*sx4 - sx2*sx3)
             + sx2*(sx*sx3 - sx2*sx2);

    float d1 = sy*(sx2*sx4 - sx3*sx3)
             - sx*(sxy*sx4 - sx3*sx2y)
             + sx2*(sxy*sx3 - sx2*sx2y);

    float d2 = n*(sxy*sx4 - sx3*sx2y)
             - sy*(sx*sx4 - sx2*sx3)
             + sx2*(sx*sx2y - sxy*sx2);

    float d3 = n*(sx2*sx2y - sxy*sx3)
             - sx*(sx*sx2y - sxy*sx2)
             + sy*(sx*sx3 - sx2*sx2);

    a = d1 / d;
    b = d2 / d;
    c = d3 / d;

    printf("\nFitted polynomial:\n");
    printf("y = %.3f + %.3f x + %.3f x^2\n", a, b, c);

    printf("\nEnter value of x: ");
    scanf("%f", &x0);

    y0 = a + b * x0 + c * x0 * x0;
    printf("Value of y = %.3f\n", y0);

    return 0;
}

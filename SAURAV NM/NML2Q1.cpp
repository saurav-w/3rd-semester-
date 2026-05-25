/*write a program in C programming to approximate the functional value at any given (x)
 from given (n no. of data using lagrange's interpolation*/
 #include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], xp, yp = 0, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the value of x to find f(x): ");
    scanf("%f", &xp);

    for (i = 0; i < n; i++) {
        term = y[i];
        for (j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + term;
    }

    printf("\nApproximate value of f(%.2f) = %.4f\n", xp, yp);

    return 0;
}


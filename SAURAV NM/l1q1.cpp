#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^4 + x^3 - 3x - 1
double f(double x) {
    return x*x*x*x + x*x*x - 3*x - 1;
}

int main() {
    double a = 1.0, b = 2.0, c;
    int iteration = 0;

    // Check if interval is valid
    if (f(a) * f(b) >= 0) {
        printf("Invalid Interval: f(a) and f(b) must have opposite signs.\n");
        return 1;
    }

    printf("To find the root of x^4 + x^3 - 3x - 1 using Bisection Method (4 decimal digits)\n");
    printf("Initial interval: [%.3f, %.3f]\n\n", a, b);

    while ((b - a) >= 0.0001) {
        iteration++;
        c = (a + b) / 2.0;
        double fc = f(c);  // store f(c) to avoid multiple calls

        printf("Iteration %2d: a = %.4f, b = %.4f, c = %.4f, f(c) = %.4f\n", 
               iteration, a, b, c, fc);

        if (fabs(fc) < 0.0001)
            break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;
    }

    printf("\nThe approximate root after %d iterations: %.4f\n", iteration, c);
    return 0;
}


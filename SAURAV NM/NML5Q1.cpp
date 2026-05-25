/*1. Write a program to to calculate an approximate value of y when x = 0.4 given that
?y/?x = x + y and y(0) = 1.
With h=0.1 and h=0.2
Using the following algorithms.
a. Euler’s algorithm
b. Heun’s algorithm
c. RK 4th order method*/
#include <stdio.h>

//dx/dy = x+y
float f(float x, float y) {
    return x + y;
}

// Euler's Method 
float euler(float x0, float y0, float h, float xn) {
    int n = (int)((xn - x0) / h);
    float x = x0;
    float y = y0;

    for (int i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;
    }

    return y;
}

// Heun's Method 
float heun(float x0, float y0, float h, float xn) {
    int n = (int)((xn - x0) / h);
    float x = x0;
    float y = y0;
    float y_predict;

    for (int i = 0; i < n; i++) {
        y_predict = y + h * f(x, y);   
        y = y + (h / 2.0f) * (f(x, y) + f(x + h, y_predict)); 
        x = x + h;
    }

    return y;
}

// Runge-Kutta 4th Order Method 
float rk4(float x0, float y0, float h, float xn) {
    int n = (int)((xn - x0) / h);
    float x = x0;
    float y = y0;
    float k1, k2, k3, k4;

    for (int i = 0; i < n; i++) {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2.0f, y + k1/2.0f);
        k3 = h * f(x + h/2.0f, y + k2/2.0f);
        k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2.0f*k2 + 2.0f*k3 + k4) / 6.0f;
        x = x + h;
    }

    return y;
}

int main() {
    float x0 = 0.0f, y0 = 1.0f, xn = 0.4f;
    float h1 = 0.1f, h2 = 0.2f;

    printf("Step size h = 0.1\n");
    printf("Euler Method: \n y(0.4) = %.6f\n", euler(x0, y0, h1, xn));
    printf("Heun Method:  \n y(0.4) = %.6f\n", heun(x0, y0, h1, xn));
    printf("RK4 Method:   \n y(0.4) = %.6f\n\n", rk4(x0, y0, h1, xn));

    printf("Step size h = 0.2\n");
    printf("Euler Method: \n y(0.4) = %.6f\n", euler(x0, y0, h2, xn));
    printf("Heun Method:  \n y(0.4) = %.6f\n", heun(x0, y0, h2, xn));
    printf("RK4 Method:   \n y(0.4) = %.6f\n", rk4(x0, y0, h2, xn));

    return 0;
}


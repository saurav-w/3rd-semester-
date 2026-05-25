#include <stdio.h>

int main() {
    int n, i;
    float x;
   
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
   
    float a[n+1]; // coefficients a0 to an
    float b[n+1]; // intermediate results b
   
    printf("Enter the coefficients from a%d to a0:\n", n);
    for(i = n; i >= 0; i--) {
        printf("a%d: ", i);
        scanf("%f", &a[i]);
    }
   
    printf("Enter the value of x: ");
    scanf("%f", &x);
   
    // Horner's method using formula
    b[n] = a[n]; // highest degree coefficient
 
   
    printf("b%d = %.2f\n", n, b[n]);
   
    for(i = n-1; i >= 0; i--) {
        b[i] = a[i] + b[i+1] * x;
        printf("b%d = %.2f + %.2f*%.2f = %.2f\n", i, a[i], b[i+1], x, b[i]);
    }
   
    printf("\nValue of polynomial at x = %.2f is %.2f\n", x, b[0]);
   
    return 0;
}


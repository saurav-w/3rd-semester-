//9. Write a program to evaluate double integration of a function using Trapezoidal rule.
#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return x * y;   // Change function if needed
}

int main()
{
    float a, b, c, d, hx, hy, sum = 0;
    int nx, ny, i, j;

    printf("--- Double Integration using Trapezoidal Rule ---\n");

    printf("Enter x-lower and x-upper: ");
    scanf("%f %f", &a, &b);

    printf("Enter y-lower and y-upper: ");
    scanf("%f %f", &c, &d);

    printf("Enter number of subintervals nx and ny: ");
    scanf("%d %d", &nx, &ny);

    hx = (b - a) / nx;
    hy = (d - c) / ny;

    for(i = 0; i <= nx; i++)
    {
        for(j = 0; j <= ny; j++)
        {
            float x = a + i * hx;
            float y = c + j * hy;

            // Corner points
            if((i == 0 || i == nx) && (j == 0 || j == ny))
                sum += f(x, y);

            // Edge points
            else if(i == 0 || i == nx || j == 0 || j == ny)
                sum += 2 * f(x, y);

            // Interior points
            else
                sum += 4 * f(x, y);
        }
    }

    sum = (hx * hy / 4) * sum;

    printf("Double Integration = %f\n", sum);

    return 0;
}

#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

void drawEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main() {
    int xc, yc, a, b;
    cout << "Enter point (xc, yc):";
    cin >> xc >> yc;
    cout << "Enter (rx, ry):";
    cin >> a >> b;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double x = 0;
    double y = b;

    double a2 = a * a;
    double b2 = b * b;

    double dx = 2 * b2 * x;
    double dy = 2 * a2 * y;

    double p1 = b2 - (a2 * b) + 0.25 * a2;

    cout << "\nRegion I Table\n";
    cout << "k\tPIk\t(xk+1,yk+1)\t2*ry^2*xk+1\t2*rx^2*yk+1\n";
    cout << "------------------------------------------------------\n";

    int k = 0;
    while (dx < dy) {
        double curr_p1 = p1;
        int new_x, new_y;

        if (curr_p1 < 0) {
            new_x = x + 1;
            new_y = y;
            p1 = p1 + 2 * b2 * new_x + b2;
        } else {
            new_x = x + 1;
            new_y = y - 1;
            p1 = p1 + 2 * b2 * new_x - 2 * a2 * new_y + b2;
        }

        cout << k << "\t" << curr_p1 << "\t(" << new_x << "," << new_y << ")\t\t"
             << 2 * b2 * new_x << "\t\t" << 2 * a2 * new_y << "\n";

        x = new_x;
        y = new_y;
        drawEllipsePoints(xc, yc, x, y);

        k++;
        dx = 2 * b2 * x;
        dy = 2 * a2 * y;
    }

    double p2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;

    cout << "\nRegion II Table\n";
    cout << "k\tPIIk\t(xk+1,yk+1)\t2*ry^2*xk+1\t2*rx^2*yk+1\n";
    cout << "------------------------------------------------------\n";

    k = 0;
    while (y >0) {
        double curr_p2 = p2;
        int new_x, new_y;

        if (curr_p2 > 0) {
            new_x = x;
            new_y = y - 1;
            p2 = p2 - 2 * a2 * new_y + a2;
        } else {
            new_x = x + 1;
            new_y = y - 1;
            p2 = p2 + 2 * b2 * new_x - 2 * a2 * new_y + a2;
        }

        cout << k << "\t" << curr_p2 << "\t(" << new_x << "," << new_y << ")\t\t"
             << 2 * b2 * new_x << "\t\t" << 2 * a2 * new_y << "\n";

        x = new_x;
        y = new_y;
        drawEllipsePoints(xc, yc, x, y);

        k++;
    }

    getch();
    closegraph();
}

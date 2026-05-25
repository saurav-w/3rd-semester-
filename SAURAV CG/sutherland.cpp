#include <graphics.h>
#include <iostream>
using namespace std;

// Region code bits
const int INSIDE = 0; // 0000
const int LEFT   = 1; // 0001
const int RIGHT  = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP    = 8; // 1000

// Clipping window boundaries
int xmin, ymin, xmax, ymax;

// Compute 4-bit code
int computeCode(double x, double y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

// Cohen-Sutherland using slope intersection formulas
void clipLine(double x1, double y1, double x2, double y2) {
    int OP1 = computeCode(x1, y1);
    int OP2 = computeCode(x2, y2);
    double m; // slope
    bool accept = false;

    while (true) {
        // Case 1: completely inside
        if ((OP1 | OP2) == 0) {
            accept = true;
            break;
        }
        // Case 2: completely outside
        else if (OP1 & OP2) {
            break;
        }
        // Case 3: partially inside
        else {
            int outcode = OP1 ? OP1 : OP2;
            double x, y;

            // Avoid divide by zero for vertical lines
            if (x2 != x1)
                m = (y2 - y1) / (x2 - x1);
            else
                m = 1e10; // treat as infinite slope

            // Vertical boundary
            if (outcode & LEFT) {
                x = xmin;
                y = y1 + m * (x - x1);
            } else if (outcode & RIGHT) {
                x = xmax;
                y = y1 + m * (x - x1);
            }
            // Horizontal boundary
            else if (outcode & BOTTOM) {
                y = ymin;
                x = x1 + (y - y1) / m;
            } else if (outcode & TOP) {
                y = ymax;
                x = x1 + (y - y1) / m;
            }

            // Replace outside endpoint and recompute code
            if (outcode == OP1) {
                x1 = x; y1 = y;
                OP1 = computeCode(x1, y1);
            } else {
                x2 = x; y2 = y;
                OP2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        cout << "Clipped line coordinates: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    } else {
        cout << "Line is completely outside the clipping window." << endl;
    }
}

int main() {
    double x1 = 60, y1 = 90;
    double x2 = 130, y2 = 140;

    xmin = 90; ymin = 90;
    xmax = 150; ymax = 130;

    cout << "Original line coordinates: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;

    initwindow( 500, 500, "Cohen-Sutherland Line Clipping");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    delay(2000);

    // Apply clipping
    clipLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

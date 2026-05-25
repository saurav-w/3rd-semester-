#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cout << "Enter (x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter (x2,y2): ";
    cin >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int Xin = x1, Yin = y1;

    // Determine step directions
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;

    int p;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int k = 0;
    cout << "K\tPk\t(Xk+1,Yk+1)" << endl;

    if (dx > dy) { // Slope < 1
        p = 2 * dy - dx;
        putpixel(Xin, Yin, WHITE);

        while (Xin != x2) {
            Xin += sx;
            if (p < 0) {
                p += 2 * dy;
            } else {
                Yin += sy;
                p += 2 * (dy - dx);
            }
            cout << k << "\t" << p << "\t(" << Xin << "," << Yin << ")" << endl;
            putpixel(Xin, Yin, WHITE);
            k++;
        }
    } else { // Slope >= 1
        p = 2 * dx - dy;
        putpixel(Xin, Yin, WHITE);

        while (Yin != y2) {
            Yin += sy;
            if (p < 0) {
                p += 2 * dx;
            } else {
                Xin += sx;
                p += 2 * (dx - dy);
            }
            cout << k << "\t" << p << "\t(" << Xin << "," << Yin << ")" << endl;
            putpixel(Xin, Yin, WHITE);
            k++;
        }
    }

    getch();
    closegraph();
    return 0;
}

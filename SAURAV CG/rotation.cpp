#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int maxx = getmaxx();
    int maxy = getmaxy();

    // Draw X and Y axis
    setcolor(LIGHTGRAY);
    line(0, maxy/2, maxx, maxy/2);   // X-axis
    line(maxx/2, 0, maxx/2, maxy);   // Y-axis

    // Origin shift
    int ox = maxx / 2;
    int oy = maxy / 2;

    // Original triangle points
    int x1 = ox + 40, y1 = oy - 70;
    int x2 = ox + 50, y2 = oy - 50;
    int x3 = ox + 30, y3 = oy - 60;

    // Take pivot point from user
    int px, py;
    cout << "Enter pivot point (x y): ";
    cin >> px >> py;

    // Convert pivot to graphics coordinates
    int xp = ox + px;
    int yp = oy - py;

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Draw pivot point
    setcolor(YELLOW);
    circle(xp, yp, 4);

    // Convert degree to radian
    float angle = 45 * 3.14159 / 180;

    // Rotate points
    int x1r = xp + (x1 - xp) * cos(angle) - (y1 - yp) * sin(angle);
    int y1r = yp + (x1 - xp) * sin(angle) + (y1 - yp) * cos(angle);
  
    int x2r = xp + (x2 - xp) * cos(angle) - (y2 - yp) * sin(angle);
    int y2r = yp + (x2 - xp) * sin(angle) + (y2 - yp) * cos(angle);

    int x3r = xp + (x3 - xp) * cos(angle) - (y3 - yp) * sin(angle);
    int y3r = yp + (x3 - xp) * sin(angle) + (y3 - yp) * cos(angle);

    // Draw rotated triangle
    setcolor(RED);
    line(x1r, y1r, x2r, y2r);
    line(x2r, y2r, x3r, y3r);
    line(x3r, y3r, x1r, y1r);

    getch();
    closegraph();
    return 0;
}



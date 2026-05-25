#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

bool liangBarsky(int xmin, int ymin, int xmax, int ymax,
                 int x1, int y1, int x2, int y2,
                 float &cx1, float &cy1, float &cx2, float &cy2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    float t1 = 0.0, t2 = 1.0;

    for(int i = 0; i < 4; i++)
    {
        if(p[i] == 0)
        {
            if(q[i] < 0)
                return false;   // Line parallel and outside
        }
        else
        {
            float t = q[i] / p[i];

            if(p[i] < 0)
            {
                if(t > t2) return false;
                if(t > t1) t1 = t;
            }
            else
            {
                if(t < t1) return false;
                if(t < t2) t2 = t;
            }
        }
    }

    cx1 = x1 + t1 * dx;
    cy1 = y1 + t1 * dy;
    cx2 = x1 + t2 * dx;
    cy2 = y1 + t2 * dy;

    return true;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "");

    // Clipping window
    int xmin = 150, ymin = 150;
    int xmax = 350, ymax = 350;

    // Line endpoints
    int x1 = 100, y1 = 200;
    int x2 = 400, y2 = 300;

    float cx1, cy1, cx2, cy2;

    // Print original line coordinates
    cout << "Original line coordinates: (" << x1 << ", " << y1 << ") to ("
         << x2 << ", " << y2 << ")" << endl;

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    getch();

    // Apply Liang-Barsky
    if(liangBarsky(xmin, ymin, xmax, ymax,
                   x1, y1, x2, y2,
                   cx1, cy1, cx2, cy2))
    {
        // Print clipped line coordinates
        cout << "Clipped line coordinates: (" << cx1 << ", " << cy1 << ") to ("
             << cx2 << ", " << cy2 << ")" << endl;

        setcolor(GREEN);
        line(cx1, cy1, cx2, cy2);
    }
    else
    {
        cout << "Line is completely outside the clipping window." << endl;
    }

    getch();
    closegraph();
    return 0;
}

#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct Point
{
    float x, y;
};

int xmin, ymin, xmax, ymax;

/* Check if point is inside a clipping edge */
bool inside(Point p, int edge)
{
    switch (edge)
    {
    case 0: return p.x >= xmin; // Left
    case 1: return p.x <= xmax; // Right
    case 2: return p.y >= ymin; // Bottom
    case 3: return p.y <= ymax; // Top
    }
    return false;
}

/* Find intersection point */
Point intersect(Point p1, Point p2, int edge)
{
    Point i;
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    switch (edge)
    {
    case 0: // Left
        i.x = xmin;
        if (dx != 0) i.y = p1.y + dy * (xmin - p1.x) / dx;
        else i.y = p1.y; // vertical line
        break;

    case 1: // Right
        i.x = xmax;
        if (dx != 0) i.y = p1.y + dy * (xmax - p1.x) / dx;
        else i.y = p1.y; // vertical line
        break;

    case 2: // Bottom
        i.y = ymin;
        if (dy != 0) i.x = p1.x + dx * (ymin - p1.y) / dy;
        else i.x = p1.x; // horizontal line
        break;

    case 3: // Top
        i.y = ymax;
        if (dy != 0) i.x = p1.x + dx * (ymax - p1.y) / dy;
        else i.x = p1.x; // horizontal line
        break;
    }
    return i;
}

/* Clip polygon against one edge */
int clip(Point in[], int n, Point out[], int edge)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        Point curr = in[i];
        Point prev = in[(i + n - 1) % n];

        bool curr_in = inside(curr, edge);
        bool prev_in = inside(prev, edge);

        if (prev_in && curr_in)
        {
            out[k++] = curr;
        }
        else if (prev_in && !curr_in)
        {
            Point inter = intersect(prev, curr, edge);
            // Avoid duplicate
            if (k == 0 || !(inter.x == out[k-1].x && inter.y == out[k-1].y))
                out[k++] = inter;
        }
        else if (!prev_in && curr_in)
        {
            Point inter = intersect(prev, curr, edge);
            if (k == 0 || !(inter.x == out[k-1].x && inter.y == out[k-1].y))
                out[k++] = inter;
            out[k++] = curr;
        }
    }
    return k;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "");

    int n;
    Point poly[20], temp[20], curr[20];

    cout << "Enter clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    cout << "Enter number of polygon vertices: ";
    cin >> n;

    cout << "Enter polygon vertices (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> poly[i].x >> poly[i].y;

    // Print original polygon vertices
    cout << "Original polygon vertices:\n";
    for (int i = 0; i < n; i++)
        cout << "(" << poly[i].x << ", " << poly[i].y << ")\n";

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original polygon in RED
    setcolor(RED);
    for (int i = 0; i < n; i++)
        line(poly[i].x, poly[i].y,
             poly[(i + 1) % n].x, poly[(i + 1) % n].y);

    getch();

    // Copy original polygon
    for (int i = 0; i < n; i++) curr[i] = poly[i];

    int clipped_n = n;

    // Clip against all 4 edges
    for (int edge = 0; edge < 4; edge++)
        clipped_n = clip(curr, clipped_n, temp, edge),
        copy(temp, temp + clipped_n, curr);

    // Print clipped polygon vertices
    cout << "Clipped polygon vertices:\n";
    for (int i = 0; i < clipped_n; i++)
        cout << "(" << curr[i].x << ", " << curr[i].y << ")\n";

    // Draw clipped polygon in GREEN
    setcolor(GREEN);
    for (int i = 0; i < clipped_n; i++)
        line(curr[i].x, curr[i].y,
             curr[(i + 1) % clipped_n].x, curr[(i + 1) % clipped_n].y);

    // Highlight vertices with YELLOW circles
    setcolor(YELLOW);
    for (int i = 0; i < clipped_n; i++)
        circle(curr[i].x, curr[i].y, 3);

    getch();
    closegraph();
    return 0;
}

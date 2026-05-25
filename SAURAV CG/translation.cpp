#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    initwindow(900, 650, "Triangle Translation with Matrix");

    int Ax = 100, Ay = 100;
    int Bx = 150, By = 50;
    int Cx = 200, Cy = 100;

    int tx, ty;
    cout << "Enter translation values (x y): ";
    cin >> tx >> ty;

    // Original triangle
    setcolor(WHITE);
    line(Ax, Ay, Bx, By);
    line(Bx, By, Cx, Cy);
    line(Cx, Cy, Ax, Ay);
    outtextxy(90, 110, (char*)"Original Triangle");

    // Translated points
    int A1x = Ax + tx, A1y = Ay + ty;
    int B1x = Bx + tx, B1y = By + ty;
    int C1x = Cx + tx, C1y = Cy + ty;

    // Translated triangle
    setcolor(CYAN);
    line(A1x, A1y, B1x, B1y);
    line(B1x, B1y, C1x, C1y);
    line(C1x, C1y, A1x, A1y);
    outtextxy(A1x - 10, A1y + 10, (char*)"Translated Triangle");
    
    setcolor(CYAN);
    outtextxy(520, 60, (char*) "3 x 3 Translation Matrix");
    
    char buffer[50];
    
    sprintf(buffer, "[ 1  0  %d ]", tx);
    outtextxy(520, 90, buffer);
    
    sprintf(buffer, "[ 0  1  %d ]", ty);
    outtextxy(520, 120, buffer);
    
    sprintf(buffer, "[ 0   0   1 ]");
    outtextxy(520, 150, buffer);
    
    getch();
    closegraph();
    return 0;
}

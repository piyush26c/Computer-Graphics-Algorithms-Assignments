//
// Created by piyush on 4/2/19.
//

#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

class Pixel
{
public :
    void drawPixel(int x, int y, int colour);

};

void Pixel::drawPixel(int x, int y, int colour) {
    putpixel(x, y, 5);
}

//inheriting pixle class
class FillAlgorithms : public Pixel
{
public:
    int width, height, X, Y;
    void getParameters();
    void drawDDALine(float x1, float y1, float x2, float y2);
    void floodFill(int x, int y, int old, int fillColour);
    void boundaryFill(int x, int y, int fillColour, int backgroundColour);

};

void FillAlgorithms::drawDDALine(float x1, float y1, float x2, float y2) {
    float x, y, dx, dy, steps, xm, ym, xin, yin;
    x = x1;
    y = y1;
    drawPixel(x,y,3);
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) >= abs(dy))
        steps = dx;
    else
        steps = dy;
    xin = (float)(dx / steps);
    yin = (float)(dy / steps);
    for(int i = 1;i <= steps; i++)
    {
        x  = x + xin;
        y  = y + yin;
        xm = x + 0.5;
        ym = y + 0.5;
        drawPixel(xm, ym, 3);
    }
}



void FillAlgorithms::boundaryFill(int x, int y, int fillColour, int backgroundColour) {
    if((getpixel(x,y)!=backgroundColour) && (getpixel(x,y)!=fillColour))
    {
        putpixel(x,y,fillColour);
        delay(1);
        boundaryFill((x) + 1, y, fillColour, backgroundColour);
        boundaryFill(x, (y) + 1, fillColour, backgroundColour);
        boundaryFill((x) - 1, y, fillColour, backgroundColour);
        boundaryFill(x, (y) - 1, fillColour, backgroundColour);
    }
}

void FillAlgorithms::floodFill(int x, int y, int oldColour, int fillColour) {
    int current = getpixel(x,y);
    if(current == oldColour)
    {
        putpixel(x,y,fillColour);
        delay(10);
        floodFill(x - 1, y, oldColour, fillColour);
        floodFill(x + 1, y, oldColour, fillColour);

        floodFill(x, y + 1, oldColour, fillColour);
        floodFill(x, y - 1, oldColour, fillColour);
    }
}

void FillAlgorithms::getParameters()
{
    cout << "\nEnter the X-Coordinate : ";
    cin >> X;
    cout << "\nEnter the Y-Coordinate : ";
    cin >> Y;
    cout << "\nEnter the Heigth       : ";
    cin >> height;
    cout << "\nEnter the Width        : ";
    cin >> width;

}


int main()
{
    FillAlgorithms f;

    int sw, dw, xm, ym, xm1, ym1;
    int gd=DETECT,gm;

    do
    {
        dw = 1;
        cout << "\nFill Algorithms ";
        cout << "\nEnter (1). Flood Fill Algorithm";
        cout << "\nEnter (2). Boundary Fill Algorithm";
        cout << "\nEnter (3). Exit";
        cin >> sw;

        switch(sw)
        {
            case 1:
                cout << "\nEnter the X-Coordinate : ";
                cin >> f.X;
                cout << "\nEnter the Y-Coordinate : ";
                cin >> f.Y;
                cout << "\nEnter the Heigth       : ";
                cin >> f.height;
                cout << "\nEnter the Width        : ";
                cin >> f.width;
                initgraph(&gd,&gm,NULL);
                f.drawDDALine(f.X, f.Y, f.X, f.Y+f.height);
                f.drawDDALine(f.X, f.Y+f.height, f.X+f.width, f.Y+f.height);
                f.drawDDALine(f.X+f.width, f.Y, f.X+f.width, f.Y+f.height);
                f.drawDDALine(f.X, f.Y, f.X+f.width, f.Y);
                xm = f.X+10;
                ym = f.Y+10;
                f.floodFill(xm, ym, 3, 5);
                break;

            case 2 :
                cout << "\nEnter the X-Coordinate : ";
                cin >> f.X;
                cout << "\nEnter the Y-Coordinate : ";
                cin >> f.Y;
                cout << "\nEnter the Heigth       : ";
                cin >> f.height;
                cout << "\nEnter the Width        : ";
                cin >> f.width;
                initgraph(&gd,&gm,NULL);
                f.drawDDALine(f.X, f.Y, f.X, f.Y+f.height);
                f.drawDDALine(f.X, f.Y+f.height, f.X+f.width, f.Y+f.height);
                f.drawDDALine(f.X+f.width, f.Y, f.X+f.width, f.Y+f.height);
                f.drawDDALine(f.X, f.Y, f.X+f.width, f.Y);
                xm1 = f.X+10;
                ym1 = f.Y+10;
                f.floodFill(xm1, ym1, 3, 5);
                f.boundaryFill(xm1, ym1, 3, 5);
                break;


            case 3:
                dw = 0;
                break;
        }


    }while(dw);

    getchar();
    closegraph();

    return 0;

}
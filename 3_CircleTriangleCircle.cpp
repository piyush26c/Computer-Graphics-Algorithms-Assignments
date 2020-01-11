//
// Created by piyush on 2/25/19.
//

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

#define R 0.866025404           //value of root3by2
#define callInitgraph int gd=DETECT,gm; initgraph(&gd,&gm,NULL);

class CircleTriangleCircle
{

private:

    float XC1,YC1,radius1;

public:
    void getCircleCoordinates();
    void bresenhamCircle(float XC,float YC, float radius);
    void DDALine(float X1, float Y1, float X2, float Y2);
    void compute();
};

void CircleTriangleCircle::compute()
{
    callInitgraph;
    bresenhamCircle(XC1,YC1,radius1);
    //bresenhamLine(0,0,640,480);
    DDALine(XC1 - R * radius1, YC1 + radius1 * 0.5, XC1, YC1 - radius1);
    DDALine(XC1 - R * radius1, YC1 + radius1 * 0.5, XC1 + R * radius1, YC1 + 0.5 * radius1);
    DDALine(XC1 + R * radius1, YC1 + 0.5 * radius1, XC1, YC1 - radius1);
    bresenhamCircle(XC1,YC1,radius1*0.5);
}
void CircleTriangleCircle::getCircleCoordinates()
{
    cout << "\nEnter the Center Coordinates of Circle ";
    cout << "\nEnter X Co-ordinate : ";
    cin >> XC1;
    cout << "\nEnter Y Co-ordinate : ";
    cin >> YC1;
    cout << "\nEnter the Radius of Circle : ";
    cin >> radius1;

}

void CircleTriangleCircle::DDALine(float X1, float Y1, float X2, float Y2)
{
    float dx,dy,step,xin,yin,x,y;

    dx = X2 - X1;
    dy = Y2 - Y1;

    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    xin = (dx) / step;
    yin = (dy) / step;

    x = X1;
    y = Y1;

    for(int i = 0; i < step; ++i)
    {
        x = x + xin;
        y = y + yin;
        round(x);
        round(y);
        putpixel(x,y,GREEN);
        delay(30);
    }

    delay(1000);
}


void CircleTriangleCircle::bresenhamCircle(float XC,float YC, float radius)
{

    //calculating first initial decision parameter
    int d = 3 - (2 * radius);
    //initial point
    int x = 0;
    int y = radius;

    putpixel(XC+x, YC+y, 4);

    while(x <= y)
    {
        if(d<0)
        {
            x = x + 1;
            y = y;
            d = d + (4 * x) + 6;

        }
        else
        {
            x = x + 1;
            y = y - 1;
            d = d + (4 * x) - (4 * y) + 10;
        }
        //this are the eight arcs to be drawn by using eight way symmetry;
        putpixel(XC+x, YC+y, 4);
        putpixel(XC+y, YC+x, 4);
        putpixel(XC+y, YC-x, 4);
        putpixel(XC+x, YC-y, 4);
        putpixel(XC-x, YC-y, 4);
        putpixel(XC-y, YC-x, 4);
        putpixel(XC-y, YC+x, 4);
        putpixel(XC-x, YC+y, 4);
        delay(30);
    }
}


int main()
{
    CircleTriangleCircle c;

    int dw, sw;

    do {

        dw = 1;
        cout << "\n(1). To get circle parameters ";
        cout << "\n(2). To draw circle ";
        cout << "\n(3). To Exit ";
        cin >> sw;

        switch(sw)
        {
            case 1:
                c.getCircleCoordinates();
                break;

            case 2:
                c.compute();
                break;
            case 3:
                dw = 0;
                break;

            default:
                cout << "\nInvalid Input";

        }
    }while  (dw);

    return 0;
}

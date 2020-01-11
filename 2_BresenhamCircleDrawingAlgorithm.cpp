//
// Created by piyush on 2/25/19.
//

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

/*
outside point is positive and inner point is negative
Inorder, if di is negative then outside point is choosen
and if di is positive then inner point is taken into consideration.
*/

class Pixel
{
public :
    void drawPixel(int x, int y, int z);

};

void Pixel::drawPixel(int x, int y, int z) {
    putpixel(x, y, 5);
}

//inheriting pixle class
class BresenhamCircle : public Pixel
{
public :
    int r, xc, yc;

    //accepting the radius and the centre from the user
    void getData();

    void circle(int xc, int yc, int r);

};

void BresenhamCircle::circle(int xc, int yc, int r) {

    //calculating first initial decision parameter
    int d = 3 - (2 * r);
    //initial point
    int x = 0;
    int y = r;

    drawPixel(xc + x, yc + y, 4);

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
        drawPixel(xc + x, yc + y, 4);
        drawPixel(xc + y, yc + x, 4);
        drawPixel(xc + y, yc - x, 4);
        drawPixel(xc + x, yc - y, 4);
        drawPixel(xc - x, yc - y, 4);
        drawPixel(xc - y, yc - x, 4);
        drawPixel(xc - y, yc + x, 4);
        drawPixel(xc - x, yc + y, 4);
        delay(30);


    }
}

void BresenhamCircle::getData() {
    cout << "\nEnter the radius of the circle : ";
    cin >> r;
    cout << "\nEntre the cordinates of the centre : ";
    cin >> xc >> yc;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    //calling circle drawing function
    circle(xc, yc, r);
}

int main()
{

    BresenhamCircle b1;
    b1.getData();
    getch();
    closegraph();
    return 0;
}
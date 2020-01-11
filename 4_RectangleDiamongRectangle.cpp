//
// Created by piyush on 2/25/19.
//

#include <bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define callInitgraph int gd=DETECT,gm; initgraph(&gd,&gm,NULL);

//line drawing algorithm (DDALine)
class LineDrawingAlgorithms
{
public:
    float a, b, c, d; //vertices of rectangle
    void getVerticesOfRectangle();
    void drawRectangleDiamongRectangle();
    void DDALine(float x1, float y1, float x2, float y2);
};

void LineDrawingAlgorithms::DDALine(float x1, float y1, float x2, float y2)
{

    float x,y,xin,yin,dx,dy,step;
    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy) || abs(dx) == abs(dy))
        step = dx;
    else
        step = dy;

    xin = dx / step;
    yin = dy / step;

    x = x1;
    y = y1;
    putpixel(x,y,WHITE);

    for(int i = 0; i < step; i++)
    {
        x=x+xin;
        y=y+yin;
        round(x);
        round(y);
        delay(10);
        putpixel(x,y,WHITE);

    }

}

void LineDrawingAlgorithms::getVerticesOfRectangle()
{
    //accepting two co-ordinates from user
    cout<<"\nEnter the coordinates of upper left vertex of rectangle (xu,yu)  :";
    cin>>a>>b;
    cout<<"\nEnter the coordinates of lower right vertex of rectangle (xl,yl) :";
    cin>>c>>d;
}

void LineDrawingAlgorithms::drawRectangleDiamongRectangle()
{
    float l1,l2,p,q,r,s;

    //calculating middle point of lenth side and breadth side for diamaond shape inside outer-rectangle
    l1=(b+d)/2;
    l2=(a+c)/2;

    //calculating middle point of each half calculated in above for inner-rectangle
    p=(a+l2)/2;
    q=(b+l1)/2;
    r=(l2+c)/2;
    s=(l1+d)/2;


    callInitgraph;
    //creates the outer rectangle
    DDALine(a, b, c, b);
    DDALine(c, b, c, d);
    DDALine(a, b, a, d);
    DDALine(a, d, c, d);

    //creates inner diamond

    DDALine(a, l1, l2, b);
    DDALine(l2, b, c, l1);
    DDALine(a, l1, l2, d);
    DDALine(l2, d, c, l1);

    //drawing the inner inner rectangle
    DDALine(p, q, r, q);
    DDALine(r, q, r, s);
    DDALine(p, q, p, s);
    DDALine(p, s, r, s);

    delay(10000);
}

int main()
{
    cout<<"\n******FIGURE DRAWING********\n";


    //line drawing dda class object
    LineDrawingAlgorithms r1;

    int dw, sw;

    do {

        dw = 1;
        cout << "\n(1). To get rectangle coordinates ";
        cout << "\n(2). To draw rectangle-diamond-rectangle ";
        cout << "\n(3). To Exit ";
        cin >> sw;

        switch(sw)
        {
            case 1:
                r1.getVerticesOfRectangle();
                break;

            case 2:
                r1.drawRectangleDiamongRectangle();
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
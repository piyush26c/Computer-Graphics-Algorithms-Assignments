//
// Created by piyush on 2/20/19.
//

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

class FormsOfLines{

private:
    float  X1,X2,Y1,Y2;

public:
    void drawDottedLine();
    void drawDashedLine();
    void drawDashDotLine();
    void drawThickLine(int thickness);
    void getLineCoordinates();

};

void FormsOfLines::drawThickLine(int w) {

    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int wy;
    int dx, dy, step, xin, yin, x, y;

    dx = X2 - X1;
    dy = Y2 - Y1;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    xin = (dx) / step;
    yin = (dy) / step;

    x = X1;
    y = Y1;

    for (int i = 0; i < step; i++) {
        x = x + xin;
        y = y + yin;
        round(x);
        round(y);

        int p = X2 - X1;
        int q = Y2 - Y1;

        wy = (w - 1) * (sqrt(pow(p, 2) + pow(q, 2))) / (2 * p);
        for (int i1 = 0; i1 < wy; i1++) {
            putpixel(x, y + i1, GREEN);
            putpixel(x, y - i1, GREEN);
        }


    }
    delay(1000);
}



void FormsOfLines::drawDottedLine()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

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

    putpixel(x,y,15);
    for(int i = 1; i <= step; i=i+1)
    {
        x = x + xin;
        y = y + yin;

        if(i%2==0)
        {
            putpixel(round(x),round(y),15);
        }

        delay(30);
    }

    delay(1000);

}

void FormsOfLines::drawDashedLine()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

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
    putpixel(x,y,15);
    for(int i = 1; i <= step; i = i + 1 )
    {
        x = x + xin;
        y = y + yin;

        putpixel(round(x),round(y),15);
        if(i%5==0)
        {
            x++;
            y++;

        }

    }

    delay(1000);

}

void FormsOfLines::drawDashDotLine()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

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
    putpixel(x,y,15);
    for(int i = 1; i <= step; ++i)
    {

        x = x + xin;
        y = y + yin;


        if(i%10!=5 && i%10!=7)
        {
            putpixel(x,y,15);

        }


    }

    delay(1000);
}

void FormsOfLines::getLineCoordinates()
{
    cout << "\nEnter First  Coordinate of Line : ";
    cout << "\n X1 : ";
    cin >> X1;
    cout << "\n Y1 : ";
    cin >> Y1;
    cout << "\nEnter Second Coordinate of Line : ";
    cout << "\n X2 : ";
    cin >> X2;
    cout << "\n Y2 : ";
    cin >> Y2;
}


int main()
{

    FormsOfLines f;
    int dw,sw, thickness;

    do
    {
        dw = 1;
        cout << "\n(1). To Get Line Coordiates ";
        cout << "\n(2). To Draw Dotted Line ";
        cout << "\n(3). To Draw Dashed Line ";
        cout << "\n(4). To Draw DottedDashed Line ";
        cout << "\n(5). To Draw Thick Line ";
        cout << "\n(6). To Exit ";
        cin >> sw;

        switch(sw)
        {
            case 1:
                f.getLineCoordinates();
                break;

            case 2:
                f.drawDottedLine();
                break;

            case 3:
                f.drawDashedLine();
                break;

            case 4:
                f.drawDashDotLine();
                break;

            case 5:
                cout << "\nEnter the value of the thickness ";
                cin >> thickness;
                f.drawThickLine(thickness);
                break;

            case 6:
                dw = 0;
                break;


            default:
                cout << "\nInvalid Input!";
        }
    }while (dw);




}

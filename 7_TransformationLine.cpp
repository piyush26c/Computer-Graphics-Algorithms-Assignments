//
// Created by piyush on 4/1/19.
//

#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;

#define callInitgraph int gd=DETECT,gm; initgraph(&gd,&gm,NULL);

/*
 * BLUE  = 1
 * GREEN = 2
 * RED   = 4
 */
class TransformationOfLine
{
private :
    int X1,Y1,X2,Y2;
public :
    void DDALine(int x1, int y1, int x2, int y2, int colour);
    void translation();
    void scalingOfLine();
    void rotationOfLine();
    void getCoordinates();

};
void TransformationOfLine :: rotationOfLine()
{

    int z, p, q, r, s;
    p = X1;
    q = Y1;
    r = X2;
    s = Y2;

    float theta; //this angle is in degree we are supposed to convert it into radian
    cout << "\nEnter the Value of Angle(Degree) : ";
    cin >> theta;

    float r11, r12, r21, r22, xn, yn;
    r11=cos((theta*3.1428)/180);
    r12=sin((theta*3.1428)/180);
    r21=(sin((theta*3.1428)/180));
    r22=cos((theta*3.1428)/180);



    cout << "\nEnter (1). To rotate line Clockwise ";
    cout << "\nEnter (2). To rotate line Anticlockwise ";
    cin >> z;
    switch(z)
    {
        case 1:
            xn = ((r*r11)-(s*r12));
            yn = ((r*r12)+(s*r11));
            break;

        case 2:
            xn = ((r*r11)+(s*r12));
            yn = ((s*r11)-(r*r12));
            break;

    }

    callInitgraph;

    DDALine(p, q, r, s, 1);
    cout << "Line after Rotation";
    DDALine(p, q, xn, yn, 2);
    delay(60);
    closegraph();
}



void TransformationOfLine :: scalingOfLine()
{
    int sx, sy;

    cout << "\nEnter the Scaling Co-ordinates ";
    cout << "\nEnter sx : ";
    cin >> sx;
    cout << "\nEnter sy : ";
    cin >> sy;

    int p, q, r, s;
    p = X1;
    q = Y1;
    r = X2;
    s = Y2;

    callInitgraph;
    cout << "\nLine Before Scaling : ";
    DDALine(p, q, r, s, 1);
    p = p * sx;
    q = q * sy;
    r = r * sx;
    s = s * sy;

    cout << "\nLine After Scaling : ";
    DDALine(p, q, r, s, 2);
    delay(60);
    closegraph();

}

void TransformationOfLine :: getCoordinates()
{
    cout << "\nEnter the X1 : ";
    cin >> X1;
    cout << "\nEnter the Y1 : ";
    cin >> Y1;
    cout << "\nEnter the X2 : ";
    cin >> X2;
    cout << "\nEnter the Y2 : ";
    cin >> Y2;

}

void TransformationOfLine :: DDALine(int x1, int y1, int x2, int y2, int colour)
{
    float dx, dy, step, xin, yin, x, y;

    callInitgraph;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    xin = (dx) / step;
    yin = (dy) / step;

    x = x1;
    y = y1;
    putpixel((x), (y),colour);
    for(int i = 1; i <= step; ++i)
    {
        x = x + xin;
        y = y + yin;

        putpixel(round(x), round(y),colour);

    }

    delay(500);

}

void TransformationOfLine :: translation()
{
    int tx, ty;

    cout << "\nEnter the Translational Co-ordinates ";
    cout << "\nEnter tx : ";
    cin >> tx;
    cout << "\nEnter ty : ";
    cin >> ty;
    int p, q, r, s;
    p = X1;
    q = Y1;
    r = X2;
    s = Y2;

    callInitgraph;
    cout << "\nLine Before Translation : ";
    DDALine(p, q, r, s, 1);
    p = p + tx;
    q = q + ty;
    r = r + tx;
    s = s + ty;

    cout << "\nLine After Translation : ";
    DDALine(p, q, r, s, 2);
    delay(60);
    closegraph();


}




int main()
{

    TransformationOfLine t;
    int sw, dw;

    do
    {
        dw = 1;
        cout << "\nEnter (1). Enter Co-ordinates";
        cout << "\nEnter (2). Translation";
        cout << "\nEnter (3). Scaling ";
        cout << "\nEnter (4). Rotation";
        cout << "\nEnter (5). Exit";

        cin >> sw;

        switch(sw)
        {

            case 1 :
                t.getCoordinates();
                break;

            case 2 :
                t.translation();
                break;


            case 3 :
                t.scalingOfLine();
                break;

            case 4 :
                t.rotationOfLine();
                break;

            case 5 :
                dw = 0;
                break;
        }


    }while(dw);


    return 0;
}

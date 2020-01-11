//
// Created by piyush on 4/2/19.
//

#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;

#define callInitgraph int gd=DETECT,gm; initgraph(&gd,&gm,NULL);

class TransformationOfEquilatralTriangle
{
private :
    double X1,Y1,X2,Y2,X3,Y3;
public :
    void DDALine(double x1, double y1, double x2, double y2, int colour);
    void translation();
    void scaling();
    void rotation();
    void shear();
    void getCoordinates();
};

void TransformationOfEquilatralTriangle :: rotation()
{

    int z;

    double p, q, r, s,u, v;
    p = X1;	//rotating about origin
    q = Y1;	//rotating about origin
    r = X2;
    s = Y2;
    u = X3;
    v = Y3;


    double theta; //this angle is in degree we are supposed to convert it doubleo radian
    cout << "\nEnter the Value of Angle(Degree) : ";
    cin >> theta;

    double r11, r12, r21, r22, xn, yn, xn1, yn1;
    r11 = cos((theta*3.1428)/180);
    r12 = sin((theta*3.1428)/180);
    r21 = sin((theta*3.1428)/180);
    r22 = cos((theta*3.1428)/180);

    cout << "\nEnter (1). To rotate line Clockwise ";
    cout << "\nEnter (2). To rotate line Anticlockwise ";
    cin >> z;
    switch(z)
    {
        case 1:
            xn = ((u*r11)-(v*r12));
            yn = ((u*r12)+(v*r11));
            //maximum we can rotate only by 30 degrees
            xn1 = ((r*r11)-(s*r12));
            yn1 = ((r*r12)+(s*r11));

            break;

        case 2:
            xn = ((r*r11)+(s*r12));
            yn = ((s*r11)-(r*r12));
            //maximum we can rotate only by 30 degrees
            xn1 = ((u*r11)-(v*r12));
            yn1 = ((u*r12)+(v*r11));
            break;

    }

    callInitgraph;

    DDALine(p, q, r, s, 1);
    DDALine(r, s, u, v, 1);
    DDALine(u, v, p, q, 1);
    cout << "Line after Rotation";

    DDALine(p, q, xn, yn, 2);			//to have different colour
    DDALine(p, q, xn1, yn1, 2);
    DDALine(xn1, yn1, xn, yn, 2);
    closegraph();
}

void TransformationOfEquilatralTriangle :: scaling()
{
    double sx, sy;

    cout << "\nEnter the Scaling Co-ordinates ";
    cout << "\nEnter sx : ";
    cin >> sx;
    cout << "\nEnter sy : ";
    cin >> sy;

    callInitgraph;
    double p, q, r, s,u, v;
    p = X1;
    q = Y1;
    r = X2;
    s = Y2;
    u = X3;
    v = Y3;

    cout << "\nEquilateral Before Scaling : ";
    DDALine(p, q, r, s, 1);
    DDALine(r, s, u, v, 1);
    DDALine(u, v, p, q, 1);
    p = p * sx;
    q = q * sy;
    r = r * sx;
    s = s * sy;
    u = u * sx;
    v = v * sy;

    cout << "\nEquilateral After Scaling : ";
    DDALine(p, q, r, s, 2);
    DDALine(r, s, u, v, 2);
    DDALine(u, v, p, q, 2);
    closegraph();

}

void TransformationOfEquilatralTriangle :: getCoordinates()
{
    cout << "\nEnter the X1 : ";
    cin >> X1;
    cout << "\nEnter the Y1 : ";
    cin >> Y1;
    cout << "\nEnter the X2 : ";
    cin >> X2;
    cout << "\nEnter the Y2 : ";
    cin >> Y2;
    cout << "\nEnter the X3 : ";
    cin >> X3;
    cout << "\nEnter the Y3 : ";
    cin >> Y3;

}

void TransformationOfEquilatralTriangle :: DDALine(double x1, double y1, double x2, double y2, int colour)
{
    float dx, dy, step, xin, yin, x, y;


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
    for(double i = 1; i <= step; ++i)
    {
        x = x + xin;
        y = y + yin;

        putpixel(round(x), round(y),colour);

    }

    delay(500);

}



void TransformationOfEquilatralTriangle :: translation()
{
    double tx, ty;

    cout << "\nEnter the Translational Co-ordinates ";
    cout << "\nEnter tx : ";
    cin >> tx;
    cout << "\nEnter ty : ";
    cin >> ty;

    callInitgraph;
    double p, q, r, s,u, v;
    p = X1;
    q = Y1;
    r = X2;
    s = Y2;
    u = X3;
    v = Y3;
    cout << "\nTriangle Before Translation : ";
    DDALine(p, q, r, s, 1);
    DDALine(r, s, u, v, 1);
    DDALine(u, v, p, q, 1);
    p = p + tx;
    q = q + ty;
    r = r + tx;
    s = s + ty;
    u = u + tx;
    v = v + ty;

    cout << "\nLine After Translation : ";
    DDALine(p, q, r, s, 2);
    DDALine(r, s, u, v, 2);
    DDALine(u, v, p, q,2);

    delay(100);
    closegraph();

}

void TransformationOfEquilatralTriangle::shear()
{
    float x1,y1,x2,y2,x3,y3,x4,y4;
    int flag,shx,shy;
    x1=100;
    y1=100;
    x2=150;
    y2=100;
    x3=150;
    y3=150;
    x4=100;
    y4=150;

    cout<<"\nBefore shearing :";
    callInitgraph;
    DDALine(x1,y1,x2,y2,1);
    DDALine(x2,y2,x3,y3,1);
    DDALine(x3,y3,x4,y4,1);
    DDALine(x4,y4,x1,y1,1);

    cout<<"\nEnter 1.For x-shear 2.For y-shear :";
    cin>>flag;

    if(flag==1)
    {
        cout<<"\nEnter the x-shear :";
        cin>>shx;

        cout<<"\nAfter shearing :";
        DDALine(x1+(shx*y1),y1,x2+(shx*y2),y2,2);
        DDALine(x2+(shx*y2),y2,x3+(shx*y3),y3,2);
        DDALine(x3+(shx*y3),y3,x4+(shx*y4),y4,2);
        DDALine(x4+(shx*y4),y4,x1+(shx*y1),y1,2);
        delay(3000);
    }
    else if(flag==2)
    {
        cout<<"\nEnter the y-shear :";
        cin>>shy;

        cout<<"\nAfter shearing :";
        DDALine(x1,y1+(shy*x1),x2,y2+(shy*x2),2);
        DDALine(x2,y2+(shy*x2),x3,y3+(shy*x3),2);
        DDALine(x3,y3+(shy*x3),x4,y4+(shy*x4),2);
        DDALine(x4,y4+(shy*x4),x1,y1+(shy*x1),2);
        delay(3000);
    }
    closegraph();
}


int main()
{

    TransformationOfEquilatralTriangle t;
    int sw, dw;

    do
    {
        dw = 1;
        cout << "\nEquilateral Triangle ";
        cout << "\nEnter (1). Enter Co-ordinates";
        cout << "\nEnter (2). Translation";
        cout << "\nEnter (3). Scaling ";
        cout << "\nEnter (4). Rotation";
        cout << "\nEnter (5). Shear";
        cout << "\nEnter (6). Exit";

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
                t.scaling();
                break;

            case 4 :
                t.rotation();
                break;
            case 5:
                t.shear();
                break;
            case 6 :
                dw = 0;
                break;
        }


    }while(dw);


    return 0;
}

/*
 * Input :  [0,0], [0, 50], [43.30, 25]
 *  [restriction] : can't rotate more than 30 degrees in anticlockwise
 */

//
// Created by piyush on 4/2/19.
//

#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;

#define callInitgraph int gd=DETECT,gm; initgraph(&gd,&gm,NULL);

void bezier(int x[],int y[])
{
    double t;
    callInitgraph;
    //bezier curve for flower
    for(t=0.0;t<1.0;t=t+0.005)
    {
        double xt = pow(1-t,3)*x[0]+3*t*pow((1-t),2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];

        double yt = pow(1-t,3)*y[0]+3*t*pow((1-t),2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];

        putpixel(xt,yt,5);

    }
    delay(50);

}
void bezier1(int x[],int y[])
{
    //simple bezier curve
    double t;
    callInitgraph;

    for(t=0.0;t<1.0;t=t+0.005)
    {
        double xt = pow(1-t,2)*x[0]+2*t*pow((1-t),1)*x[1]+1*pow(t,2)*x[2];

        double yt = pow(1-t,2)*y[0]+2*t*pow((1-t),1)*y[1]+1*pow(t,2)*y[2];

        putpixel(xt,yt,5);
        delay(50);
    }
    getch();
    closegraph();
}
int main()
{
    int a;
    cout<<"\nENTER \n1.BEZIER CURVE\n2.FLOWER\nENTER YOUR CHOICE::";
    cin>>a;
    switch(a)
    {
        case 1:
            int x5[3],y5[3];
            x5[0] = 190, x5[1] = 220, x5[2] = 250;
            y5[0] = 50, y5[1] = 90, y5[2] = 50;
            bezier1(x5,y5);
            break;
        case 2:
            int x1[4],y1[4];
            int x2[4],y2[4];
            int x3[4],y3[4];
            int x4[4],y4[4];
            cout<<"Enter four coordinates";

            x1[0]=200, x1[1]=160, x1[2]=240, x1[3]=200;
            y1[0]=200, y1[1]=160, y1[2]=160, y1[3]=200;
            x2[0]=200, x2[1]=240, x2[2]=240, x2[3]=200;
            y2[0]=200, y2[1]=160, y2[2]=240, y2[3]=200;
            x3[0]=200, x3[1]=240, x3[2]=160, x3[3]=200;
            y3[0]=200, y3[1]=240, y3[2]=240, y3[3]=200;
            x4[0]=200, x4[1]=160, x4[2]=160, x4[3]=200;
            y4[0]=200, y4[1]=240, y4[2]=160, y4[3]=200;

            //call for four petals
            bezier(x1,y1);
            bezier(x2,y2);
            bezier(x3,y3);
            bezier(x4,y4);
            //line for as a stem
            line(200,230,200,300);

            delay(10000);
            getch();
            closegraph();
            break;
    }
}



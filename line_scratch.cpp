//this code helps you to draw a line and change its orientation with the keys 'w''a''s''d'. this program uses dda algorithm.

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int round(float a)
{
    a=(int)(a+0.5);
    return a;
}
void draw(int points[100][100])
{  for(int i=0; i<23; i++)
    {
        for(int j=0; j<70; j++)
        {
            if(points[j][i]==1)
            {
                cout<<"#";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

}
void dda_algorithm(float x1, float y1, float x2, float y2)
{
int points[100][100];
    for(int k=0; k<100; k++)
      {
         for(int j=0; j<100; j++)
         points[k][j]=0;
      }
    points[(int)x1][(int)y1]=1;
    points[(int)x2][(int)y2]=1;

    float dx=x2-x1;
    float dy=y2-y1;
    int x,y;
    float steps;
    if(abs(dx)>abs(dy))
    {
        steps=abs(dx);
    }
    else if(abs(dx)<abs(dy))
    {
        steps=abs(dy);
    }
    else{
        steps=abs(dx);
    }
    float x_inc=((dx)/steps);
    float y_inc=((dy)/steps);
    x=(int)x1;
    y=(int)y1;
    for(int i=0; i<=steps; i++)
    {
        points[x][y]=1;
        x1=(x1+x_inc);
        y1=(y1+y_inc);
        x=round(x1);
        y=round(y1);


    }
draw(points);
}
int main()
{
int points[100][100]={0};
int oneminus=-1;
int counter_movement;
 int x1=7,x2=2,y1=8,y2=5;
while(1)
{
  dda_algorithm(x1,y1,x2,y2);


   if(_kbhit())
    {

        switch(_getch())
        {
        case 'w':
        case 'W':
            if(counter_movement==1)
            {
                points[x2][--y2]=1;
            }
            else{points[x1][--y1]=1;}
            break;
        case 's':
        case 'S':
           if(counter_movement==1)
            {
                points[x2][++y2]=1;
            }
            else{points[x1][++y1]=1;}
            break;
        case 'd':
        case 'D':
          if(counter_movement==1)
            {
                points[++x2][y2]=1;
            }
            else{points[++x1][y1]=1;}
            break;
        case 'a':
        case 'A':
           if(counter_movement==1)
            {
                points[--x2][y2]=1;
            }
            else{points[--x1][y1]=1;}
            break;
        case 'v':
        case 'V':
            counter_movement=-1*oneminus;
            oneminus=-1*oneminus;
            break;
        default:
            break;

        }

    }
    system("cls");
}


    return 0;
}

//the following code can change the orientation and lengths of quadrilaterals with 'w'a'd's'.this program uses dda algortithm .
//to swap the four points press'v
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
                cout<<"0";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

}
void dda_algorithm_quad(float x1, float y1, float x2, float y2)
{
 static int c=0;
 static int points[100][100];
if(c==4)
{
    for(int k=0; k<100; k++)
      {
         for(int j=0; j<100; j++)
         {
            if(points[j][k]==1)
            {
                points[j][k]=0;
            }
         }
      }
      c=0;
}


      c++;
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
   if(c==4)
{
    draw(points);

}

}
int main()
{
int points[100][100]={0};
int oneminus=-1;
int counter_movement=4;
 int x1=5,x2=8,y1=4,y2=4,x3=8,y3=9,x4=5,y4=9;

while(1)
{
 dda_algorithm_quad(x1,y1,x2,y2);
 dda_algorithm_quad(x2,y2,x3,y3);
 dda_algorithm_quad(x3,y3,x4,y4);
 dda_algorithm_quad(x4,y4,x1,y1);

   if(_kbhit())
    {
        n1:
        switch(_getch())
        {
        case 'w':
        case 'W':
            if(counter_movement==1)
            {
                points[x2][--y2]=1;
            }
            else if(counter_movement==4)
                {
                    points[x1][--y1]=1;
                }
                else if(counter_movement==2)
                {
                    points[x3][--y3]=1;
                }
                else if(counter_movement==3)
                {
                    points[x4][--y4]=1;
                }
            break;
        case 's':
        case 'S':
              if(counter_movement==1)
            {
                points[x2][++y2]=1;
            }
            else if(counter_movement==4)
                {
                    points[x1][++y1]=1;
                }
                else if(counter_movement==2)
                {
                    points[x3][++y3]=1;
                }
                else if(counter_movement==3)
                {
                    points[x4][++y4]=1;
                }

            break;
        case 'd':
        case 'D':
              if(counter_movement==1)
            {
                points[++x2][y2]=1;
            }
            else if(counter_movement==4)
                {
                    points[++x1][y1]=1;
                }
                else if(counter_movement==2)
                {
                    points[++x3][y3]=1;
                }
                else if(counter_movement==3)
                {
                    points[++x4][y4]=1;
                }

            break;
        case 'a':
        case 'A':
              if(counter_movement==1)
            {
                points[--x2][y2]=1;
            }
            else if(counter_movement==4)
                {
                    points[--x1][y1]=1;
                }
                else if(counter_movement==2)
                {
                    points[--x3][y3]=1;
                }
                else if(counter_movement==3)
                {
                    points[--x4][y4]=1;
                }

            break;
        case 'v':
        case 'V':
            counter_movement++;
            if(counter_movement>4)
            {
                counter_movement=1;
            }
            break;
        default:
            goto n1;
            break;

        }

    }
    else
    {
        goto n1;
    }
    system("cls");
}


    return 0;
}

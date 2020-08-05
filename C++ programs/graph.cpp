#include <math.h>
#include "graphics.h"

 const int width=800,height =600;
 void drawline(int moveTox,int moveToy,int drawx,int drawy,int color,int textx,int texty,char *name)
 {

     moveto(moveTox,moveToy);
     setcolor(color);
     lineto(drawx,drawy);
     outtextxy(textx,texty,name);

 }
 int main()
 {
     double x,y;
     initwindow(width,height);
     moveto(width/2,height/2);
     for(x=0;x<width;x+=0.01)
     {
         y=pow(x,4);
         setcolor(14);
         lineto(width/2+(x*100),height/2-(y*100));
     }

     getch();
     closegraph();
     system("pause");
     return 0;
 }

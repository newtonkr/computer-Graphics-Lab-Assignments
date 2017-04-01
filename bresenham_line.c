/*
Newton kumar
1401CS29

*/



#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double X1,Y1,X2,Y2;

void Bresenham(void)
{
double dx = X2 - X1;
double dy = Y2 - Y1;
dx = abs(dx);
dy = abs(dy);
double d = 2*dy - dx ;
double d_east = 2*dy;
double d_north_east = 2*(dy-dx);
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
glVertex2d(X1,Y1);
double x=X1,y=Y1;
while(x<X2)
{

	if(d<0)
	{
		d=d+d_east;
	}
	else
	{
		if(d>0)
		{
		d=d+d_north_east;
		y++;
		}
		x++;
		glVertex2d(round(x),round(y));
	}
}
glEnd();
glFlush();
}



void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}




int main(int argc, char **argv)
{
	
	printf("\n");
	printf("enter point1 (X1 , Y1) : ");
	scanf("%lf%lf",&X1,&Y1);
	printf("\nEnter point2 (X2 ,Y2) : ");
	scanf("%lf%lf",&X2,&Y2);
	printf("\n");
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("bresenham  Line drawing window ");
  Init();
  glutDisplayFunc(Bresenham);
  glutMainLoop();
  return 0;

}

//g++ bresenham.c -lglut -lGL -lGLEW -lGLU -o b
//./b

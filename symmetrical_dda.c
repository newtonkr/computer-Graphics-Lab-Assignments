/*
Newton kumar
1401CS29

*/



#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double X1,Y1,X2,Y2;
void symmetricalDDA(void)
{
double dx = X2 - X1;
double dy = Y2 - Y1;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
while(dx>=1 || dy>=1){
	dx/=2;
	dy/=2;
}


glVertex2d(X1,Y1);
double x=X1,y=Y1;
double x1,x2;
int i;
for(i=0;x<X2 && y<Y2;i++)
{
x=x+dx;
y=y+dy;
x1=round(x);
x2=round(y);
glVertex2d(x1,x2);
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
  glutCreateWindow("symmetrical DDA window ");
  Init();
  glutDisplayFunc(symmetricalDDA);
  glutMainLoop();
  return 0;

}


//g++ symmetrical_dda.c -lglut -lGL -lGLEW -lGLU -o sym_dda
//./sym_dda

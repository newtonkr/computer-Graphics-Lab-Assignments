/*
Newton kumar
1401CS29

*/



#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double X1,Y1,X2,Y2;
double MaxFunc(double a,double b)
{
if(a>b)
	return a;
else
	return b;
}
void SimpleDDA(void)
{
double dx = X2 - X1 ;
double dy = Y2 - Y1 ;
double max = MaxFunc(abs(dx),abs(dy));
dx = dx/max;
dy = dy/max;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_STRIP);
glVertex2d(X1,Y1);
int k;
double x=X1,y=Y1;
  for(k=0;k<max;k++)
  {
    x = x + dx;
    y = y + dy;
    glVertex2d(round((float) x), round((float) y));
  }
glEnd();
glFlush();
}
void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,640,0,240);
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
	glutInitWindowSize(640,240);
	glutInitWindowPosition(200,100);
	glutCreateWindow("simple DDA");
	Init();
	glutDisplayFunc(SimpleDDA);
	glutMainLoop();
	return 0;

}

//g++ simple_dda.c -lglut -lGL -lGLEW -lGLU -o s_dda
//./s_dda

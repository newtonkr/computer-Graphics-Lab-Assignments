/*
Newton kumar
1401CS29

*/



#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double xc,yc,r;

  
void drawcircle()
{
 	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	double x=0;
    double y=r;
    double d=1.25-r;
           
    while(x<y)
    {
    		   glVertex2d(xc+x,yc+y);
               glVertex2d(xc+y,yc+x);
	           glVertex2d(xc-y,yc+x);
	           glVertex2d(xc-x,yc+y);
	           glVertex2d(xc-x,yc-y);
	           glVertex2d(xc-y,yc-x);
	           glVertex2d(xc+y,yc-x);
	           glVertex2d(xc+x,yc-y);
			      if(d<0)
			      {
			       x=x+1;
			       d=d+(2*x)+3;
			      }
			      else
			     {
			       x=x+1;
			       y=y-1;
			       d=d+(2*x)-(2*y)+5;
			     }
               
			     break;
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
	printf("enter center of the circle (X0 , Y0) : ");
	scanf("%lf%lf",&xc,&yc);
	printf("\nEnter radius of the circle : ");
	scanf("%lf",&r);
	printf("\n");
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,240);
	glutInitWindowPosition(200,100);
	glutCreateWindow("circle drawing");
	Init();
	glutDisplayFunc(drawcircle);
	glutMainLoop();
	return 0;

}


//g++ bresenham_circle.c -lglut -lGL -lGLEW -lGLU -o c_dda
//./c_dda

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
# define PI 3.14
float T[4][4];
float I[8][3]={{80,80,-100},{180,80,-100},{180,180,-100},{80,180,-100},{60,60,0},{160,60,0},{160,160,0},{60,160,0}};
float O[8][3];

void Draw(float a[8][3])                 //Display the Figure
{
	int i;
   	glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
	for(i=-1000;i<=1000;i++)
	{
		glVertex2s(i,0);
		glVertex2s(0,i);
	}
 	glEnd();
 
 glColor3f (0.7, 0.4, 0.7);
 glBegin(GL_POLYGON);       
 glVertex3f(a[0][0],a[0][1],a[0][2]);
 glVertex3f(a[1][0],a[1][1],a[1][2]);
 glVertex3f(a[2][0],a[2][1],a[2][2]);
 glVertex3f(a[3][0],a[3][1],a[3][2]);
 glEnd();
 i=0;
 glColor3f (0.8, 0.6, 0.5);
 glBegin(GL_POLYGON);       
 glVertex3s(a[0+i][0],a[0+i][1],a[0+i][2]);
 glVertex3s(a[1+i][0],a[1+i][1],a[1+i][2]);
 glVertex3s(a[5+i][0],a[5+i][1],a[5+i][2]);
 glVertex3s(a[4+i][0],a[4+i][1],a[4+i][2]);
 glEnd();
 glColor3f (0.2, 0.4, 0.7);
 glBegin(GL_POLYGON);       
 glVertex3f(a[0][0],a[0][1],a[0][2]);
 glVertex3f(a[3][0],a[3][1],a[3][2]);
 glVertex3f(a[7][0],a[7][1],a[7][2]);
 glVertex3f(a[4][0],a[4][1],a[4][2]);
 glEnd();
 i=1;
 glColor3f (0.5, 0.4, 0.3);
 glBegin(GL_POLYGON);       
 glVertex3s(a[0+i][0],a[0+i][1],a[0+i][2]);
 glVertex3s(a[1+i][0],a[1+i][1],a[1+i][2]);
 glVertex3s(a[5+i][0],a[5+i][1],a[5+i][2]);
 glVertex3s(a[4+i][0],a[4+i][1],a[4+i][2]);
 glEnd();
 i=2;
 glColor3f (0.5, 0.6, 0.2);
 glBegin(GL_POLYGON);       
 glVertex3s(a[0+i][0],a[0+i][1],a[0+i][2]);
 glVertex3s(a[1+i][0],a[1+i][1],a[1+i][2]);
 glVertex3s(a[5+i][0],a[5+i][1],a[5+i][2]);
 glVertex3s(a[4+i][0],a[4+i][1],a[4+i][2]);
 glEnd();
 i=4;
 glColor3f (0.7, 0.3, 0.4);
 glBegin(GL_POLYGON);       
 glVertex3f(a[0+i][0],a[0+i][1],a[0+i][2]);
 glVertex3f(a[1+i][0],a[1+i][1],a[1+i][2]);
 glVertex3f(a[2+i][0],a[2+i][1],a[2+i][2]);
 glVertex3f(a[3+i][0],a[3+i][1],a[3+i][2]);
 glEnd();
}

void TransformationDisplay(void)
{
	int i;
	for(i=0;i<8;i++)
	{
		printf("%f %f %f\n",I[i][0],I[i][1],I[i][3]);
		printf("%f %f %f\n",O[i][0],O[i][1],O[i][3]);
	}
	

    glClear (GL_COLOR_BUFFER_BIT);
    Draw(I);
    Draw(O);
    glFlush();
}

void m()
{
int r=0,i,j;
for(r=0;r<8;r++)
{
float X[1][4];
float temp[1][4];
X[0][0]=I[r][0];X[0][1]=I[r][1];X[0][2]=I[r][2];X[0][3]=1;
 for (i = 0; i < 1; i++)
{
	 for (j = 0; j < 4; j++)
	{
	 temp[i][j]=X[i][0]*T[0][j]+X[i][1]*T[1][j]+X[i][2]*T[2][j]+X[i][3]*T[3][j];
	}
}
O[r][0]=temp[0][0];O[r][1]=temp[0][1];O[r][2]=temp[0][2];
}
}

void translation()
{
float dx,dy,dz;
printf("enter translation along x axis : ");
scanf("%f",&dx);
printf("enter translation along y axis : ");
scanf("%f",&dy);
printf("enter translation along z axis : ");
scanf("%f",&dz);
int r;
for(r=0;r<8;r++)
{
O[r][0]=I[r][0]+dx;O[r][1]=I[r][1]+dy;O[r][2]=I[r][2]+dz;
}
}
void reflection()
{
int choice;
printf("enter\n1 to get reflection about xy plane\n2 to get reflection about xz plane\n3 to get reflection about yz plane");
printf("\nenter your choice : ");
scanf("%d",&choice);
switch(choice)
{
	case 1:	T[0][0]=1;T[0][1]=0;T[0][2]=0;T[0][3]=0;
			T[1][0]=0;T[1][1]=1;T[1][2]=0;T[1][3]=0;
			T[2][0]=0;T[2][1]=0;T[2][2]=-1;T[2][3]=0;
			T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
			break;
	case 2:	T[0][0]=1;T[0][1]=0;T[0][2]=0;T[0][3]=0;
			T[1][0]=0;T[1][1]=-1;T[1][2]=0;T[1][3]=0;
			T[2][0]=0;T[2][1]=0;T[2][2]=1;T[2][3]=0;
			T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
			break;
	case 3:	T[0][0]=-1;T[0][1]=0;T[0][2]=0;T[0][3]=0;
			T[1][0]=0;T[1][1]=1;T[1][2]=0;T[1][3]=0;
			T[2][0]=0;T[2][1]=0;T[2][2]=1;T[2][3]=0;
			T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
			break; 
}
m();
}
void rotation()
{
	int choice;
	float angle;
	printf("enter\n1 to get rotation about x axis\n2 to get rotation about y axis\n3 to get rotation about z axis\n");
	printf("enter your choice : ");
	scanf("%d",&choice);
	printf("\nenter angle you want to rotate it : ");
	scanf("%f",&angle);
	float t = angle*(PI/180);
	switch(choice)
	{
	case 1:	T[0][0]=1;T[0][1]=0;T[0][2]=0;T[0][3]=0;
			T[1][0]=0;T[1][1]=cos(t);T[1][2]=sin(t);T[1][3]=0;
			T[2][0]=0;T[2][1]=-sin(t);T[2][2]=cos(t);T[2][3]=0;
			T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
			break;
	case 2:	T[0][0]=cos(t);T[0][1]=0;T[0][2]=-sin(t);T[0][3]=0;
			T[1][0]=0;T[1][1]=1;T[1][2]=0;T[1][3]=0;
			T[2][0]=sin(t);T[2][1]=0;T[2][2]=cos(t);T[2][3]=0;
			T[3][0]=0;T[3][1]=1;T[3][2]=0;T[3][3]=1;
			break;
	case 3:	T[0][0]=cos(t);T[0][1]=sin(t);T[0][2]=0;T[0][3]=0;
			T[1][0]=-sin(t);T[1][1]=cos(t);T[1][2]=0;T[1][3]=0;
			T[2][0]=0;T[2][1]=0;T[2][2]=1;T[2][3]=0;
			T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
			break; 
	}
	m();
}
void scaling()
{
	float sx,sy,sz;
	printf("\nenter scaling along x axis : ");
	scanf("%f",&sx);
	printf("\nenter scaling along y axis : ");
	scanf("%f",&sy);
	printf("\nenter scaling along z axis : ");
	scanf("%f",&sz);
	T[0][0]=sx;T[0][1]=0;T[0][2]=0;T[0][3]=0;
	T[1][0]=0;T[1][1]=sy;T[1][2]=0;T[1][3]=0;
	T[2][0]=0;T[2][1]=0;T[2][2]=sz;T[2][3]=0;
	T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
	m();
}
void shear()
{
	int choice;
	float v;
	printf("\nenter 1 to shear along x axis : ");
	printf("\nenter 2 to shear along y axis : ");
	printf("\nenter 3 to shear along z axis : ");
	printf("\nenter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("enter shearing magnitude along x axis : ");
				scanf("%f",&v);
				T[0][0]=1;T[0][1]=v;T[0][2]=v;T[0][3]=0;
				T[1][0]=0;T[1][1]=1;T[1][2]=0;T[1][3]=0;
				T[2][0]=0;T[2][1]=0;T[2][2]=1;T[2][3]=0;
				T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
				break;
	    case 2:printf("enter shearing magnitude along y axis : ");
				scanf("%f",&v);
				T[0][0]=1;T[0][1]=0;T[0][2]=0;T[0][3]=0;
				T[1][0]=v;T[1][1]=1;T[1][2]=v;T[1][3]=0;
				T[2][0]=0;T[2][1]=0;T[2][2]=1;T[2][3]=0;
				T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
				break;
		case 3:printf("enter shearing magnitude along z axis : ");
				scanf("%f",&v);
				T[0][0]=1;T[0][1]=0;T[0][2]=0;T[0][3]=0;
				T[1][0]=0;T[1][1]=1;T[1][2]=0;T[1][3]=0;
				T[2][0]=v;T[2][1]=v;T[2][2]=1;T[2][3]=0;
				T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=1;
				break;
	}
	m();
}
void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 1.0);
 glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0); 
 }
int main(int argc, char **argv)
{
int i,choice;
while(1<2)
{
printf("enter \n");
printf("1 scaling\n2 reflection\n3 translation\n4 rotation\n5 shear\n");
printf("enter your choice : ");
scanf("%d",&choice);
switch(choice)
{

case 1:scaling();
		break;
case 2:reflection();
		break;
case 3:translation();
       break;
case 4:rotation();
		break;	
case 5:shear();
		break;	

default:printf("your input is invalid");

}

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,640);
glutCreateWindow("Transformation ");
init();
glutDisplayFunc(TransformationDisplay);
glutMainLoop();

}
return 0;
}

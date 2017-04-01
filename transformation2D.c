/*
Newton kumar
1401CS29

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
# define PI 3.14
double X[20][2];
double R[20][2];
double T[2][2];
int s;
void TransformationDisplay(void)
{
	int i;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for(i=-100;i<=100;i++)
    {
    	glVertex2s(i,0);
    	glVertex2s(0,i);
    }
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(i=0; i<s; i++)
    {
        glVertex2s(X[i][0],X[i][1]);
    }
    glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for(i=0; i<s; i++)
    {
        glVertex2s(R[i][0],R[i][1]);
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
void m(void)
{
int i;
for(i=0;i<s;i++)
{
    R[i][0]=T[0][0]*X[i][0]+T[0][1]*X[i][1];
    R[i][1]=T[1][0]*X[i][0]+T[1][1]*X[i][1];
}
}
void scaling(void)
{
int scale,i,j;
printf("enter scale : ");
scanf("%d",&scale);
printf("\n");
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        if(i==j)
        {
            T[i][j]=scale;
        }
        else
            T[i][j]=0;
    }
}
m();
}
void reflection()
{
int choice;
printf("enter\n1 reflection along x axis\n2 relection along y axis\n");
printf("enter your choice : ");
scanf("%d",&choice);
printf("\n");
switch(choice)
{
    case 1:T[0][0]=1;T[0][1]=0;T[1][0]=0;T[1][1]=-1;
            m();
            break;
    case 2:T[0][0]=-1;T[0][1]=0;T[1][0]=0;T[1][1]=1;
            m();
            break;
    default:printf("your input is invalid");
            exit(0);

}
}

void translation(void)
{
    int dx,dy,i;
    printf("enter magnitude of translation along x axis and y axis : ");
    scanf("%d%d",&dx,&dy);
    for(i=0;i<s;i++)
    {
        R[i][0]=X[i][0]+dx ;
        R[i][1]=X[i][1]+dy ;
    }

}
void rotation()
{
    double degree,angle;
    printf("Rotation is assumed to be around origin \n");
    printf("enter degree of rotation : ");
    scanf("%lf",&degree);
    angle = degree*(PI/180.0);
    T[0][0]=cos(angle);
    T[0][1]=-sin(angle);
    T[1][0]=sin(angle);
    T[1][1]=cos(angle);
    m();

}
void shear()
{
    int choice;
    double shearing_m;
    printf("enter\n1 for shearing along x axis\n2 for shearing along y axis\n");
    printf("enter your choice : ");
    scanf("%d",&choice);
    printf("\nenter shearing amount : ");
    scanf("%lf",&shearing_m);
    printf("\n");
    switch(choice)
    {
        case 1: T[0][0]=1;T[0][1]=0;T[1][0]=shearing_m;T[1][1]=1;
                m();
                break;
        case 2: T[0][0]=1;T[0][1]=shearing_m;T[1][0]=0;T[1][1]=0;
                m();
                break;
        default:printf("your input is invalid\n");
                exit(0);
    }

}

int main(int argc, char **argv)
{
int i,choice;
printf("\nenter size of polygon(no of vertices) : ");
scanf("%d",&s);
for(i=0;i<s;i++)
{
    printf("enter X%d and Y%d : ",i+1,i+1);
    scanf("%lf%lf",&X[i][0],&X[i][1]);
    printf("\n");
}
while(true)
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
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,640);
glutCreateWindow("Transformation ");
init();
glutDisplayFunc(TransformationDisplay);
glutMainLoop();
}

return 0;
}

// g++ transformation.c -lglut -lGL -lGLEW -lGLU -o t
// ./t
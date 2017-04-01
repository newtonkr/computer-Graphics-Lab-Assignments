/*
@auther Newton Kumar
1401CS29
*/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float vertices[20][2];
int np,i,j,k,m=0;
float ymin,ymax;
float intersection_points[4000][2];
void calculate_Y_min_max(void);
void find_intersection_points(void);
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(1);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for(i=0;i<m;i+=2)
	{
		glVertex2s(intersection_points[i][0],intersection_points[i][1]);
		glVertex2s(intersection_points[i+1][0],intersection_points[i+1][1]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	printf("enter no of points : ");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("enter vertex %d : ",i+1);
		scanf("%f%f",&vertices[i][0],&vertices[i][1]);
	}
	calculate_Y_min_max();
	printf("%f %f\n",ymin,ymax);
	find_intersection_points();
	void print(void);
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("polygon : filling ");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
	glutDisplayFunc(display);
	glutMainLoop(); 
	return 0;
}

void find_intersection_points(void)
{

float temp_vertices[20][2];
float intersection_container[400][2];
for(i=0;i<np;i++)
{
temp_vertices[i][0]=vertices[i][0];
temp_vertices[i][1]=vertices[i][1];
}
for(i=ymin;i<=ymax;i++)
{
	int t=0;
	for(j=0;j<np;j++)
	{
		if(temp_vertices[j][1]==i)
		{
			intersection_container[t][0]=temp_vertices[j][0];
			intersection_container[t][1]=temp_vertices[j][1];
			t++;
			intersection_container[t][0]=temp_vertices[j][0];
			intersection_container[t][1]=temp_vertices[j][1];
			t++;
		}
	}
	for(j=0;j<np;j++)
	{
		if((temp_vertices[j][1]>i && temp_vertices[(j+1)%np][1]<i)||(temp_vertices[j][1]<i && temp_vertices[(j+1)%np][1]>i))
		{
			if(((temp_vertices[j][0]-temp_vertices[(j+1)%np][0])!=0)||((temp_vertices[j][1]-temp_vertices[(j+1)%np][1])!=0))
			{
				float sl = (temp_vertices[j][1]-temp_vertices[(j+1)%np][1])/(temp_vertices[j][0]-temp_vertices[(j+1)%np][0]);
				float x = ((i - temp_vertices[j][1])/sl)+temp_vertices[j][0];
				intersection_container[t][0]=x;
				intersection_container[t][1]=i;
				t++;
			}
		}

	}


	// sorting 
	for(j=1;j<t;j++)
	{
		for(k=j;k>0;k--)
		{
			if(intersection_container[k][0]<intersection_container[k-1][0])
			{
				int temp=intersection_container[k][0];
				intersection_container[k][0]=intersection_container[k-1][0];
				intersection_container[k-1][0]=temp;
			}
			else
				break;
		}
	}
	for(j=0;j<t;j++)
	{
		intersection_points[m][0]=intersection_container[j][0];
		intersection_points[m][1]=intersection_container[j][1];
		m++;
	}
	

}
	// for(j=0;j<m;j++)
	// {
	// 	printf("%f %f\n",intersection_points[j][0],intersection_points[j][1]);
	// }
	// printf("%d\n", m);
}
void calculate_Y_min_max(void)
{
	ymin=vertices[0][1];ymax=vertices[0][1];
	for(i=1;i<np;i++)
	{
		if(vertices[i][1]<ymin)
		{
			ymin=vertices[i][1];
		}
		if(vertices[i][1]>ymax)
		{
			ymax = vertices[i][1];
		}
	}
}


//g++ pf.c -lglut -lGL -lGLEW -lGLU -o pf
//./pf

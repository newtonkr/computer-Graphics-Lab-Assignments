/*
@auther Newton Kumar
1401CS29
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

double ymax=50,ymin=-50,xmax=50,xmin=-50;
double vertex[20][2];
double final_vertex[20][2],oldVertx[20][2];
int code[20][4];
int np,i,m=0,nps;

void execute(void);
void print(double [20][2]);

void display_before_clipping(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glBegin(GL_LINE_LOOP);
        glColor3f(0.0,1.0,1.0);
    glVertex2f(xmin/100.0f,ymin/100.0f);
      glVertex2f(xmin/100.0f,ymax/100.0f);
      glVertex2f(xmax/100.0f,ymax/100.0f);
      glVertex2f(xmax/100.0f,ymin/100.0f);
    glEnd();
    // glColor3f(1.0,1.0,1.0);
    // glBegin(GL_LINE_LOOP);
    // glVertex2s(xmin, ymax);
    // glVertex2s(xmax, ymax);
    // glVertex2s(xmax, ymin);
    // glVertex2s(xmin, ymin);
    // glEnd();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
      for(i=0;i<nps;i++)
      {
      	glVertex2f(vertex[i][0]/100.0f,vertex[i][1]/100.f);
      	glVertex2f(vertex[(i+1)%nps][0]/100.f,vertex[(i+1)%nps][1]/100.f);
      }    
    glEnd();
    glFlush();
}
void display_after_clipping(void)
{
 	glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glBegin(GL_LINE_LOOP);
        glColor3f(0.0,1.0,1.0);
    glVertex2f(xmin/100.0f,ymin/100.0f);
      glVertex2f(xmin/100.0f,ymax/100.0f);
      glVertex2f(xmax/100.0f,ymax/100.0f);
      glVertex2f(xmax/100.0f,ymin/100.0f);
    glEnd();

     glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
      for(i=0;i<m;i++)
      {
      	glVertex2f(final_vertex[i][0]/100.0f,final_vertex[i][1]/100.f);
      	glVertex2f(final_vertex[(i+1)%m][0]/100.f,final_vertex[(i+1)%m][1]/100.f);
      }    
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
	printf("enter no of points : ");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		scanf("%lf%lf",&vertex[i][0],&vertex[i][1]);
	}
	execute();
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500.0, 500.0);
	glutInitWindowPosition (0, 0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
	 glutCreateWindow("Before polygon Clipping");
    glutDisplayFunc(display_before_clipping);
   glutCreateWindow("After polygon Clipping");
   glutDisplayFunc(display_after_clipping);
	glutMainLoop(); 
	return 0;
}
void print(double f[20][2])
{
	for(i=0;i<m;i++)
	{
		printf("%lf  %lf\n",f[i][0],f[i][1]);
	}

}

void execute(void)
{
	double newVertx[20][2],Vertx[20][2];
	int code[20][4];
	double sl=0;
	nps=np;
	for(i=0;i<np;i++)
	{
		Vertx[i][0]=vertex[i][0];
		Vertx[i][1]=vertex[i][1];
	}
	for(i=0;i<np;i++)
	{
		oldVertx[i][0]=Vertx[i][0];
		oldVertx[i][1]=Vertx[i][1];
	}
		for(i=0;i<np;i++)
	{
		if(Vertx[i][1]>ymax)
			code[i][0]=1;
		else
			code[i][0]=0;
		if(Vertx[i][1]<ymin)
			code[i][1]=1;
		else
			code[i][1]=0;
		if(Vertx[i][0]>xmax)
			code[i][2]=1;
		else
			code[i][2]=0;
		if(Vertx[i][0]<xmin)
			code[i][3]=1;
		else
			code[i][3]=0;
	}
	
	for(i=0;i<np;i++)
	{

		if(code[i][0]==0)
		{
			if(code[(i+1)%np][0]==0)
			{
				newVertx[m][0]=Vertx[(i+1)%np][0];
				newVertx[m++][1]=Vertx[(i+1)%np][1];
			}
			else if(code[(i+1)%np][0]==1)
			{
				if(Vertx[i][0]-Vertx[(i+1)%np][0]!=0)
				{
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double x = ((ymax-Vertx[i][1])/sl)+Vertx[i][0];
					newVertx[m][0]=x;
					newVertx[m++][1]=ymax;
				}
				else
				{
					newVertx[m][0]=Vertx[i][0];
					newVertx[m++][1]=ymax;	
				}
				
			}

		}
		else if(code[i][0]=1)
		{

			if(code[(i+1)%np][0]==0)
			{
				if(Vertx[i][0]-Vertx[(i+1)%np][0]!=0)
				{
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double x = ((ymax-Vertx[i][1])/sl)+Vertx[i][0];
					newVertx[m][0]=x;
					newVertx[m++][1]=ymax;
					newVertx[m][0]=Vertx[(i+1)%np][0];
					newVertx[m++][1]=Vertx[(i+1)%np][1];
				}
				else
				{
					newVertx[m][0]=Vertx[i][0];
					newVertx[m++][1]=ymax;
					newVertx[m][0]=Vertx[(i+1)%np][0];
					newVertx[m++][1]=Vertx[(i+1)%np][1];	
					
				}
			}


		}

	}

print(newVertx);

np = m;
m = 0;

//////// 2nd part
for(i=0;i<np;i++)
{
	Vertx[i][0]=0;
	Vertx[i][1]=0;
}
for(i=0;i<np;i++)
	{
		Vertx[i][0]=newVertx[i][0];
		Vertx[i][1]=newVertx[i][1];
	}
	m=0;
		for(i=0;i<np;i++)
	{
		if(Vertx[i][1]>ymax)
			code[i][0]=1;
		else
			code[i][0]=0;
		if(Vertx[i][1]<ymin)
			code[i][1]=1;
		else
			code[i][1]=0;
		if(Vertx[i][0]>xmax)
			code[i][2]=1;
		else
			code[i][2]=0;
		if(Vertx[i][0]<xmin)
			code[i][3]=1;
		else
			code[i][3]=0;
	}
	
for(i=0;i<np;i++)
	{
	
		if(code[i][1]==0)
		{
			if(code[(i+1)%np][1]==0)
			{
				newVertx[m][0]=Vertx[(i+1)%np][0];
				newVertx[m++][1]=Vertx[(i+1)%np][1];
			}
			else if(code[(i+1)%np][1]==1)
			{
				if(Vertx[i][0]-Vertx[(i+1)%np][0]!=0)
				{
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double x = ((ymin-Vertx[i][1])/sl)+Vertx[i][0];
					newVertx[m][0]=x;
					newVertx[m++][1]=ymin;
				}
				else
				{
					newVertx[m][0]=Vertx[i][0];
					newVertx[m++][1]=ymin;	
				}
				
			}

		}
		else if(code[i][1]=1)
		{

			if(code[(i+1)%np][1]==0)
			{
				if(Vertx[i][0]-Vertx[(i+1)%np][0]!=0)
				{
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double x = ((ymin-Vertx[i][1])/sl)+Vertx[i][0];
					newVertx[m][0]=x;
					newVertx[m++][1]=ymin;
					newVertx[m][0]=Vertx[(i+1)%np][0];
					newVertx[m++][1]=Vertx[(i+1)%np][1];
				}
				else
				{
					newVertx[m][0]=Vertx[i][0];
					newVertx[m++][1]=ymin;
					newVertx[m][0]=Vertx[(i+1)%np][0];
					newVertx[m++][1]=Vertx[(i+1)%np][1];	
				}
			}


		}

	}

printf("\n\n");
print(newVertx);

np = m;
m = 0;

/// 3rd part

for(i=0;i<np;i++)
{
	Vertx[i][0]=0;
	Vertx[i][1]=0;
}
for(i=0;i<np;i++)
	{
		Vertx[i][0]=newVertx[i][0];
		Vertx[i][1]=newVertx[i][1];
	}

	m=0;
		for(i=0;i<np;i++)
	{
		if(Vertx[i][1]>ymax)
			code[i][0]=1;
		else
			code[i][0]=0;
		if(Vertx[i][1]<ymin)
			code[i][1]=1;
		else
			code[i][1]=0;
		if(Vertx[i][0]>xmax)
			code[i][2]=1;
		else
			code[i][2]=0;
		if(Vertx[i][0]<xmin)
			code[i][3]=1;
		else
			code[i][3]=0;
	}

for(i=0;i<np;i++)
	{
	
		if(code[i][2]==0)
		{
			if(code[(i+1)%np][2]==0)
			{
				newVertx[m][0]=Vertx[(i+1)%np][0];
				newVertx[m++][1]=Vertx[(i+1)%np][1];
				
			}
			else if(code[(i+1)%np][2]==1)
			{
				
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double y = (sl*(xmax-Vertx[i][0]))+Vertx[i][1];
					newVertx[m][0]=xmax;
					newVertx[m++][1]=y;
					
			
				
			}

		}
		else if(code[i][2]==1)
		{

			if(code[(i+1)%np][2]==0)
			{
				
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double y = sl*(xmax-Vertx[i][0])+Vertx[i][1];
					newVertx[m][0]=xmax;
					newVertx[m++][1]=y;
					newVertx[m][0]=Vertx[(i+1)%np][0];
					newVertx[m++][1]=Vertx[(i+1)%np][1];
					
			}


		}

	}
printf("\n\n");
print(newVertx);

np = m;
m = 0;
/////4rth part
for(i=0;i<np;i++)
{
	Vertx[i][0]=0;
	Vertx[i][1]=0;
}


for(i=0;i<np;i++)
	{
		Vertx[i][0]=newVertx[i][0];
		Vertx[i][1]=newVertx[i][1];
	}
	m=0;
		for(i=0;i<np;i++)
	{
		if(Vertx[i][1]>ymax)
			code[i][0]=1;
		else
			code[i][0]=0;
		if(Vertx[i][1]<ymin)
			code[i][1]=1;
		else
			code[i][1]=0;
		if(Vertx[i][0]>xmax)
			code[i][2]=1;
		else
			code[i][2]=0;
		if(Vertx[i][0]<xmin)
			code[i][3]=1;
		else
			code[i][3]=0;
	}
for(i=0;i<np;i++)
	{
	
		if(code[i][3]==0)
		{
			if(code[(i+1)%np][3]==0)
			{
				newVertx[m][0]=Vertx[(i+1)%np][0];
				newVertx[m++][1]=Vertx[(i+1)%np][1];
			}
			else if(code[(i+1)%np][3]==1)
			{
				
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double y = sl*(xmin-Vertx[i][0])+Vertx[i][1];
					newVertx[m][0]=xmin;
					newVertx[m++][1]=y;
	
			
				
			}

		}
		else if(code[i][3]==1)
		{

			if(code[(i+1)%np][3]==0)
			{
				
					sl = (Vertx[i][1]-Vertx[(i+1)%np][1])/(Vertx[i][0]-Vertx[(i+1)%np][0]);
					double y = sl*(xmin-Vertx[i][0])+Vertx[i][1];
					newVertx[m][0]=xmin;
					newVertx[m++][1]=y;
					newVertx[m][0]=Vertx[(i+1)%np][0];
					newVertx[m++][1]=Vertx[(i+1)%np][1];
			}


		}

	}
	printf("\n\n");
	print(newVertx);


for(i=0;i<m;i++)
{
	final_vertex[i][0]=newVertx[i][0];
	final_vertex[i][1]=newVertx[i][1];
}
	




}



//g++ clippingMyOwn.c -lglut -lGL -lGLEW -lGLU -o cf
//./cf

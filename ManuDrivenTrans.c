#include<stdio.h> 
#include<math.h>
#include<GL/glut.h> 
void init(void) { glClearColor(1.0,1.0,1.0,0.0); 
glMatrixMode(GL_PROJECTION); 
gluOrtho2D(0.0,1.0,0.0,1.0); 
} 
void polygon(void) 
{ float x1,x2,x3,y1,y2,y3,angle; 
scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3); 

glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(0.0,0.0,0.0); 
printf("1 for rotation\n2 for scaling\n3 for translation");
int de;
scanf("%d",&de);
glBegin(GL_POLYGON); 
glVertex3f(x1,y1,0.0); 
glVertex3f(x2,y2,0.0); 
glVertex3f(x3,y3,0.0); 
glEnd(); 
if(de==1)
{	scanf("%f",&angle);
	angle=angle*3.14159265/180;
glBegin(GL_POLYGON); 
glVertex3f(x1*cos(angle)-y1*sin(angle),x1*sin(angle)+y1*cos(angle),0.0); 
glVertex3f(x2*cos(angle)-y2*sin(angle),x2*sin(angle)+y2*cos(angle),0.0);
glVertex3f(x3*cos(angle)-y3*sin(angle),x3*sin(angle)+y3*cos(angle),0.0); 
glEnd();
}
else	if(de==3)
	{	 
	glBegin(GL_POLYGON); 
	glVertex3f(x1+0.5,y1+0.5,0.0); 
	glVertex3f(x2+0.5,y2+0.5,0.0); 
	glVertex3f(x3+0.5,y3+0.5,0.0); 
	glEnd();
	}
	else
	{ 
	glBegin(GL_POLYGON); 
	glVertex3f(2*x1,2*y1,0.0); 
	glVertex3f(2*x2,2*y2,0.0);
	glVertex3f(2*x3,2*y3,0.0); 
	glEnd();
	} 
/*glBegin(GL_POLYGON); 
glVertex3f(x1,y1,0.0);
glVertex3f(x2,y2,0.0); 
glVertex3f(x3,y3,0.0); 
glEnd(); */
glFlush(); 
} 
void main(int argc,char **argv) 
{ glutInit(&argc,argv); 
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
glutInitWindowPosition(50,100); 
glutInitWindowSize(1000,1300); 
glutCreateWindow("AN EXAMPLE OF OPEN GL"); 

init(); 
glutDisplayFunc(polygon); 
glutMainLoop(); 
}

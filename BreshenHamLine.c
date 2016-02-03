#include<stdio.h> 
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>

double X1,Y1,X2,Y2;


void init(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,400,0.0,500.0);
}

float roundValue(float v)
{
  return floor(v + 0.5);
}
void BreshenHamLine(void){
	double dx=X2-X1;
	double  dy=X2-Y1;
	float x,y,p;
int i;
	x=X1,y=Y1;
	p=2*dy-dx;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2s(x,y);
	while(x<=X2){
		if(p<0){
			x=x+1;		
			y=y;
			p=p+2*dy;
			glVertex2s(roundValue(x),roundValue(y));
			printf("%lf %lf\n",x,y);
		}
		else{
			x=x+1;
			y=y+1;
			p=p+2*(dy-dx);
			glVertex2s(roundValue(x),roundValue(y));
			printf("%lf %lf\n",x,y);		
		}
	}
	

/* for(i=-100 ; i<=100 ; i++)
 {
 glVertex2s(i,0);
 glVertex2s(0,i);
 }
 for(i=-2; i<=2 ; i++)
 {
 glVertex2s(95+i,4+i);
 glVertex2s(95-i,4+i);
 } 
 for(i=0; i<=2 ; i++)
 {
 glVertex2s(4+i,95+i);
 glVertex2s(4-i,95+i);
 glVertex2s(4,95-i);
 }*/
	
	glEnd();
	glFlush();
}




void main(int argc,char** argv){
	printf("Enter the first two end points \n");
	scanf("%lf %lf",&X1,&Y1);
	printf("Enter the second two end points \n");
	scanf("%lf %lf",&X2,&Y2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,300);
	glutCreateWindow("AnnExample of OpenGl");
	init();
	glutDisplayFunc(BreshenHamLine);
 	glutMainLoop();
}

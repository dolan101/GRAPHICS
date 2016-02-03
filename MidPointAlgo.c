#include<stdio.h> 
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>

double Xc,Yc,r;


void init(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,400,0.0,500.0);
}

float roundValue(float v)
{
  return floor(v + 0.5);
}


 void pixel(int xc,int yc,int x,int y)
{
	        Putpixel(xc+x,yc+y,7);
            Putpixel(xc+y,yc+x,7);
            Putpixel(xc-y,yc+x,7);
            Putpixel(xc-x,yc+y,7);
            Putpixel(xc-x,yc-y,7);
            Putpixel(xc-y,yc-x,7);
            Putpixel(xc+y,yc-x,7);
            Putpixel(xc+x,yc-y,7);
}






void MPCircle(void){
	float x,y,p;
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	x=0;
	y=r;	
	p=1-r;	
	pixel(Xc,Yc,x,y);
	while(x<y){
		if(p<0){		
		x=x+1;
		p=p+2*x+1;	
		}
		else{
			x=x+1;
			y=y-1;
			p=p+2*x-2+y+1;
		}
		pixel(Xc,Yc,x,y);
	}
	
	
	glEnd();
	glFlush();
}




void main(int argc,char** argv){
	printf("Enter the centere of the circle \n");
	scanf("%lf %lf",&Xc,&Yc);
	printf("Enter the radius of the circle \n");
	scanf("%lf",&r);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,300);
	glutCreateWindow("Mid Point Circle Drawing algo");
	init();
	glutDisplayFunc(MPCircle);
 	glutMainLoop();
}

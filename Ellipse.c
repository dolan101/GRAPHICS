#include<stdio.h> 
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>

  void Ellipse() {
glClear(GL_COLOR_BUFFER_BIT);
        long midx, midy, xradius, yradius;
        long xrad2, yrad2, twoxrad2, twoyrad2;
        long x, y, dp, dpx, dpy;

        /* x axis radius and y axis radius of ellipse */
        xradius = 100, yradius = 50;

        /* finding the center postion to draw ellipse */
        midx = 200;
        midy = 200;

        xrad2 = xradius * xradius;
        yrad2 = yradius * yradius;

        twoxrad2 = 2 * xrad2;
        twoyrad2 = 2 * yrad2;
        x = dpx = 0;
        y = yradius;
        dpy = twoxrad2 * y;
	

	glBegin(GL_POINTS);
        glVertex2i(midx + x, midy + y);
        glVertex2i(midx - x, midy + y);
        glVertex2i(midx + x, midy - y);
        glVertex2i(midx - x, midy - y);
	glEnd();
        

	dp = (long) (0.5 + yrad2 - (xrad2 * yradius) + (0.25 * xrad2));

        while (dpx < dpy) {
                x = x + 1;
                dpx = dpx + twoyrad2;
                if (dp < 0) {
                        dp = dp + yrad2 + dpx;
                } else {
                        y = y - 1;
                        dpy = dpy - twoxrad2;
                        dp = dp + yrad2 + dpx - dpy;
                }

                /* plotting points in y-axis(top/bottom) */
               glBegin(GL_POINTS);
        	glVertex2i(midx + x, midy + y);
        	glVertex2i(midx - x, midy + y);
        	glVertex2i(midx + x, midy - y);
        	glVertex2i(midx - x, midy - y);
		glEnd();
        }

        dp = (long)(0.5 + yrad2 * (x + 0.5) * (x + 0.5) +
                        xrad2 * (y - 1) * (y - 1) - xrad2 * yrad2);

        while (y > 0) {
                y = y - 1;
                dpy = dpy - twoxrad2;

                if (dp > 0) {
                        dp = dp + xrad2 - dpy;
                } else {
                        x = x + 1;
                        dpx = dpx + twoyrad2;
                        dp = dp + xrad2 - dpy + dpx;
                }

                /* plotting points at x-axis(left/right) */
                glBegin(GL_POINTS);
        	glVertex2i(midx + x, midy + y);
       		glVertex2i(midx - x, midy + y);
        	glVertex2i(midx + x, midy - y);
        	glVertex2i(midx - x, midy - y);
		glEnd();
        }
	glFlush();
  }


void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
}



void main(int argc, char **argv)
{
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("bresenham_circle");
  /* Initialize drawing colors */
  Init();
  /* Call the displaying function */
  glutDisplayFunc(Ellipse);
  /* Keep displaying untill the program is closed */
  glutMainLoop();
}

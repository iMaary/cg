#include <GL/glut.h>

void reshape(int, int);
void timer(int);
void display();

void init();

void main(int argc, char** argv) {
	// base initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	// setting up screen
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Window 1");

	// callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	// simple functions
	init();

	// loop to keep the program running
	glutMainLoop();
}

float x_position = -10.0;
int state = 1;

void display() {
	// before load each frame we need clear the previous
	glClear(GL_COLOR_BUFFER_BIT);
	// reset all transformations of our current metrics
	glLoadIdentity();

	glPointSize(10.0);
	//////////////////////
	// start-draw area //
	////////////////////
	glBegin(GL_POLYGON);

	glVertex2f(x_position, 1.0);
	glVertex2f(x_position, -1.0);
	glVertex2f(x_position+2, -1.0);
	glVertex2f(x_position+2, 1.0);

	glEnd();
	////////////////////
	// end-draw area //
	//////////////////

	// friend buffer <-> backup buffer
	glutSwapBuffers();

	// display the frame buffer on the screen
	//glFlush();
}

void reshape(int w, int h) {
	// viewport: where the things will be drawn
	glViewport(0, 0, w, h); // the whole of your screen
	// projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	// modelview
	glMatrixMode(GL_MODELVIEW);

}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	switch (state){
	case 1:
		if (x_position < 8)
			x_position += 0.15;
		else
			state = -1;
		break;
	case -1:
		if (x_position > -10)
			x_position -= 0.15;
		else
			state = 1;
		break;
	}
}

void init() {
	// the black is default but here we can declare the color we want
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

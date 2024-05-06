#include <GL/glut.h>

GLfloat mover_y = 1.0;
GLfloat quad_angle = 0;

void defScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// rotate object
	glRotated(quad_angle, 1, 1, 1);

	// for interaction
	glTranslatef(0, mover_y, 0);
	glColor3f(1, 1, 0);

	//glutWireTeapot(0.5);	
	glutWireCube(2);

	glFlush();
	glutSwapBuffers();

	// changing the rotation angle
	quad_angle += 0.1;

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP) mover_y += 0.1;
	else if (key == GLUT_KEY_DOWN) mover_y -= 0.1;
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		glOrtho(-2, 2, -2*h/w, 2*h/w, -10, 10);
	}
	else {
		glOrtho(-2*w/h, 2*w/h, -2, 2, -10, 10);
	}
	glMatrixMode(GL_MODELVIEW);
}

// ################################
// ######### Main Program #########
// ################################
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	// Basic Setup
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Primitivas 3D");
	// Callback Functions
	glutDisplayFunc(defScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys); // handle interaction

	// Keeps the Screen Running
	glutMainLoop();
}

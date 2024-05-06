#include <GL/glut.h>

GLfloat mover_y = 0.0;
GLfloat bule_angle = 0;

void defScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// rotate object
	glRotated(bule_angle, 0, 1, 0);

	// for interaction
	glTranslatef(0, mover_y, 0);
	glColor3f(1, 1, 0);

	glutWireTeapot(0.5);

	glFlush();
	glutSwapBuffers();

	// changing the rotation angle
	bule_angle += 0.2;

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP) mover_y += 0.1;
	else if (key == GLUT_KEY_DOWN) mover_y -= 0.1;
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
	glutSpecialFunc(specialKeys);

	// Keeps the Screen Running
	glutMainLoop();
}

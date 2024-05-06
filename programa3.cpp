#include <GL/glut.h>


void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(100.0, 150.0, 150.0, 100.0);

	glFlush();
}

void SetupRC() {
	glClearColor(0, 0, 1, 1);
}

void ChangeSize(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) glOrtho(0, 250, 0, 250, 1, -1);
	else glOrtho(0, 250, 0, 250, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Formas Geom�tricas - Reshape");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
}

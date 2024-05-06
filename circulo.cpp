#include <GL/glut.h>
#include <math.h>

#define CIRCLE_STEPS 50

void desenhaCirculo() {
	GLint i;

	glLineWidth(3);
	glColor3f(0, 0, 1);

	glBegin(GL_LINE_LOOP);
		glVertex2f(1, 0);
		for (i = 0; i < CIRCLE_STEPS; i++) {
			GLfloat t = i * 3.1415 * 2 / CIRCLE_STEPS;
			glVertex2f(cos(t), sin(t));
		}
	glEnd();
}

void janela() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	gluOrtho2D(-4, -4, -4, -4);

	desenhaCirculo();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Formas Geom�tricas - C�rculo");
	glutDisplayFunc(janela);

	glutMainLoop();
}

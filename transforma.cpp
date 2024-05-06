#include <GL/glut.h>


//definir posi��o inicial
GLfloat x = 200;
GLfloat y = 150;
GLsizei rectDimensao = 50;

GLfloat janelaW, janelaH;

GLfloat xStep = 1;
GLfloat yStep = 1;


// Chamada para desenhar a cena
void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(x, y, x+rectDimensao, y+rectDimensao);
	glutSwapBuffers();
}

void changeSize(GLsizei w, GLsizei h) {
	if(h == 0) h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		janelaW = 250;
		janelaH = 250 * h / w;
	}
	else {
		janelaW = 250 * w / h;
		janelaH = 250;
	}

	glOrtho(0, janelaW, 0, janelaH, 1, -1);
	// glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void TimerFunction(int value) {
	// verifuca  os limites da janela 
	if (x > janelaW-rectDimensao || x < 0) {
		xStep = -xStep;
	}
	if (y > janelaH-rectDimensao || y < 0) {
		yStep = -yStep;
	}
	if (x > janelaW - rectDimensao) {
		x = janelaW - rectDimensao - 1;
	}
	if (y > janelaH - rectDimensao) {
		y = janelaH - rectDimensao - 1;
	}

	// mover quadrado
	x += xStep;
	y += yStep;
	glutPostRedisplay();
	glutTimerFunc(30, TimerFunction, 1);
}

void SetupRC() {
	glClearColor(0, 0, 1, 1);
}

// programa principal
void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Anima Quadrado");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(30, TimerFunction, 1);

	SetupRC();

	glutMainLoop();
}

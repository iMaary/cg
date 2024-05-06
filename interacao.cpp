#include <GL/glut.h>

// Definiçãod de Variáveis Globais
float xf = 20, yf = 20, win = 250;
int view_w, view_h;

// Chamada para desenhar a cena
void RenderScene() {
	// limpar a janela
	glClear(GL_COLOR_BUFFER_BIT);

	// glColor3f(1.0, 0.0, 0.0);

	// Desenhar um rectangulo com a cor atual
	glRectf(0, 0, xf, yf);
	glFlush();

	//glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h) {
	// Especificar o tamnaho do viewport
	glViewport(0, 0, w, h);
	view_w = w;
	view_h = h;

	// Inicializar o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Estabelecer o volume de visualização
	// (esquerda, direita, inferior, superior, near, far)
	glOrtho(-win, win, -win, win, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Callback para gerir as interações com o teclado
void TratarTeclado(unsigned char key, int x, int y) {
	switch (key) {
		case 82:	// tecla R
		case 114:	// tecla r
			glColor3f(1, 0, 0);	// mudar a cor para vermelho
			break;
		case 71:	// tecla G
		case 103:	// tecla g
			glColor3f(0, 1, 0);	// mudar a cor para verde
			break;
	}
	glutPostRedisplay();
}

void TratarMouse(int botao, int estado, int x, int y) {
	if (botao == GLUT_LEFT_BUTTON) {
		if (estado == GLUT_DOWN) {
			// Trocar o rectangulo, da sua posição atual até a posição que clicamos
			xf = ((2 * win * x) / view_w) - win;
			yf = (((2 * win) * (y - view_h)) / -view_h) - win;
		}
	}
	glutPostRedisplay();
}

void TratarEspeciais(int tecla, int x, int y) {
	if (tecla == GLUT_KEY_UP) {
		win -= 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(-win, win, -win, win, 1, -1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	if (tecla == GLUT_KEY_DOWN) {
		win += 20;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(-win, win, -win, win, 1, -1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	glutPostRedisplay();
}

void SetupRC() {
	glClearColor(0, 0, 1, 1);
}

// ----------------------
// | PROGRAMA PRINCIPAL |
// ----------------------
void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350, 350);
	glutCreateWindow("Interação com o Utilizador");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(TratarTeclado);
	glutMouseFunc(TratarMouse);
	glutSpecialFunc(TratarEspeciais);
	
	SetupRC();
	glutMainLoop();
}

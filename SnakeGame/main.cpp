#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 20

extern short sDirection;
bool gameOver = false;
int score = 0;

void init();
void timerCallback(int);
void displayCallback();
void keyboardCallback(int, int, int);
void reshapeCallback(GLsizei w, GLsizei h);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	// Basic Setup
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Snake Game");
	// Callback Functions
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutTimerFunc(0, timerCallback, 0);
	glutSpecialFunc(keyboardCallback);
	// Initializer Screen
	init();
	// Keeps the Screen Running
	glutMainLoop();
}

void displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();

	if (gameOver) {
		char _score[10];
		_itoa_s(score, _score, 10);
		char _text[50] = "YOUR SCORE: ";
		strcat_s(_text, _score);
		MessageBoxA(NULL, _text, "GAME OVER", 0);
		exit(0);
	}
}

void reshapeCallback(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timerCallback(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timerCallback, 0);
}

void keyboardCallback(int key, int, int) {
	switch (key) {
		case GLUT_KEY_UP:
			if (sDirection != DOWN) sDirection = UP;
			break;
		case GLUT_KEY_DOWN:
			if (sDirection != UP) sDirection = DOWN;
			break;
		case GLUT_KEY_RIGHT:
			if (sDirection != LEFT) sDirection = RIGHT;
			break;
		case GLUT_KEY_LEFT:
			if (sDirection != RIGHT) sDirection = LEFT;
			break;
	}
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMNS, ROWS);
}

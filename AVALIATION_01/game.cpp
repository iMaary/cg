#include <GL/glut.h>
#include <ctime>
#include "game.h"

int gridX, gridY;
int posX = 20, posY = 20;
int foodX, foodY;
int max_pos = 20;
bool food = true;
extern bool gameOver, isReady;

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;
}

void drawGrid() {
	for (int x = 0; x < gridX; x++) {
		for (int y = 0; y < gridY; y++) {
			unit(x, y);
		}
	}
}

void unit(int x, int y) {
	if (x > 20) {
		glLineWidth(3.0);
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glLineWidth(1.0);
		glColor3f(1.0, 1.0, 1.0);
	}

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x+1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void drawFood() {
	if (food)
		random(foodX, foodY);
	food = false;

	glColor3f(1.0, 1.0, 1.0);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void drawPlayer() {
	if (isReady)
		posX++;

	glColor3f(1.0, 1.0, 0.0);
	glRectd(posX, posY, posX+1, posY+1);

	if (posX > 38)
		gameOver = true;

	if (posX == foodX && posY == foodY)
		food = true;
}

void random(int& x, int& y) {
	int _maxX = gridX - 2;
	int _maxY = gridY - 2;
	int _min = 1;

	srand(time(NULL));
	x = 20 + rand() % (_maxX - 20);
	y = _min + rand() % (_maxY - _min);
}

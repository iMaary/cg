#include <GL/glut.h>
#include <cmath>

float pacmanX = 200;
float pacmanY = 200;
int n = 0, closing, state=0;
int directions[4][2] = { {30, 330}, {120, 420}, {210, 510}, {300, 600} };

void specialCallback(int, int, int);
void reshapeCallback(int, int);
void drawPacman();
void timerCallback(int);
void displayCallback();
void init();

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Pacman");

    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutSpecialFunc(specialCallback);
    glutTimerFunc(0, timerCallback, 0);

    init();
    glutMainLoop();
}

void drawPacman() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    float radius = 0.5f;
    for (int i = directions[n][0] - closing; i <= directions[n][1] + closing; ++i) {
        float angle = i * 3.14159 / 180;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
}

void specialCallback(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            pacmanX += 10;
            n = 0;
            break;
        case GLUT_KEY_UP:
            pacmanY += 10;
            n = 1;
            break;
        case GLUT_KEY_LEFT:
            pacmanX -= 10;
            n = 2;
            break;
        case GLUT_KEY_DOWN:
            pacmanY -= 10;
            n = 3;
            break;
    }
    glutPostRedisplay();
}

void timerCallback(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timerCallback, 0);

    switch (state) {
    case 0:
        if (closing < 30)
            closing++;
        else
            state = 1;
        break;
    case 1:
        if (closing > 0)
            closing--;
        else
            state = 0;
        break;
    }
}

void displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(pacmanX, pacmanY, 0);
    glScalef(30, 30, 1);
    drawPacman();
    glutSwapBuffers();
}

void reshapeCallback(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

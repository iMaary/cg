#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

GLuint idTexture;

void windowCallback() {
	glClear(GL_COLOR_BUFFER_BIT);

	// ligar, desligar luzes ambientais individuais (por default estão desligadas)
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, idTexture);
	glOrtho(-2, 2, -2, 2, -1, 1);
	
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex2f(-1, -1);

		glTexCoord2f(1, 0);
		glVertex2f(1, -1);

		glTexCoord2f(1, 1);
		glVertex2f(1, 1);

		glTexCoord2f(0, 1);
		glVertex2f(-1, 1);
	glEnd();
	glFlush();
}

void loadTexture(const char *image) {
	unsigned char *infoTexture;
	int w, h, numChannels;

	// inverte a imagem para que ela nao apareça espelhada
	stbi_set_flip_vertically_on_load(true);

	infoTexture = stbi_load(image, &w, &h, &numChannels, 0);

	glGenTextures(2, &idTexture);

	glBindTexture(GL_TEXTURE_2D, idTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// make sure GL_UNPACK_ALIGNMENT is set to 1 (default 4) 
	// with glPixelStorei() before your glTexImage2D() call
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glBindTexture(GL_TEXTURE_2D, idTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, infoTexture);

	stbi_image_free(infoTexture);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Carregamento de Imagem/Textura");
	glutInitWindowSize(500, 500);
	// Callback Functions
	glutDisplayFunc(windowCallback);
	loadTexture("test.jpg");

	glutMainLoop();
}

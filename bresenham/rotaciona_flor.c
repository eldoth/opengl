/*
 * flor.c
 *
 *  Created on: 21/05/2013
 *      Author: leowada
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float anguloRotacao = 0;

void desenhaAbobrinha() {
	int angulo;
	float x, y, raio;
	raio = 0.2;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	x = -(raio * 1.4);
	y = raio * -1.4;
	glRotatef(anguloRotacao, 0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(x, y);
	for (angulo = 0; angulo < 360; angulo++) {
		glVertex2f(x + sinf(angulo) * raio + 0.1, y + cos(angulo) * raio + 0.1);
	}
	glEnd();
	glFlush();
	//Desenha Petala Superior Direita
	raio = 0.2;
	x = raio * 0.4;
	y = raio * 0.4;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(x, y);
	for (angulo = 0; angulo < 360; angulo++) {
		glVertex2f(x + sinf(angulo) * raio + 0.1, y + cos(angulo) * raio + 0.1);
	}
	glEnd();
	glFlush();
	//Desenha Petala Superior Esquerda
	raio = 0.2;
	x = -(raio * 1.4);
	y = raio * 0.4;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(x, y);
	for (angulo = 0; angulo < 360; angulo++) {
		glVertex2f(x + sinf(angulo) * raio + 0.1, y + cos(angulo) * raio + 0.1);
	}
	glEnd();
	glFlush();
	//Desenha Petala Inferior Direita
	raio = 0.2;
	x = raio * 0.4;
	y = raio * -1.4;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(x, y);
	for (angulo = 0; angulo < 360; angulo++) {
		glVertex2f(x + sinf(angulo) * raio + 0.1, y + cos(angulo) * raio + 0.1);
	}
	glEnd();
	glFlush();
	//Desenha Parte Central
	x = 0;
	y = 0;
	raio = 0.15;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.9, 0.0);
	glVertex2f(x, y);
	for (angulo = 0; angulo < 360; angulo += 10) {
		glVertex2f(x + sinf(angulo) * raio, y + cos(angulo) * raio);
	}
	glEnd();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFlush();
}

void desenhaFlor() {
	float x, raio;
	raio = 0.1;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Desenha caule
	x = 0;
	glLineWidth(8.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(x, -raio + 0.04);
	glVertex2f(x, -0.9);
	glEnd();
	desenhaAbobrinha();
	glFlush();
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		anguloRotacao += 10;
		break;
	case 'd':
		anguloRotacao -= 10;
		break;
	}
	glutPostRedisplay();
}

void specialKeys() {

}

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(600, 600);
	glutInit(&argc, argv);
	glutCreateWindow("Lista OpenGL 23_05 Flor");
	glutDisplayFunc(desenhaFlor);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}

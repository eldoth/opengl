/*
 * carro.c
 *
 *  Created on: 21/05/2013
 *      Author: leowada
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

void init() {
	gluOrtho2D(-300,300,-300,300);
}

void desenhaRodas() {
	float x, y, raio, angulo, x2, y2;
	//Desenha Roda da frente
	x = -0.45;
	y = -0.28;
	raio = 0.12;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
	for (angulo = 1.0f; angulo < 361.0f; angulo += 0.2) {
		x2 = x + sin(angulo) * raio;
		y2 = y + cos(angulo) * raio;
		glVertex2f(x2, y2);
	}
	glEnd();
	glFlush();
	//Desenha Roda de trás
	x = 0.1;
	y = -0.28;
	raio = 0.12;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
	for (angulo = 1.0f; angulo < 361.0f; angulo += 0.2) {
		x2 = x + sin(angulo) * raio;
		y2 = y + cos(angulo) * raio;
		glVertex2f(x2, y2);
	}
	glEnd();
	glFlush();
}

void desenhaCarro() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
//	glTranslatef(1,0,1);
	//Desenha Parte Central
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.0);
	glVertex2f(0.2, 0.25);
	glVertex2f(0.25, 0.0);
	glVertex2f(0.25, -0.25);
	glVertex2f(-0.65, -0.25);
	glVertex2f(-0.65, -0.1);
	glVertex2f(-0.45, 0.0);
	glVertex2f(-0.35, 0.25);
	glEnd();
//	//Desenha Janela da Esquerda
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.33, 0.22);
	glVertex2f(-0.42, 0.0);
	glVertex2f(-0.12, 0.0);
	glVertex2f(-0.12, 0.22);
	glEnd();
//	//Desenha Janela da Direita
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.08, 0.22);
	glVertex2f(-0.08, 0.0);
	glVertex2f(0.21, 0.0);
	glVertex2f(0.17, 0.22);
	glEnd();
//	//Desenha Escapamento
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.25, -0.23);
	glVertex2f(0.25, -0.18);
	glVertex2f(0.28, -0.18);
	glVertex2f(0.28, -0.23);
	glEnd();
//	// Desenha Lanterna
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-0.65, -0.12);
	glVertex2f(-0.55, -0.08);
	glVertex2f(-0.55, -0.17);
	glVertex2f(-0.65, -0.17);
	glEnd();
	desenhaRodas();
	glFlush();

}

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(150, 100);
	glutInitWindowSize(900, 600);
	glutInit(&argc, argv);
	glutCreateWindow("Lista OpenGL 23_05 Carro");
	init();
	glutDisplayFunc(desenhaCarro);
	glutMainLoop();
	return 0;
}

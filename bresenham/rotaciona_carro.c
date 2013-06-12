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

float anguloRotacao;
float translacaoEmX;

void init() {
	gluOrtho2D(-300, 300, -300, 300);
}

void desenhaRodas() {
	float xRodaFrente, yRodaFrente, xRodaTras, yRodaTras, raio, angulo, x2, y2;
	xRodaFrente = -0.45 * 300;
	yRodaFrente = -0.28 * 300;
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glTranslatef(xRodaFrente, yRodaFrente, 1);
		glRotatef(anguloRotacao, 0, 0, 1);
		glTranslatef(-xRodaFrente, -yRodaFrente, -1);
		//Desenha Roda da frente
		raio = 0.12 * 300;
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2f(xRodaFrente, yRodaFrente);
			for (angulo = 1.0f; angulo < 361.0f; angulo += 0.2) {
				x2 = xRodaFrente + sin(angulo) * raio;
				y2 = yRodaFrente + cos(angulo) * raio;
				glVertex2f(x2, y2);
			}
		glEnd();
		// Centro da roda da frente
		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(-130.0, -60.0);
			glVertex2f(-140.0, -60.0);
			glVertex2f(-140.0, -106.0);
			glVertex2f(-130.0, -106.0);
		glEnd();
	glPopMatrix();
	//Desenha Roda de trás
	xRodaTras = 0.1 * 300;
	yRodaTras = -0.28 * 300;
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glTranslatef(xRodaTras, yRodaTras, 1);
		glRotatef(anguloRotacao, 0, 0, 1);
		glTranslatef(-xRodaTras, -yRodaTras, -1);
		raio = 0.12 * 300;
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2f(xRodaTras, yRodaTras);
			for (angulo = 1.0f; angulo < 361.0f; angulo += 0.2) {
				x2 = xRodaTras + sin(angulo) * raio;
				y2 = yRodaTras + cos(angulo) * raio;
				glVertex2f(x2, y2);
			}
		glEnd();
			// Centro da roda de tras
		glBegin(GL_POLYGON);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(35.0, -60.0);
			glVertex2f(25.0, -60.0);
			glVertex2f(25.0, -106.0);
			glVertex2f(35.0, -106.0);
		glEnd();
	glPopMatrix();
}

void desenhaCarro() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	init();
	glTranslatef(translacaoEmX, 0, 1);
//	Desenha Parte Central
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.0);
	glVertex2f(0.2 * 300, 0.25 * 300);
	glVertex2f(0.25 * 300, 0.0 * 300);
	glVertex2f(0.25 * 300, -0.25 * 300);
	glVertex2f(-0.65 * 300, -0.25 * 300);
	glVertex2f(-0.65 * 300, -0.1 * 300);
	glVertex2f(-0.45 * 300, 0.0 * 300);
	glVertex2f(-0.35 * 300, 0.25 * 300);
	glEnd();
	//Desenha Janela da Esquerda
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.33 * 300, 0.22 * 300);
	glVertex2f(-0.42 * 300, 0.0 * 300);
	glVertex2f(-0.12 * 300, 0.0 * 300);
	glVertex2f(-0.12 * 300, 0.22 * 300);
	glEnd();
	//Desenha Janela da Direita
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.08 * 300, 0.22 * 300);
	glVertex2f(-0.08 * 300, 0.0 * 300);
	glVertex2f(0.21 * 300, 0.0 * 300);
	glVertex2f(0.17 * 300, 0.22 * 300);
	glEnd();
	//Desenha Escapamento
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.25 * 300, -0.23 * 300);
	glVertex2f(0.25 * 300, -0.18 * 300);
	glVertex2f(0.28 * 300, -0.18 * 300);
	glVertex2f(0.28 * 300, -0.23 * 300);
	glEnd();
	// Desenha Lanterna
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-0.65 * 300, -0.12 * 300);
	glVertex2f(-0.55 * 300, -0.08 * 300);
	glVertex2f(-0.55 * 300, -0.17 * 300);
	glVertex2f(-0.65 * 300, -0.17 * 300);
	glEnd();
	desenhaRodas();
	glFlush();

}

void SpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		translacaoEmX -= 10;
		anguloRotacao += 10;
		break;
	case GLUT_KEY_RIGHT:
		translacaoEmX += 10;
		anguloRotacao -= 10;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(150, 100);
	glutInitWindowSize(900, 600);
	glutInit(&argc, argv);
	glutCreateWindow("Lista OpenGL 13_06 Rotacionar Carro");
	init();
	translacaoEmX = 0.0;
	anguloRotacao = 0.0;
	glutDisplayFunc(desenhaCarro);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
	return 0;
}

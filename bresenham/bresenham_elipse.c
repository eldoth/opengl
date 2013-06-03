/*
 * bresenham_elipse.c
 *
 *  Created on: 02/06/2013
 *      Author: leonardowada
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

typedef struct ponto {
	int x;
	int y;
} ponto;

float pointSize;
ponto foco1, foco2;
int raiox, raioy;
int primeiroPonto;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}

void setPixel(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

/**
 * Método que verifica se o ponto está dentro, fora ou faz parte da elipse.
 */
int estaNaElipse(ponto ponto) {
	int result = (pow(raioy, 2) * pow(ponto.x, 2))
			+ (pow(raiox, 2) * pow(ponto.y, 2))
			- (pow(raiox, 2) * pow(raioy, 2));
	if (result == 0) {
		// Ponto faz parte da elipse
		return 0;
	} else if (result > 0) {
		// Ponto está fora da elipse
		return 1;
	}
	// Ponto está dentro da elipse
	return -1;
}

double getInclinacaoDaReta(ponto ponto) {
	double m = - ((2 * pow(raioy, 2) * ponto.x) / (2 * pow(raiox, 2) * ponto.y));
	return m;
}

int estaNoLimiteRegiaoUmDois(ponto ponto) {
	if (2 * pow(raioy, 2) * ponto.x == 2 * pow(raiox, 2) * ponto.y) {
		return 1;
	}
	return 0;
}

void bresenham_elipse() {
	ponto ponto;
	ponto.x = 0;
	ponto.y = raioy;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	while (!estaNoLimiteRegiaoUmDois(ponto)) {
		setPixel(ponto.x, ponto.y);
		ponto.x++;
	}
	while(ponto.y >= 0) {
		setPixel(ponto.x,ponto.y);
		ponto.y++;
	}
	glFlush();
}

/*void Keyboard(unsigned char key, int x, int y) {
 switch (key) {
 case '0':
 glColor3f(1.0, 1.0, 1.0);
 break;
 case '1':
 glColor3f(1.0, 1.0, 1.0);
 break;
 case '2':
 glColor3f(1.0, 0.0, 0.0);
 break;
 case '3':
 glColor3f(0.0, 1.0, 0.0);
 break;
 case '4':
 glColor3f(1.0, 1.0, 0.0);
 break;
 case '5':
 glColor3f(1.0, 0.0, 1.0);
 break;
 case '6':
 glColor3f(0.0, 1.0, 1.0);
 break;
 case '7':
 glColor3f(1.0, 1.0, 0.5);
 break;
 case '8':
 int primeiroPonto;
 glColor3f(1.0, 0.5, 1.0);
 break;
 case '9':

 glColor3f(0.5, 1.0, 1.0);
 break;
 }
 glFlush();
 glutPostRedisplay();
 }*/

/*void MouseInt(int botao, int estado, int x, int y) {
 if (primeiroPonto) {
 switch (botao) {
 case GLUT_LEFT_BUTTON:
 if (estado == GLUT_DOWN) {
 primeiroPonto--;
 p1.x = x - 300;
 p1.y = (y - 300) * (-1);
 break;
 }
 }
 } else {
 switch (botao) {
 case GLUT_LEFT_BUTTON:
 if (estado == GLUT_DOWN) {
 primeiroPonto++;
 p2.x = x - 300;
 p2.y = (y - 300) * (-1);
 glutDisplayFunc(bresenham);
 glutPostRedisplay();
 break;
 }
 }
 }
 }*/

int main(int argc, char *argv[]) {
	primeiroPonto = 1;
	pointSize = 5.0;
	foco1 =
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(600, 600);
	glutInit(&argc, argv);
	glutCreateWindow("Lista OpenGL 26_05 Exercicio 1");
	init();
	glColor3f(0.0, 0.0, 1.0);
	glutDisplayFunc(bresenham_elipse());
	glutMainLoop();
	return 0;
}


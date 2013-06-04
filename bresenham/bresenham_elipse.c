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
int raiox, raioy;

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

int pXInicial() {
	double result = pow(raioy, 2) - pow(raiox, 2) * raioy + (double)pow(raiox, 2) / 4;
	return result;
}

int pYInicial(ponto ponto) {
	double result = (pow(raioy, 2) * pow(ponto.x + ((double)1 / 2), 2))
			+ (pow(raiox, 2) * pow(ponto.y - 1, 2))
			- (pow(raioy, 2) * pow(raiox, 2));
	return result;
}

/**
 * o ponto que deve ser passado é o p(k+1).
 */
int calculaPx(ponto ponto, int pk) {
	int pkMaisUm;
	if (pk < 0) {
		pkMaisUm = pk + pow(raioy, 2) * (2 * ponto.x + 1);
	} else {
		pkMaisUm = pk + pow(raioy, 2) * (2 * ponto.x + 1)
				+ pow(raiox, 2) * (-2 * ponto.y);
	}
	return pkMaisUm;
}

int calculaPy(int yk, int xkMaisUm, int pk) {
	int pkMaisUm;
	if (pk > 0) {
		pkMaisUm = pk + pow(raiox, 2) * ((-2 * yk) + 1);
	} else {
		pkMaisUm = pk + pow(raioy, 2) * (2 * xkMaisUm)
				+ pow(raiox, 2) * ((-2 * yk) + 1);
	}
	return pkMaisUm;
}

double getInclinacaoDaReta(ponto ponto) {
	if (ponto.y == 0) {
		return 0.0;
	}
	double m = -((double) (2 * pow(raioy, 2) * ponto.x) / (2 * pow(raiox, 2) * ponto.y));
	return m;
}

void bresenham_elipse() {
	ponto ponto;
	ponto.x = 0;
	ponto.y = raioy;
	int pk;
	int yk;
	double m;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	pk = pXInicial();
	setPixel(ponto.x, ponto.y);
	m = getInclinacaoDaReta(ponto);
	while (m >= -1) {
		if (pk < 0) {
			ponto.x++;
		} else {
			ponto.x++;
			ponto.y--;
		}
		setPixel(ponto.x, ponto.y);
		m = getInclinacaoDaReta(ponto);
		pk = calculaPx(ponto, pk);
	}
	pk = pYInicial(ponto);
	while (m <= -1) {
		if (pk > 0) {
			ponto.y--;
		} else {
			ponto.x++;
			ponto.y--;
		}
		setPixel(ponto.x, ponto.y);
		m = getInclinacaoDaReta(ponto);
		yk = ponto.y;
		pk = calculaPy(yk--, ponto.x, pk);
	}
	glFlush();
}

int main(int argc, char *argv[]) {
	pointSize = 5.0;
	//Parametros iniciais.
	raioy = 250;
	raiox = 150;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(600, 600);
	glutInit(&argc, argv);
	glutCreateWindow("Lista OpenGL 06/06");
	init();
	glColor3f(0.0, 0.0, 1.0);
	glutDisplayFunc(bresenham_elipse);
	glutMainLoop();
	return 0;
}


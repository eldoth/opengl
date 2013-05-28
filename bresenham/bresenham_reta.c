/*
 * bresenham_reta.c
 *
 *  Created on: 26/05/2013
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
ponto p1, p2;
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

void bresenham() {
	ponto ponto1, ponto2;
	ponto1 = p1;
	ponto2 = p2;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	int dx, dy, incSup, incInf, p, x, y, incLeft, incRight;
	dx = ponto2.x - ponto1.x;
	dy = ponto2.y - ponto1.y;
	if (abs(dx) == abs(dy)) {
		x = ponto1.x;
		y = ponto1.y;
		if (dx > 0 && dy > 0) {
			while (x < ponto2.x) {
				setPixel(x, y);
				x++;
				y++;
			}
		} else if (dx > 0 && dx < 0) {
			while (x < ponto2.x) {
				setPixel(x, y);
				x++;
				y--;
			}
		} else if (dx < 0 && dy > 0) {
			while (y < ponto2.y) {
				setPixel(x, y);
				x--;
				y++;
			}
		} else if (dx < 0 && dy < 0) {
			while (y > ponto2.y) {
				setPixel(x, y);
				x--;
				y--;
			}
		}
	} else if (dy == 0) {
		x = ponto1.x;
		y = ponto1.y;
		while (x < ponto2.x) {
			setPixel(x, y);
			x++;
		}
	} else if (dx == 0) {
		x = ponto1.x;
		y = ponto1.y;
		while (y < ponto2.y) {
			setPixel(x, y);
			y++;
		}
	} else if ((abs(dy) < abs(dx)) && dx * dy > 0) {
		if (dx < 0 && dy < 0) {
			ponto1 = p2;
			ponto2 = p1;
			dx = dx * (-1);
			dy = dy * (-1);
		}
		p = 2 * dy - dx;
		incInf = 2 * dy;
		incSup = 2 * (dy - dx);
		x = ponto1.x;
		y = ponto1.y;
		setPixel(x, y);
		while (x < ponto2.x) {
			if (p <= 0) {
				p = p + incInf;
			} else {
				p = p + incSup;
				y++;
			}
			x++;
			setPixel(x, y);
		}
	} else if ((abs(dy) > abs(dx)) && dx * dy > 0) {
		if (dx < 0 && dy < 0) {
			ponto1 = p2;
			ponto2 = p1;
			dx = dx * (-1);
			dy = dy * (-1);
		}
		p = 2 * dy - dx;
		incLeft = 2 * dx;
		incRight = 2 * (dx - dy);
		x = ponto1.x;
		y = ponto1.y;
		setPixel(x, y);
		while (y < ponto2.y) {
			if (p <= 0) {
				p = p + incLeft;
			} else {
				p = p + incRight;
				x++;
			}
			y++;
			setPixel(x, y);

		}
	} else if ((abs(dy) < abs(dx)) && dx * dy < 0) {
		if (dy > 0 && dx < 0) {
			ponto1 = p2;
			ponto2 = p1;
			dx *= -1;
			dy *= -1;
		}
		p = 2 * dy + dx;
		incInf = 2 * dy;
		incSup = 2 * (dy + dx);
		x = ponto1.x;
		y = ponto1.y;
		setPixel(x, y);
		if (dx > 0) {
			while (x < ponto2.x) {
				if (p >= 0) {
					p = p + incInf;
				} else {
					p = p + incSup;
					y--;
				}
				x++;
				setPixel(x, y);
			}
		}
	} else if ((abs(dy) > abs(dx)) && dx * dy < 0) {
		if (dy < 0 && dx > 0) {
			ponto1 = p2;
			ponto2 = p1;
			dx *= -1;
			dy *= -1;
		}
		p = 2 * dy + dx;
		incLeft = 2 * dx;
		incRight = 2 * (dx + dy);
		x = ponto1.x;
		y = ponto1.y;
		setPixel(x, y);
		while (y < ponto2.y) {
			if (p >= 0) {
				p = p + incLeft;
			} else {
				p = p + incRight;
				x--;
			}
			y++;
			setPixel(x, y);

		}
	}
	glFlush();
}

void Keyboard(unsigned char key, int x, int y) {
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
		glColor3f(1.0, 0.5, 1.0);
		break;
	case '9':

		glColor3f(0.5, 1.0, 1.0);
		break;
	}
	glFlush();
	glutPostRedisplay();
}

void MouseInt(int botao, int estado, int x, int y) {
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
}

int main(int argc, char *argv[]) {
	primeiroPonto = 1;
	pointSize = 5.0;
	p1.x = p2.x = -300;
	p1.y = p2.y = 0;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(600, 600);
	glutInit(&argc, argv);
	glutCreateWindow("Lista OpenGL 26_05 Exercicio 1");
	init();
	glColor3f(0.0, 0.0, 1.0);
	glutDisplayFunc(bresenham);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(MouseInt);
	glutMainLoop();
	return 0;
}


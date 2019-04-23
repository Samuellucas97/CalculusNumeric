#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>

#include "interpolacaoPolinomialNewton.h"

double tAtual = 0.0; //um ponto é renderizado na reta
int delta = 1; //= 1 ou -1... variação positiva ou negativa de tAtual, quando animacao = 1
int animacao = 1;
double top = 6, bottom = -4, left = -4, right = 6;
int showGuideLines = true;

using namespace std;

vector<double> vx; /// Vetor que contem as abscissas dos pontos
vector<double> vy; /// Vetor que contem as ordenadas dos pontos


enum {
	ADICIONARREMOVER, 
	ALTERAR
};

int estado = ADICIONARREMOVER;
int pontoAtual = 0;

void inicializacao() {
	glClearColor(0.5, 0.5, 0.5, 0.0);
}

//preencha a seguinte função
//seja n a quantidade de pontos (tamanho do vetor)
//a função deve retornar o valor v(t), tal que:
//	quando t = 0, retorna v[0]
//	quando t = 1, retorna v[n-1]
double interpolacao(vector<double> v, double t) {
	int n = v.size();
	double ret = 0;

	if( t == 0)
		return v[0];

	if( t == 1 )	
		return v[n - 1];	

	return interpolacaoPolinomial_Lagrange( v, t );
}


void funcaoDisplay() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	for(int i = 0; i < (int)vx.size(); i++) {
		if(i == pontoAtual && estado == ALTERAR) {
			glColor3f(0, 0, 1);
			glPointSize(6.0);
		} else {
			glColor3f(1, 1, 1);
			glPointSize(3.0);
		}
		glBegin(GL_POINTS);
		glVertex2f(vx[i], vy[i]);
		glEnd();
	}

	//renderização de tAtual
	double px = interpolacao(vx, tAtual);
	double py = interpolacao(vy, tAtual);

	if(vx.size() > 2) {
		glColor3f(1, 1, 1);
		glPointSize(6.0);
		glBegin(GL_POINTS);
		glVertex2f(px, py);
		glEnd();
	}

	if(vx.size() > 2 && showGuideLines) {
		for(int i = 0; i < (int)vx.size()-1; i++) {
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex2f(vx[i], vy[i]);
			glVertex2f(vx[i+1], vy[i+1]);
			glEnd();
		}
	}

	int n = 100*vx.size();
	for(int i = 0; i < n-1; i++) {
		double t = ((double)i)/(n-1);
		double tnext = ((double)(i+1))/(n-1);
		glColor3f(1, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(interpolacao(vx, t), interpolacao(vy, t));
		glVertex2f(interpolacao(vx, tnext), interpolacao(vy, tnext));
		glEnd();
	}


	//escreve um texto na tela para acompanhar a coordenada para t = tAtual
	if(vx.size() > 2) {
		glRasterPos2f(px+0.1, py+0.1);
		char texto[60];
		sprintf(texto, "t = %.2f, (x, y) = (%.2f, %.2f)", tAtual, px, py);
		for(int i = 0; i < (int)strlen(texto); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[i]);
	}

	glutSwapBuffers();
	glFlush();
}

void funcaoKeyboard(unsigned char key, int , int ) {

	if(key == 'q') {
		exit(-1);
	}
	if(!animacao) {
		if(key == 'a') {
			tAtual -= 0.01;
		}
		if(key == 'd') {
			tAtual += 0.01;
		}
	}
	if(key == 's')
		animacao = 1 - animacao;
	if(key == 'g')
		showGuideLines = !showGuideLines;
	glutPostRedisplay();
}

void temporizador() {
	glutPostRedisplay();
	if(animacao) {
		tAtual += 0.005*delta;
		if(tAtual >= 1) {
			tAtual = 1;
			delta = -1;
		}
		if(tAtual < 0) {
			tAtual = 0;
			delta = 1;
		}
	}
}

void funcaoMouseMotion(int x, int y) {

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble worldX, worldY, worldZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (double)x;
	winY = (double)viewport[3] - (double)y;
	winZ = 0;

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

	if(estado == ALTERAR) {
		vx[pontoAtual] = worldX;
		vy[pontoAtual] = worldY;
	}
}

void funcaoMouse(int button, int state, int x, int y) {

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble worldX, worldY, worldZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (double)x;
	winY = (double)viewport[3] - (double)y;
	winZ = 0;

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

	if(state == GLUT_UP) {
		if(estado == ADICIONARREMOVER) {
			if(button == GLUT_LEFT_BUTTON) {
				vx.push_back(worldX);
				vy.push_back(worldY);
			}
			if(button == GLUT_RIGHT_BUTTON && vx.size() > 0) {
				vx.pop_back();
				vy.pop_back();
			}
		} else {
			if(button == GLUT_LEFT_BUTTON) {
				vx[pontoAtual] = worldX;
				vy[pontoAtual] = worldY;
				estado = ADICIONARREMOVER;
			}
		}
	} if(state == GLUT_DOWN) {
		double menorDistancia = -1;
		int pontoMaisProximo = 0;
		for(int i = 0; i < (int)vx.size(); i++) {
			double distancia1 = fabs(vx[i] - worldX) + fabs(vy[i] - worldY);
			if(i == 0 || distancia1 < menorDistancia) {
				menorDistancia = distancia1;
				pontoMaisProximo = i;
			}
		}
		if(menorDistancia < 0.2 && (int)vx.size() > 0 && estado == ADICIONARREMOVER) {
			estado = ALTERAR;
			pontoAtual = pontoMaisProximo;
		}
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Splines");
	glutKeyboardFunc(funcaoKeyboard);
	glutMouseFunc(funcaoMouse);
	glutMotionFunc(funcaoMouseMotion);
	glutDisplayFunc(funcaoDisplay);
	glutIdleFunc(temporizador);
	inicializacao();

	glutMainLoop();

	return 0;
}


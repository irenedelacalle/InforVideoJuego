#include "EsquinaIzquierda.h"
#include "glut.h"
#include "Generacion.h"


EsquinaIzquierda::EsquinaIzquierda(float x,float y)
{
	l=5;
	oi.x=x;
	oi.y=y;
	tipo=ESQUINA_IZQ;
}


EsquinaIzquierda::~EsquinaIzquierda(void)
{
}

void EsquinaIzquierda::Dibuja(void)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255,0,0);
		glVertex3f(oi.x,oi.y,0.0f);
		glColor3ub(0,225,0);
		glVertex3f(oi.x+l,oi.y,0.0f);
		glColor3ub(0,0,225);
		glVertex3f(oi.x+l,oi.y+l,0.0f);
		glColor3ub(0,0,0);
		glVertex3f(oi.x,oi.y+l,0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

EsquinaIzquierda& EsquinaIzquierda::operator=(const EsquinaIzquierda *ei){
	oi.x=ei->oi.x;
	oi.y=ei->oi.y;
	l=ei->l;
	return (*this);
	}

Suelo& EsquinaIzquierda::generaSiguiente(int tipoSiguiente){
	return Generacion::generaHijoEsquIzqda(this);
}


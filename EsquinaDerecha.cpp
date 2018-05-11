#include "EsquinaDerecha.h"
#include "glut.h"
#include "Generacion.h"

EsquinaDerecha::EsquinaDerecha(float x=0, float y=0)
{
	l=5;
	oi.x=x;
	oi.y=y;
	tipo=ESQUINA_DRCH;
}


EsquinaDerecha::~EsquinaDerecha(void)
{

}

void EsquinaDerecha::Dibuja(void)
{
	glPushMatrix();
	glColor3ub(0,225,0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glVertex3f(oi.x,oi.y,0.0f);
		glVertex3f(oi.x+l,oi.y,0.0f);
		glVertex3f(oi.x+l,oi.y+l,0.0f);
		glVertex3f(oi.x,oi.y+l,0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}
EsquinaDerecha& EsquinaDerecha::operator=(const EsquinaDerecha *ed){
	oi.x=ed->oi.x;
	oi.y=ed->oi.y;
	l=ed->l;
	return (*this);
	}

Suelo& EsquinaDerecha::generaSiguiente(int tipoSiguiente){

	return Generacion::generaHijoEsquDcha(this);

}




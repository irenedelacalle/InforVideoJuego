#include "Pasillo.h"
#include "glut.h"
#include "Generacion.h"
Pasillo::Pasillo(float x=0, float y=0, float largo=20, float ancho=5)
{
	a=ancho;
	oi.x=x;
	oi.y=y;
	l=largo;
	tipo=PASILLO;
}


Pasillo::~Pasillo(void)
{

}

void Pasillo::Dibuja(){

	//glColor3ub(255,255,255);
	//glPushMatrix();
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(oi.x,oi.y,0.0f);
		glColor3ub(255,255,0);
		glVertex3f(oi.x+a,oi.y,0.0f);
		glColor3ub(255,255,255);
		glVertex3f(oi.x+a,oi.y+l,0.0f);
		glColor3ub(0,255,255);
		glVertex3f(oi.x,oi.y+l,0.0f);
	glEnd();
		glEnable(GL_LIGHTING);
	//glPopMatrix();
}



Suelo& Pasillo::generaSiguiente(int tipoSiguiente){
	return Generacion::generaHijoPasillo(this,tipoSiguiente);

}

Pasillo& Pasillo::operator=(const Pasillo *p){
	oi.x=p->oi.x;
	oi.y=p->oi.y;
	l=p->l;
	a=p->a;
	return (*this);
	}


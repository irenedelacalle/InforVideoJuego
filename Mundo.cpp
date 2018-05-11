#include "Mundo.h"
#include "glut.h"
#include "EsquinaDerecha.h"
#include "EsquinaIzquierda.h"
#include "Pasillo.h"
#include <math.h>
#include <conio.h>
#include"Pasillo.h"
#include"Suelo.h"
#include "Universidad.h"
#include "Irene.h"


void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  
			0.0, 0, 0.0,      
			0.0, 0.0, 1.0); 

	
	for(int i=0;i<MAX;i++){
		actual.next[i]->Dibuja();
	}
	irenes.Dibujaa();

}

void Mundo::Mueve()
{
	actual.Mueve();
	irenes.Mueve(0.025f);
}

void Mundo::Inicializa()
{
	/*x_ojo=50;
	y_ojo=8;
	z_ojo=50;*/
	x_ojo=0;
	y_ojo=-40;
	z_ojo=130;
	

}

void Mundo::Tecla(unsigned char key)
{


}

  void Mundo::teclaEspecial(unsigned char key)
 {
   switch(key)
  {
   case GLUT_KEY_LEFT:
    irenes.SetVel (-5.0f, 0.0f);
    break;
    case GLUT_KEY_RIGHT:
    irenes.SetVel (5.0f, 0.0f);
    break;
 }
}

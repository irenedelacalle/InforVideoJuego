#include "Irene.h"
#include "glut.h"

 Irene::Irene( float x, float y, float vx, float vy)
 {
  altura=5;

  posicion.x=x;
  posicion.y=y;
  velocidad.x=vx;
  velocidad.y=vy;
  aceleracion.y=-9.8;

  rojo=verde=255;
  azul=100; //color distinto
}

 Irene::~Irene(void)
 {
 }

  void Irene::Dibujaa(void){

   glTranslated(0,2.5,0);
   glColor3ub(225,225,255);
   glutSolidSphere(1,20,20);

  }

 void Irene::Mueve(float t){

   posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
   velocidad=velocidad+aceleracion*t; 


}

 void Irene::SetColor( unsigned char r,unsigned char v, unsigned char a)
 {
   rojo=r;
   verde=v;
   azul=a;
 }

 void Irene::SetPos(float ix,float iy)
 {
   posicion.x=ix;
   posicion.y=iy;
 }

void Irene::SetVel(float vx,float vy)
{
 velocidad.x=vx;
 velocidad.y=vy;
}





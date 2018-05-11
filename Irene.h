/*#pragma once
class Irene
{
public:
	float altura;
	float alpha;
	Irene(void);
	~Irene(void);
	void Dibujaa();
};*/
#pragma once
#include "Vector2D.h"
class Irene
{
private:
 unsigned char rojo;
 unsigned char azul;
 unsigned char verde;
 Vector2D posicion;
 Vector2D velocidad;
 Vector2D aceleracion; 

public:
 float altura;
 float alpha;
 Irene(float x=0.0f, float y=0.0f, float vx=0.0f, float vy=0.0f);
 ~Irene(void);
 void Dibujaa();

 void SetColor( unsigned char r,unsigned char v, unsigned char a);
 void SetPos(float ix,float iy);
 void SetVel(float vx=5,float vy=10);

 void Mueve(float);
};


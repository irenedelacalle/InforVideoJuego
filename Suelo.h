#pragma once
#include "Vector2D.h"
#define SUELO 0
#define PASILLO 1
#define ESQUINA_IZQ 2
#define ESQUINA_DRCH 3

class Suelo
{
public:
	int tipo;
	float l,a;//largo y ancho del suelo. En el caso de esquinas se utiliza únicamente el ancho.
	Vector2D oi;//Coordenadas del vértice inferior izuierdo del suelo.
	virtual Suelo& generaSiguiente(int tipoSiguiente)=0;//función virtual pura para generar el siguiente elemento 
	//del puntero a vector de suelos de universidad. 
	//elemento del vector suelo
	virtual void Dibuja()=0;//funcion virtual pura para dibujar el suelo.
	Suelo(void);
	~Suelo(void);
};


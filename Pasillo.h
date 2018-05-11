#pragma once
#include "suelo.h"
#include "Vector2D.h"
class Pasillo :public Suelo
{
public:
	void Dibuja();
	Pasillo &operator=(const Pasillo *p);
	Pasillo(float x, float y, float largo, float ancho);
	Suelo& generaSiguiente(int tipoSiguiente);
	~Pasillo(void);
};


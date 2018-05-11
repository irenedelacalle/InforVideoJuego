#pragma once
#include "suelo.h"
class EsquinaIzquierda :public Suelo
{
public:
	void Dibuja(void);
	EsquinaIzquierda(float x, float y);
	EsquinaIzquierda& operator=(const EsquinaIzquierda *ei);
	Suelo& generaSiguiente(int tipoSiguiente);
	~EsquinaIzquierda(void);
};


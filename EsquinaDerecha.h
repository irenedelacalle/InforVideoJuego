#pragma once
#include "Suelo.h"
#include"Generacion.h"
class EsquinaDerecha :public Suelo
{
public:
	void Dibuja();
	void Inicializa();
	Suelo& generaSiguiente(int tipoSiguiente);
	EsquinaDerecha& operator=(const EsquinaDerecha *ed);
	EsquinaDerecha(float x, float y);
	~EsquinaDerecha(void);
};


#pragma once
#include "Suelo.h"
class Generacion
{
public:
	
	friend class Pasillo;
	friend class EsquinaDerecha;
	friend class EsquinaIzquierda;
	static Suelo& generaHijoEsquDcha(Suelo *s);
	static Suelo& generaHijoEsquIzqda(Suelo *s);
	static Suelo& generaHijoPasillo(Suelo *s, int tipoSiguiente);
	Pasillo *v;
	EsquinaDerecha *ed;
	EsquinaIzquierda *ei; 
	Generacion(void);
	~Generacion(void);
};



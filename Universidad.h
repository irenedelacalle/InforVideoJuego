#pragma once
#include "Suelo.h"
#include "EsquinaDerecha.h"
#include "EsquinaIzquierda.h"
#include "Pasillo.h"

#define MAX 3

class Universidad
{
public:
	int n;
	static int orientacion;//Variable común a todos los objetos de la clase. Se trata de un contador
	//que nos permite saber en todo momento la orientación del suelo. Se incrementará en uno cada vez que 
	//aparezca una esquina derecha y decrementará una unidad cada vez que aparezca una esquina izquierda.


	
	Vector2D Limite; //Guardo en este vector el límite con el que comparar para eliminar el suelo.
	Suelo *next[MAX];
	void Mueve ();
	//void propagacion(Universidad *u);
	bool operator+=(EsquinaDerecha *ed);
	bool operator+=(EsquinaIzquierda *ei);
	bool operator+=(Pasillo *ep);
	bool operator=(Pasillo *p);
	void propaga();
	void Dibuja(Suelo *s);
	void Inicializa(void);
	Universidad(void);
	~Universidad(void);
};


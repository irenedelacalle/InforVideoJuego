#pragma once
#include "Universidad.h"
#include "Irene.h"
class Mundo
{
public: 
	Universidad actual;
	Irene irenes;
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	//void RotarOjo();
	void Mueve();
	void Dibuja();
	float x_ojo;
	float y_ojo;
	float z_ojo;
};

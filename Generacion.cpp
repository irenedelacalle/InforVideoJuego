#include "Generacion.h"
#include "EsquinaIzquierda.h"
#include "EsquinaDerecha.h"
#include "Pasillo.h"
#include "Universidad.h"



Generacion::Generacion(void)
{
	Pasillo *m=new Pasillo (0,0,0,0);
	v=m;
	EsquinaDerecha *n=new EsquinaDerecha (0,0);
	ed=n;
	EsquinaIzquierda *n2=new EsquinaIzquierda (0,0);
	ei=n2;
}

Generacion::~Generacion(void)
{
}

Suelo& Generacion::generaHijoEsquDcha(Suelo *s)  
{

	Universidad::orientacion++;

	//Para que el contador vaya de 0 a 3 y cuando llegue a 3 pase a cero y viceversa utiliamos el resto de 
	//dividir entre cuatro

		if((Universidad::orientacion)%4==0)//A la esquina derecha le preced�a un pasillo con orientaci�n Oeste.
		{
			Suelo *p=new Pasillo(s->oi.x,s->oi.y+s->l,2*s->l,s->l);
			return *p;
		}
		else if((Universidad::orientacion)%4==1)//A la esquina derecha le preced�a un pasillo con orientacion Norte.
		{
			Suelo *p=new Pasillo(s->oi.x+s->l,s->oi.y,s->l,2*s->l);
			return *p;
		}
		else if((Universidad::orientacion)%4==2)//A la esquina derecha le preced�a un pasillo con orientaci�n Este.
		{
			Suelo *p=new Pasillo(s->oi.x,s->oi.y-2*s->l,2*s->l,s->l);
			return *p;
		}
		else if((Universidad::orientacion%4)==3)//A la esquina derecha le preced�a un pasillo con orientaci�n Sur.
		{
			Suelo *p=new Pasillo(s->oi.x-2*s->l,s->oi.y,s->l,2*s->l);
			return *p;
		}
}

Suelo& Generacion::generaHijoEsquIzqda(Suelo *s)
{
		Universidad::orientacion--;

		if((Universidad::orientacion%4)==0)//A la esquina izquierda le precede un pasillo con orientaci�n Este.
		{
			Suelo *p=new Pasillo(s->oi.x,s->oi.y+s->l,2*s->l,s->l);
			return *p;
		}
		else if((Universidad::orientacion%4)==1)//A la esuqina izquierda le precede un pasillo con orientaci�n Sur.
		{
			Suelo *p=new Pasillo(s->oi.x+s->l,s->oi.y,s->l,2*s->l);
			return *p;
		}
		else if((Universidad::orientacion%4)==2)//A la esuqina izquierda le precede un pasillo con orientaci�n Oeste.
		{
			Suelo *p=new Pasillo(s->oi.x,s->oi.y-2*s->l,2*s->l,s->l);
			return *p;
		}
		else if((Universidad::orientacion%4)==3)//A la esquina izquierda le precede un pasillo con orientaci�n Norte.
		{
			Suelo *p=new Pasillo(s->oi.x-2*s->l,s->oi.y,s->l,2*s->l);
			return *p;
		}
}

Suelo& Generacion::generaHijoPasillo(Suelo *s,int tipoSiguiente)
{
	if(tipoSiguiente==1)
	{
		if((Universidad::orientacion)%4==0){ //A este pasillo le precede un pasillo con orientaci�n Norte.
		Pasillo *p=new Pasillo (s->oi.x,s->oi.y+s->l,s->l,s->a);
		return *p;
		}
		else if((Universidad::orientacion)%4==1){ //A este pasillo le precede un pasillo con orientaci�n Este.
		Pasillo *p=new Pasillo (s->oi.x+s->l,s->oi.y,s->l,s->a); 
		return *p;
		}
		else if((Universidad::orientacion)%4==2){ //A este pasillo le precede un pasillo con orientaci�n Sur.
		Pasillo *p=new Pasillo (s->oi.x,s->oi.y-s->l,s->l,s->a); 
		return *p;
		}
		else if((Universidad::orientacion)%4==3){ //A este pasillo le precede un pasillo con orientaci�n Oeste.
		Pasillo *p=new Pasillo (s->oi.x-2*s->l,s->oi.y,s->l,s->a); 
		return *p;
		}
	}
	else if(tipoSiguiente==2)
	{
		if((Universidad::orientacion)%4==0){ //A esta esquina le precede un pasillo con orientaci�n Norte.
		EsquinaIzquierda *ei=new EsquinaIzquierda(s->oi.x,s->oi.y+s->l);
		return *ei;
		}
		if((Universidad::orientacion)%4==1){ //A esta esquina le precede un pasillo con orientaci�n Este.
		EsquinaIzquierda *ei=new EsquinaIzquierda(s->oi.x+s->l,s->oi.y);
		return *ei;
		}
		if((Universidad::orientacion)%4==2){ //A esta esquina le precede un pasillo con orientaci�n Sur.
		EsquinaIzquierda *ei=new EsquinaIzquierda(s->oi.x,s->oi.y-s->a-s->l);
		return *ei;
		}
		if((Universidad::orientacion)%4==3){ //A esta esquina le precede un pasillo con orientaci�n Oeste.
		EsquinaIzquierda *ei=new EsquinaIzquierda(s->oi.x-s->l-s->a,s->oi.y);
		return *ei;
		}
		
	}

	else if(tipoSiguiente==3)
	{
		if((Universidad::orientacion)%4==0){ //A esta esquina le precede un pasillo con orientaci�n Norte.
		EsquinaDerecha *ei=new EsquinaDerecha(s->oi.x,s->oi.y+s->l);
		return *ei;
		}
		if((Universidad::orientacion)%4==1){ //A esta esquina le precede un pasillo con orientaci�n Este.
		EsquinaDerecha *ei=new EsquinaDerecha(s->oi.x+s->l,s->oi.y);
		return *ei;
		}
		if((Universidad::orientacion)%4==2){ //A esta esquina le precede un pasillo con orientaci�n Sur.
		EsquinaDerecha *ei=new EsquinaDerecha(s->oi.x,s->oi.y-s->a-s->l);
		return *ei;
		}
		if((Universidad::orientacion)%4==3){ //A esta esquina le precede un pasillo con orientaci�n Oeste.
		EsquinaDerecha *ei=new EsquinaDerecha(s->oi.x-s->l-s->a,s->oi.y);
		return *ei;
		}
	}
	
}
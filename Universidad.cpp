#include "Universidad.h"
#include <stdlib.h>

	int Universidad::orientacion=120;//Variable común a todos los objetos de la clase. Se trata de un contador
	//que nos permite saber en todo momento la orientación del suelo. Se incrementará en uno cada vez que 
	//aparezca una esquina derecha y decrementará una unidad cada vez que aparezca una esquina izquierda.

	//Inicializamos a nivel global la variable static y solo una vez. Lo hacemos en el 
	//fichero fuente .cpp ya que el compilador lee este fichero una única vez. El valor dado es lo suficientemente 
	//grande como para que siempre sea positivo. Tenemos que encontrar solución al problema de que en algún momento 
	//llegue a ser negativo el número.
	
Universidad::Universidad()
{
	
	n=0;
	for (int i=0;i<MAX;i++)
	{
		Pasillo *m =new Pasillo(-2.5f,i*20.0f,20,5);
		n++;
		next[i]=m;
	}
}


Universidad::~Universidad(void)
{
}

	

void Universidad::Dibuja(Suelo *s)
{
	s->Dibuja();
}

void Universidad::Mueve(void)
{
	if(next[0]->tipo==PASILLO)
	{	
		//NORTE
		if(orientacion%4==0)//Pasillo con orientacion Norte.
		{
			if ((next[0]->oi.y+next[0]->l)<(Limite.y))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.y-=0.5;	
		}

		//ESTE
		else if((orientacion)%4==1)//Pasillo con orientacion Este.
		{
			if ((next[0]->oi.x+next[0]->l)<(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.x-=0.5;	
		}

		//SUR
		else if((orientacion)%4==2)//Pasillo con orientacion Sur.
		{
			if ((next[0]->oi.y-next[0]->l)>(Limite.y))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.y-=0.5;	
		}

		//OESTE
		else if((orientacion)%4==3)//Pasillo con orientacion Oeste.
		{
			if ((next[0]->oi.x-next[0]->l)>(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.x+=0.5;	
		}
			
		 /*/if((next[0]->a<next[0]->l) && next[0]->oi.x<next[0]->oi.x+next[0]->l)//definicion pasillo vertical hacia arriba
			//{
			if ((next[0]->oi.y+next[0]->l)<0)
			propaga();
			for(int i=0;i<MAX;i++)
			next[i]->oi.y-=0.5; 
			//}*/
	}


	else if(next[0]->tipo==ESQUINA_DRCH)
	{
		//NORTE
		if((orientacion)%4==0)//Le precedía un pasillo con orientacion Oeste.
		{
			if ((next[0]->oi.x+next[0]->l)>(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.x-=0.5;	
		}

		//ESTE
		else if((orientacion)%4==1)//Le precedía un pasillo con orientacion Norte.
		{
			if ((next[0]->oi.y+next[0]->l)<(Limite.y))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.y-=0.5;
		}

		//SUR
		else if((orientacion)%4==2)//Le precedía un pasillo con orientacion Este.
		{
			if ((next[0]->oi.x-next[0]->l)>(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.x+=0.5;	
		}

		//OESTE
		else if((orientacion)%4==3)//Le precedía un pasillo con orientacion Sur.
		{
			if ((next[0]->oi.y-next[0]->l)>(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.y-=0.5;	//cambioo
		}
		
		/*if ((next[0]->oi.x+next[0]->l)<0)
			propaga();
		for(int i=0;i<MAX;i++)
			next[i]->oi.x-=0.5;*/
	}

	else if(next[0]->tipo==ESQUINA_IZQ)
	{
		//NORTE
		if(orientacion%4==0)//Le precedía un pasillo con orientacion Oeste.
		{
			if ((next[0]->oi.x+next[0]->l)>(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.x+=0.5;	
		}

		//ESTE
		else if(orientacion%4==1)//Le precedía un pasillo con orientacion Norte.
		{
			if ((next[0]->oi.y+next[0]->l)<(Limite.y))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.y-=0.5;	
		}

		//SUR
		else if((orientacion)%4==2)//Le precedía un pasillo con orientacion Este.
		{
			if ((next[0]->oi.x-next[0]->l)<(Limite.x))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.x+=0.5;	
		}

		//OESTE
		else if((orientacion)%4==3)//Le precedía un pasillo con orientacion Sur.
		{
			if ((next[0]->oi.y-next[0]->l)>(Limite.y))
				propaga();
			for(int i=0;i<MAX;i++)
				next[i]->oi.y+=0.5;	
		}

		/*if (next[0]->oi.x>next[0]->l)
			propaga();
		for(int i=0;i<MAX;i++)
			next[i]->oi.x+=0.5;*/

		/*if ((next[0]->oi.y+next[0]->l)<0)
		propaga();
		for(int i=0;i<MAX;i++)
		{
			next[i]->oi.y-=0.5;
		}*/
	}
}
		



void Universidad::propaga()
{
	delete next[0];
	next[0]=next[1];
	next[1]=next[2];
	
	if(next[1]->tipo==ESQUINA_DRCH)
	{
			for(int i=0;i<2;i++){
			//Suelo *b=new Pasillo(next[1]->oi.x,next[1]->oi.y+next[1]->l,2*next[1]->l,next[1]->l);
			Suelo *b=new Pasillo(0,0,0,0);
			*b=next[1]->generaSiguiente(1);
			next[2]=b;
			}
	}
	
	if(next[1]->tipo==ESQUINA_IZQ)
	{
			for(int i=0;i<2;i++){
			//Suelo *b=new Pasillo(next[1]->oi.x,next[1]->oi.y+next[1]->l,2*next[1]->l,next[1]->l);
			Suelo *b=new Pasillo(0,0,0,0);
			*b=next[1]->generaSiguiente(1);
			next[2]=b;
			}
	}

	else if(next[1]->tipo==PASILLO)
	{
		int tipoSiguiente=rand()%3 +1;
		if(tipoSiguiente==1)
		{
			Suelo *b=new Pasillo(0.0f,0.0f,0.0f,0.0f);
			Limite=next[0]->oi;//PRUEBA
			*b=(next[1]->generaSiguiente(tipoSiguiente));
			next[2]=b;
		}
		else if(tipoSiguiente==2)
		{
			Suelo *b=new EsquinaIzquierda(0.0f,0.0f);
			Limite=next[0]->oi;//PRUEBA
			*b=(next[1]->generaSiguiente(tipoSiguiente));
			next[2]=b;
		}
		else if(tipoSiguiente==3)
		{
			Suelo *b=new EsquinaDerecha(0.0f,0.0f);
			Limite=next[0]->oi;//PRUEBA
			*b=(next[1]->generaSiguiente(tipoSiguiente));
			next[2]=b;
		}
	}
}



	
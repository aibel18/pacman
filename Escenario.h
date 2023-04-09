#ifndef Escenario_h
#define Escenario_h

#include <windows.h>
#include <math.h>
#include <time.h>

#include "Actor.h"


class Escenario{
private:
	char rejilla[50][60];
	float anchoRegilla ;

	int posX;
	int posY;
	int alto;
	int ancho;
public:
	Escenario();
	~Escenario(){
		for(int i=0;i<alto;i++)
			for(int j=0;j<ancho;j++)
				rejilla[i][j] = 0;
	}

	void setDimesion(int,int);

	void inicializar();

	void inicializar2();

	char* getAdyacentes(int,int);

	char* getAdyacentes2(int,int);

	char* getActor(int,int);

	bool agregarActor(Actor*);
	bool agregarActor(int,int,char);

	void dibujarEscenario();

	void actualizarEscanario();

	void cambiar(int,int,Actor*);


	void operator = (Escenario*);

};

#endif
#ifndef Juego_h
#define Juego_h

#include "Fantasma.h"
#include "Pacman.h"
#include "Objetivo.h"

#define numO 10
#define numF 20

class Juego{
private:

	int ancho;
	int alto;

public:

	int estado;

	Escenario escenario;
	Fantasma fantasma[numF];
	Pacman pacman;

	Cola cola;
	
	
public:
	Juego();
	~Juego(){
		ancho =0;
		alto =0;

		escenario.~Escenario();

		for(int i =0;i<numF;i++)
			fantasma[i].~Fantasma();

	}
	void dibujar();
	void actualizar();
};
#endif
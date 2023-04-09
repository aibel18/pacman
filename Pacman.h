#ifndef H_Pacman
#define H_Pacman

#include "ColaPrioridad.h"
#include "Escenario.h"
#include <string>

using namespace std;

class Pacman:public Actor{

public:

	string movi;

	Actor objetivo;
	Pacman();
	void analizar(char *,Escenario* es,int&);

	void girar(char *);

	void mover(Escenario*);

	void buscaObjetivo(Escenario*);

	bool verificar(int,char*);

};


void busqueda_A(Nodo *nodo,Par &ob,Escenario *,string &s);

void heuristica(Nodo * n,double g, Par&ob);
void heuristica2(Nodo * n,double g, Par&ob);

void heuristica3(Nodo * n,int,int);

void sucesores(Cola& cola,Nodo* n,Escenario * es, Par &ob);

#endif
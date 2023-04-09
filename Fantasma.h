#include "Escenario.h"

class Fantasma:public Actor{
public:

	Fantasma();
	~Fantasma(){

	}

	void analizar(char *);

	void girar(char *);

	void girar2(char *);

	void mover(Escenario*);

};
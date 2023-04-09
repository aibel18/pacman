#include "Escenario.h"
#include "ColaPrioridad.h"

class Objetivo:public Actor{
public:

	Objetivo();

	void mover(Escenario*);
};
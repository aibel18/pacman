#include "Objetivo.h"

Objetivo::Objetivo(){

	tipo = 'o';

}

void Objetivo::mover(Escenario* es){

	if( estado && *es->getActor(posX,posY) == 'p' )
		estado = INACTIVO;		
	

	if( estado )
		es->cambiar(posX,posY,this);

	

	
}
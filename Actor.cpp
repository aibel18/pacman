#include "Actor.h"

Actor::Actor(){

	posX = 0;
	posY = 0;

	estado = ACTIVO;

	sentido = 0;

}

void Actor::setPosicion(int _x,int _y){

	posX = _x;
	posY = _y;
}

int Actor::getX(){
	return posX;
}
int Actor::getY(){
	return posY;
}
char Actor::getTipo(){
	return tipo;
}
int Actor::getEstado(){
	return estado;
}
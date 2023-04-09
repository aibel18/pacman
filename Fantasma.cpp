#include "Fantasma.h"

Fantasma::Fantasma(){	

	tipo = '*';

}

void Fantasma::mover(Escenario* es){

	int x = posX;
	int y = posY;

	switch(sentido){
		case 0:posX -= 1 ; break;
		case 1:posY -= 1 ;break;
		case 2:posX += 1 ;break;
		case 3:posY += 1 ;break;
		default: sentido = ( ( abs( (int)time(0)*rand() ) )%4);return ;
	}

	es->cambiar(x,y,this);

}
void Fantasma::analizar(char *cadena ){

	if( cadena[ sentido ] == ' ' || cadena[sentido] == '*' || cadena[sentido] == 'o' || cadena[ sentido] == 'p' )
			return;
		
	girar(cadena);

	delete [4]cadena;
	cadena =0;
	
}
void Fantasma::girar(char *cadena ){

	int a = ( ( abs( (int)time(0)*rand() ) )%4)+1;

	for( int i= sentido; i< sentido+4 ; i++ ){		

		if( cadena[ (i+a)%4 ] == ' ' ){
			sentido = ((i+a)%4);
			return;
		}
	}
	sentido = -1;
}

void Fantasma::girar2(char *cadena ){

	int a = ( ( abs( (int)time(0)*rand() ) )%2)*2+1;

	for( int i= 0; i< 3 ; i +=2 ){		

		if( cadena[ (i + a + sentido)%4 ] == ' ' ){
			sentido = (i + a + sentido)%4;
			break;
		}
	}
}

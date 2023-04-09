#include "Juego.h"

Juego::Juego(){

	estado = 0;

	ancho = 43;
	alto = 35;

	escenario.setDimesion(ancho,alto);

	escenario.inicializar();


	int x=0;
	int y=0;

	for(int i = 0; i< numF ; i++){

		do{
			x= ( abs( (int)time(0)*rand() ) )%alto;
			y= ( abs( (int)time(0)*rand() ) )%(ancho-1)+1;

			fantasma[i].setPosicion(x,y);

		}
		while( !escenario.agregarActor(&fantasma[i]) );
		
	}

	x= ( abs( (int)time(0)*rand() ) )%alto;

	pacman.setPosicion(x,0);

	escenario.agregarActor(&pacman);

	for(int i = 0; i< numO ; i++){

		Objetivo* actor = new Objetivo();

		do{
			x= ( abs( (int)time(0)*rand() ) )%alto;
			y= ( abs( (int)time(0)*rand() ) )%(ancho-1)+1;

			actor->setPosicion(x,y);

		}
		while( !escenario.agregarActor(actor) );

		
		Nodo* nodo = new Nodo(actor);

		heuristica3(nodo,pacman.getX(),pacman.getY());
		
		cola.insertar(nodo);		
		
	}

	Actor  temp = *((Actor*)cola.inicio->contenido);

	pacman.objetivo.setPosicion(temp.getX(),temp.getY());

	pacman.buscaObjetivo(&escenario);

}
int t=0;
int t2=10;
void Juego::actualizar(){	

	char * temp =0;

	temp = escenario.getAdyacentes2(pacman.getX(),pacman.getY());

	pacman.analizar( temp ,&escenario,estado);	

	pacman.mover(&escenario);

	Objetivo* ob ;
	Nodo *tem = cola.inicio;

	for(int i=0; i<numO && tem;i++){

		ob = ((Objetivo*)tem->contenido);

		ob->mover(&escenario);

		tem = tem->siguiente;

		if( !ob->getEstado() ){
			cola.eliminar(ob);
			if( cola.numeroN ){
				ob = ((Objetivo*)cola.inicio->contenido);
				pacman.objetivo.setPosicion(ob->getX(),ob->getY());
			}
			else
				estado =1;
		}		
	}

	for(int i=0; i<numF;i++){

		temp = escenario.getAdyacentes( fantasma[i].getX(),fantasma[i].getY() );
	
		if(t%t2==0){
			fantasma[i].girar2(temp);

			t2 = ( abs( (int)time(0)*rand() ) )%15+1;
			if(t >1000)
				t=0;
		}
		t++;	

		fantasma[i].analizar(temp);
		fantasma[i].mover(&escenario);
	}	

}


void Juego::dibujar(){

	escenario.dibujarEscenario();
}

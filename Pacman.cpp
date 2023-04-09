#include "Pacman.h"

Pacman::Pacman(){

	tipo = 'p';
}

void Pacman::mover(Escenario* es){

	int x = posX;
	int y = posY;

	switch(sentido){
		case 0:posX -= 1 ; break;
		case 1:posY -= 1 ;break;
		case 2:posY += 1 ;break;
		case 3:posX += 1 ;break;				
	}
	
	es->cambiar(x,y,this);

}

bool Pacman::verificar(int i ,char * cadena ){
	switch( i ){
		case 0: if( cadena[0] == '*'  || cadena[2] == '*'  || cadena[9] == '*')
					return false;
				break;
		case 1: if( cadena[0] == '*'  || cadena[6] == '*'  || cadena[10] == '*')
					return false;
				break;
		case 2: if( cadena[2] == '*'  || cadena[8] == '*'  || cadena[11] == '*')
					return false;
				break;
		case 3: if( cadena[6] == '*'  || cadena[8] == '*'  || cadena[12] == '*')
					return false;
				break;
	}
	return true;
}
void Pacman::analizar(char *cadena ,Escenario* es ,int & esta){

	if( cadena[4] == '*' || cadena[4] == ' ' ){
		estado = INACTIVO;
		esta = 2;
	}

	if( estado && movi.size() ==0){
		buscaObjetivo(es);	

		if( movi.size() ==0){
			girar(cadena);
			delete [13]cadena;
			cadena =0;
			return;
		}		
	}		

	if(estado ){

		sentido = movi[0]-'0';

		movi = movi.substr(1);


		if( !verificar(sentido,cadena) || cadena[sentido*2+1] == '*' ){
			
				girar(cadena);

			delete [13]cadena;
			cadena =0;
			return;
		}


	}
	else{
		sentido = -1;
	}

	delete [13]cadena;
	cadena =0;
	
}
void Pacman::girar(char *cadena ){

	for( int i= 0; i< 4 ; i++ ){		

		if( ( cadena[ i*2+1 ] == ' ' && verificar(i,cadena) ) || cadena[i*2+1] == 'o' ){
			
			sentido = i;

			movi ="";
			return;
		}
	}
	movi ="";
	sentido = -1;
}

void Pacman::buscaObjetivo(Escenario* es){
	
	Par * par = new Par();
	par->x = posX;
	par->y = posY;

	par->movimiento =0;

	Nodo * nodo = new Nodo(par);

	Par parO;
	parO.x = objetivo.getX();
	parO.y = objetivo.getY();

	Escenario es2;
	es2.operator=( es);

	busqueda_A(nodo,parO,&es2,movi);	
}

void heuristica(Nodo * n,double g, Par&ob){

	Par * p = ((Par *)n->contenido);
	
	n->h = sqrt( pow( p->x - ob.x ,2.) + pow( p->y - ob.y,2. ) );

	n->f = n->h + g;

}

void heuristica2(Nodo * n,double g, Par&ob){

	Par * p = ((Par *)n->contenido);
	
	n->h = abs(  p->x - ob.x ) + abs( p->y - ob.y  );

	n->f = n->h + g;

}

void heuristica3(Nodo * n,int _x,int _y){

	Actor * p = ((Actor*)n->contenido);
	
	n->h = sqrt( pow( p->getX() - _x ,2.) + pow( p->getY() - _y,2. ) );

	n->f = n->h;

}

void busqueda_A( Nodo *nodo,Par &ob,Escenario *es,string &s ){

	Cola nuevaCola;

	Cola nuevaColaT;

	heuristica(nodo,0,ob);

	nuevaCola.insertar(nodo);

	Nodo *temp=0;

	while( true ){

		if( nuevaCola.numeroN ==0 )
			return ;

		temp = nuevaCola.sacar();

		nuevaColaT.insertar(temp);
			
		if(  temp->h == 0 ){

			while( temp && temp->padre){
			
				s = ((Par *)temp->contenido)->movimiento + s;
				temp = temp->padre;
			}
			return ;
		}

		sucesores(nuevaCola,temp,es,ob);
	}

}

void sucesores(Cola& cola,Nodo* n,Escenario * es, Par &ob){

	Par* temp = (Par*)n->contenido;
	
	char * cadena = es->getAdyacentes2(temp->x,temp->y);

	if( cadena[1] == ' ' || cadena[1] == 'o' ){

		Par *nuevo = new Par ();

		nuevo->x = temp->x -1;
		nuevo->y = temp->y;

		es->agregarActor(nuevo->x,nuevo->y,'p');

		nuevo->movimiento = '0';

		Nodo *nuevoN = new Nodo(nuevo);
		nuevoN->padre = n;

		heuristica(nuevoN,n->f,ob);
		cola.insertar(nuevoN);
	}

	if( cadena[3] == ' ' || cadena[3] == 'o'){

		Par *nuevo = new Par ();

		nuevo->x = temp->x;
		nuevo->y =temp->y - 1;

		es->agregarActor(nuevo->x,nuevo->y,'p');

		nuevo->movimiento = '1';
		

		Nodo *nuevoN = new Nodo(nuevo);
		nuevoN->padre = n;

		heuristica(nuevoN,n->f,ob);
		cola.insertar(nuevoN);
	}

	if( cadena[5] == ' ' || cadena[5] == 'o'){

		Par *nuevo = new Par ();

		nuevo->x = temp->x;
		nuevo->y = temp->y + 1;

		es->agregarActor(nuevo->x,nuevo->y,'p');

		nuevo->movimiento = '2';
		

		Nodo *nuevoN = new Nodo(nuevo);
		nuevoN->padre = n;

		heuristica(nuevoN,n->f,ob);
		cola.insertar(nuevoN);
	}

	if( cadena[7] == ' ' || cadena[7] == 'o'){

		Par *nuevo = new Par ();

		nuevo->x =temp->x + 1;
		nuevo->y = temp->y;

		es->agregarActor(nuevo->x,nuevo->y,'p');

		nuevo->movimiento = '3';
		

		Nodo *nuevoN = new Nodo(nuevo);
		nuevoN->padre = n;

		heuristica(nuevoN,n->f,ob);
		cola.insertar(nuevoN);
	}

	delete [13]cadena;

	cadena =0;
	
}
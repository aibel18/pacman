#include "ColaPrioridad.h"

//----------Lista---------


void Cola::insertar( Nodo* n){

	if( inicio== 0 && numeroN ==0 ){
		inicio = n;
		inicio->siguiente = 0;
		fin =inicio;

		numeroN =1;
	}
	else{

		Nodo *temp = inicio;
		Nodo *padre=0;
		while(temp){
			
			if( n->f <= temp->f && n->h < temp->h){
				break;
			}
			padre = temp;
			temp = temp->siguiente;
		}
		if( padre == 0){
			n->siguiente = inicio;
			inicio = n;	
		}
		else if( temp == 0){
			fin->siguiente = n;

			fin = n;
		}
		else{
			padre->siguiente = n;

			n->siguiente = temp;
		}
		numeroN++;
		
	}

}

Nodo* Cola::sacar(){

	Nodo * nodo = inicio;

	inicio = inicio->siguiente;

	nodo->siguiente=0;

	numeroN--;

	return nodo;

}

void Cola::eliminar(void* nod){

	Nodo *temp = inicio;
	Nodo *padre=0;

	while(temp){
			
		if( temp->contenido == nod )
			break;
	
		padre = temp;
		temp = temp->siguiente;
	}

	if( padre == 0){
		inicio = temp->siguiente;

		temp->siguiente =0;
	}
	else if(temp->siguiente ==0){

		fin->siguiente = 0;
		padre->siguiente = 0;

	}
	else{
		padre->siguiente = temp->siguiente;

		temp->siguiente =0;
	}
	
	numeroN--;

	delete temp->contenido;

	temp->contenido =0;

	delete temp;

}

void Cola::eliminarCola(){

	Nodo * nodo;

	while(inicio){

		 nodo = inicio;

		inicio = inicio->siguiente;

		nodo->siguiente=0;
		nodo->padre=0;

		delete nodo->contenido;

		delete nodo;
		
	}
	numeroN=0;

}
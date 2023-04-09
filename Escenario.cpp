#include "Escenario.h"


#include <GL/gl.h>
#include <GL/glu.h>

Escenario::Escenario(){

	anchoRegilla = 20;
	
	posX = 10;
	posY = 10;

}

//cargando las dimensiones del escenario
void Escenario::setDimesion(int ancho, int alto){
	this->ancho = ancho;
	this->alto = alto;
}

//inicializamos el la matriz del escenario
void Escenario::inicializar(){

	int a=0;

	for(int k =0; k < alto;k++){

		 a = ( abs( (int)time(0)*rand() ) )%3+1;		

		for(int i =k; i<k+a && i< alto && k < alto; i++)

			for(int j =0; j<ancho; j++){

				if( j % (a+2) )
					rejilla[i][j] = '|';
			
				else
					rejilla[i][j] = ' ';			
			}

		k = k+ a;

		for(int j =0; j<ancho && k <alto; j++)
				rejilla[k][j] = ' ';
			
		if(k%4 == 0)
			k--;
	}

}

void Escenario::inicializar2(){

	char temp [30][40] = {	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|','|','|','|',' ','|','|','|','|','|','|',' ','|','|','|','|',' ','|',' ','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|','|','|','|',' ','|','|','|','|','|','|',' ','|','|','|','|',' ','|',' ','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ','|','|','|','|','|','|',' ','|','|','|','|',' ','|',' ','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ','|','|',' ','|','|','|',' ','|',' ','|','|','|','|','|','|','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ','|',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ','|','|','|','|','|','|',' ','|','|','|',' ','|',' ','|',' ','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','|',' ','|',' ','|',' ','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{'|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','|',' ','|',' ','|',' ','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{'|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{'|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|','|','|',' ','|','|','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{'|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{'|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','|','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','|','|','|','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','|','|',' ','|','|','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|','|','|','|','|','|','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','|','|',' ','|',' ','|','|','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|','|',' ','|','|','|',' ','|','|','|','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ','|','|','|',' ','|','|','|',' ','|','|','|','|','|',' ','|','|','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

	for(int i = 0; i < alto ; i++)
		for(int j = 0; j < ancho ; j++)
			rejilla[i][j] = temp[i][j];

}
//inicializamos la posiciones de los actores
bool Escenario::agregarActor(Actor *actor){

	int x = actor->getX();
	int y = actor->getY();

	if( x < alto && y < ancho && rejilla[x][y] == ' '){
		rejilla[x][y] = actor->getTipo();
		return true;
	}
	return false;
}

//inicializamos la posiciones de los actores
bool Escenario::agregarActor(int x,int y,char tipo){

	if(x < alto && y < ancho && rejilla[x][y] == ' ' ){
		rejilla[x][y] = tipo;
		return true;
	}
	return false;
}


char* Escenario::getAdyacentes(int x,int y){

	char *alrededor = new char[4];

	int tx ;
	int ty ;

	int signo = -1;

	for(int i=0; i<4 ;){		

		for(int j=0; j<2 ;j++,i++){

			tx = (j+1)%2*signo;
			ty = j*signo;

			if(x+tx >= 0 && x+tx < alto && y+ty >= 0 && y+ty < ancho){
				alrededor[i] = rejilla[x + tx][y + ty];
			}
			else
				alrededor[i] = '-';
		}
		signo *= signo;
	}

	return alrededor;

}

char* Escenario::getAdyacentes2(int x,int y){

	char *alrededor = new char[13];

	int tempX =0;
	int tempY =0;

	int k=0;

	for(int i= -1; i< 2 ;i++){
		for(int j= -1 ; j < 2 ;j++,k++){

			tempX = x + i;
			tempY = y + j;

			if( tempX >= 0 && tempX < alto && tempY >= 0 && tempY < ancho)
				alrededor[k] = rejilla[tempX][tempY];
			else
				alrededor[k] = '-';
		}
	}

	tempX = x -2;
	tempY = y;

	if( tempX >= 0 && tempX < alto && tempY >= 0 && tempY < ancho)
		alrededor[k] = rejilla[tempX][tempY];
	else
		alrededor[k] = '-';

	k++;
	

	tempX = x;
	tempY = y -2;

	if( tempX >= 0 && tempX < alto && tempY >= 0 && tempY < ancho)
		alrededor[k] = rejilla[tempX][tempY];
	else
		alrededor[k] = '-';

	k++;

	tempX = x;
	tempY = y +2;

	if( tempX >= 0 && tempX < alto && tempY >= 0 && tempY < ancho)
		alrededor[k] = rejilla[tempX][tempY];
	else
		alrededor[k] = '-';

	k++;

	tempX = x +2;
	tempY = y;

	if( tempX >= 0 && tempX < alto && tempY >= 0 && tempY < ancho)
		alrededor[k] = rejilla[tempX][tempY];
	else
		alrededor[k] = '-';


	return alrededor;

}

char* Escenario::getActor(int x,int y){


	return &rejilla[x][y];

}

//dibujamos la matriz del escenario

void Escenario::dibujarEscenario(){	

	glPointSize(anchoRegilla);
	
	glBegin(GL_POINTS);

	for(int i=0;i<alto;i++)
		for(int j=0;j<ancho;j++){

			if(rejilla[i][j]== '|'){
				glColor3f(0.f,0.f ,.9f );
				glVertex3f(j*anchoRegilla ,i*anchoRegilla,0);
			}
			else if(rejilla[i][j]== '*'){

				glColor3f(1.f,0.f ,0.f );
				glVertex3f(j*anchoRegilla ,i*anchoRegilla ,0);
			}
			else if(rejilla[i][j]== 'o'){

				glColor3f(0.f,.75f ,0.f );
				glVertex3f(j*anchoRegilla,i*anchoRegilla,0);
			}
			else if(rejilla[i][j]== 'p'){
				
				glColor3f(0.95f,0.95f ,0.f );
				glVertex3f(j*anchoRegilla,i*anchoRegilla,0);
			}	
	
		}
	glEnd();
}
void Escenario::cambiar(int ix,int iy,Actor* actor){

	if( ix < 0 && ix >= alto && iy < 0 && iy >= ancho ){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

	rejilla[ix][iy] =' ';
	rejilla[actor->getX()][actor->getY()] = actor->getTipo();;

}

void Escenario::operator = (Escenario* es){

	anchoRegilla  = es->anchoRegilla;

	posX = es->posX;
	posY = es->posY;
	alto = es->alto;
	ancho = es->ancho;

	for(int i=0;i<alto;i++)
		for(int j=0;j<ancho;j++){

			rejilla [i][j] = es->rejilla[i][j];
		}
	

}
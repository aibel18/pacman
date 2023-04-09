#ifndef H_Actor
#define H_Actor

#define ACTIVO 1
#define INACTIVO 0

class Actor{
protected:
	int posX;
	int posY;
	int sentido;

	int estado;

	char tipo;

public:
	Actor();
	~Actor(){
		posX =0;
		posY =0;
		sentido =0;
		estado =0;
		tipo =0;
	}

	void setPosicion(int,int);

	int getY();
	int getX();

	char getTipo();

	int getEstado();

};

#endif
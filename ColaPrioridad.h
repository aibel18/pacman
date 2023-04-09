#ifndef H_Cola
#define H_Cola

class Nodo{
public:

	void * contenido;
	Nodo * siguiente;
	Nodo * padre;

	double f;
	double h;

	Nodo(void * con){


		f=0;
		h=0;

		contenido = con;
		siguiente = 0;
		padre =0;
	}

};

class Cola{
public:

	Nodo * inicio;
	Nodo * fin;
	int numeroN;

	Cola(){
		inicio =0;
		fin =0;
		numeroN=0;
	}
	~Cola(){
		eliminarCola();
	}
	void insertar(Nodo*);
	Nodo * sacar();

	void eliminar(void*);

	void eliminarCola();
};

class Par{
public:
	int x;
	int y;

	char movimiento;
};

#endif
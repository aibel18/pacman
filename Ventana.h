#ifndef Ventana_h
#define Ventana_h

#include <windows.h>

#pragma comment( lib, "openGL32.lib" )
#pragma comment( lib, "glu32.lib" )

#include <GL/gl.h>
#include <GL/glu.h>

//clase Ventana ----------
class Ventana{

private:
	WNDCLASS  claseVentana;
public:
	HWND      IdVentana;
public:
	HDC      IdDC;
	HGLRC OGLrc;

	HINSTANCE IdAplicacion;
	const char *nombreVentana;
	MSG       Mensaje;

	GLuint tex_usw;

	Ventana();
	Ventana(WNDPROC ,char const* ,HINSTANCE);
	~Ventana(){
		limpiar();	
	}
	void registrar();
	void mostrar(int );
	void crearVentana(int,int);
	void limpiar();

	void inicializarGL();

	bool cicloMensaje(void);

};
//procesos de la ventana
LRESULT CALLBACK procesos
    (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif
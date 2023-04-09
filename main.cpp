#include "Ventana.h"

#include "Juego.h"
#include "botones.h"


int WINAPI WinMain(	HINSTANCE hInst,HINSTANCE hPrevInst,
				   char* cmdParam,int cmdShow)
{

	Ventana ven(procesos,"Mi Ventana",hInst);
	ven.crearVentana(866,738);
	ven.mostrar(cmdShow);

	ven.inicializarGL();

	Juego juego;
	juego.dibujar();
	SwapBuffers(ven.IdDC);

	while ( !ven.cicloMensaje() && !juego.estado)
	{
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		juego.actualizar();

		juego.dibujar();
		Sleep(100);

		SwapBuffers(ven.IdDC);
		
	}

	Imagen imagen(hInst,ven.IdVentana);

	if(juego.estado == 1)

		imagen.cargarImagen("Felicidades.bmp",80,50,512,512);
	else
		imagen.cargarImagen("over.bmp",80,50,512,512);

	Sleep(3000);

	
	return ven.Mensaje.wParam;
	
}
#include "Ventana.h"
#include "Botones.h"

Ventana::Ventana(){
}

Ventana::Ventana(WNDPROC winProc, const char *nombre, HINSTANCE hins){
	nombreVentana = nombre;
	IdAplicacion = hins;

	claseVentana.style = CS_OWNDC;
	claseVentana.lpfnWndProc= winProc;
	claseVentana.cbWndExtra =0;
	claseVentana.cbClsExtra =0;
	claseVentana.hInstance = IdAplicacion;
	claseVentana.hIcon =0;
	claseVentana.hCursor = LoadCursor(0,IDI_APPLICATION);
	claseVentana.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	claseVentana.lpszMenuName =0;
	claseVentana.lpszClassName =nombreVentana;
	registrar();
}
void Ventana::crearVentana(int ancho,int alto){

	IdVentana = CreateWindowEx(
		WS_EX_APPWINDOW,
		nombreVentana,
		nombreVentana,
		WS_OVERLAPPEDWINDOW|SS_BITMAP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		ancho,
		alto,
		0,
		LoadMenu(IdAplicacion,"Menu"),
		IdAplicacion,
		0
		);

	if(!IdVentana){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

}
void Ventana::registrar(){
	if(!RegisterClass(&claseVentana)){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}
}
void Ventana::mostrar (int cmdShow)
{
        ShowWindow (IdVentana, cmdShow);
        UpdateWindow (IdVentana);
}
bool Ventana::cicloMensaje(void){

	if (PeekMessage(&Mensaje,NULL,0,0,PM_REMOVE)){

		if (Mensaje.message==WM_QUIT)	
			return true;
		else{			
			TranslateMessage(&Mensaje);
			DispatchMessage(&Mensaje);
               return false;
		}
	}
	else		          
		return false;
}
void Ventana::inicializarGL(){


	static PIXELFORMATDESCRIPTOR pfd =
	{				
		sizeof(PIXELFORMATDESCRIPTOR),
		1,	
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |	
        PFD_DOUBLEBUFFER |	
        PFD_TYPE_RGBA,	
		32,			
		0,0,0,0,0,0,	
		0,	
		0,	
		0,
		0,0,0,0,	
		32,	
		0,	
		0,	
        PFD_MAIN_PLANE,	
		0,
		0,0,0,
		};	


	IdDC = GetDC(IdVentana);

	if(!IdDC){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

	int PixF=ChoosePixelFormat(IdDC,&pfd);

	if(!PixF){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

	
	if(!SetPixelFormat(IdDC,PixF,&pfd)){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

	OGLrc=wglCreateContext(IdDC);

	if(!OGLrc){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

	;

	if(!wglMakeCurrent(IdDC,OGLrc)){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}

	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glClearColor(1,1,1,1.0f);

	glShadeModel(GL_SMOOTH);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);


	RECT rect; 

	GetClientRect(IdVentana, &rect);

	glViewport(rect.left+5,rect.top-5,rect.right,rect.bottom);

	glOrtho(0,rect.right,rect.bottom,0,-1,1); 

	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	SwapBuffers(IdDC);

}

void Ventana::limpiar(){

	wglMakeCurrent(IdDC,0);
	wglDeleteContext(OGLrc);

	ReleaseDC(IdVentana,IdDC);

	DestroyWindow(IdVentana);
	UnregisterClass(nombreVentana,IdAplicacion);
}


//procesos de la ventana principal
LRESULT CALLBACK  procesos(HWND hwnd, UINT message, WPARAM wParam, LPARAM
							lParam)
{
	switch (message)
	{		
		case WM_DESTROY:
		{	PostQuitMessage (0);
			
			return 0;
		}
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}



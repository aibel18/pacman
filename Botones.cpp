#include "Botones.h"
BotonEdit::BotonEdit(HINSTANCE hinst,HWND hwnd,HMENU h)
{
	IdPadre =hwnd;
	IdAplicacion= hinst;
	hijo=h;
}
void BotonEdit::set(HINSTANCE hinst,HWND hwnd,HMENU h)
{
	IdPadre =hwnd;
	IdAplicacion= hinst;
	hijo=h;
}
void BotonEdit::crear_boton(int iniX,int iniY,int x,int y)
{
	IdVentana= CreateWindow("edit","" ,
	WS_VISIBLE|WS_CHILD|WS_BORDER|ES_WANTRETURN|estilo,
	iniX,iniY,x,y ,IdPadre, (HMENU)hijo, IdAplicacion, NULL);
}
void BotonEdit::SetEstilo(int e0,int e1,int e2,int e3,int e4){

	estilo =e0|e1|e2|e3|e4;
}

//-------------
BotonStatic::BotonStatic(HINSTANCE hinst,HWND hwnd )
{
	IdPadre =hwnd;
	IdAplicacion= hinst;	

}
void BotonStatic::set(HINSTANCE hinst,HWND hwnd)
{
	IdPadre =hwnd;
	IdAplicacion= hinst;
	
}
void BotonStatic::SetEstilo(int e0,int e1,int e2,int e3,int e4){

	estilo =e0|e1|e2|e3|e4;
}
void BotonStatic::crear_boton(char* nombre,int iniX,int iniY,int x,int y)
{
	IdVentana= CreateWindow("static", nombre,
	WS_VISIBLE|WS_CHILD,
	iniX,iniY,x,y, IdPadre, (HMENU)NULL, IdAplicacion, NULL);
}
//-------------
Boton::Boton(HINSTANCE hinst,HWND hwnd,HMENU h)
{
	IdPadre =hwnd;
	IdAplicacion= hinst;
	hijo=h;
}

void Boton::crear_boton(char* nombre,int iniX,int iniY,int x,int y)
{
	IdVentana= CreateWindow("button", nombre,
	WS_VISIBLE|WS_CHILD,
	iniX,iniY,x,y, IdPadre, (HMENU)hijo, IdAplicacion, NULL);
}

//-------------
Imagen::Imagen(HINSTANCE hinst,HWND hwnd)
{
	IdPadre =hwnd;
	IdAplicacion= hinst;
}

void Imagen::cargarImagen(char* nombre,int iniX,int iniY,int x,int y)
{

	bitmap = (HBITMAP)LoadImage(NULL,nombre, IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

	IdVentana = CreateWindowEx(0,"STATIC","",SS_CENTERIMAGE | SS_REALSIZEIMAGE |SS_BITMAP |WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				iniX,iniY, x, y, IdPadre,  NULL, IdAplicacion, NULL);

	if(bitmap == NULL)
		MessageBox(NULL,"No se encontro la imagen bmp", "Error", MB_OK | MB_ICONWARNING);
			
	else
		SendMessageA(IdVentana,STM_SETIMAGE, (WPARAM)IMAGE_BITMAP,(LPARAM)bitmap);


}
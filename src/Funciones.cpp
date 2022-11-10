#include <cstdio>
#include <ctime>
#include <windows.h>
#include <iostream>
#include "Cliente.h"
#include "Archivo.h"
using namespace std;

void mostrar_fecha(){
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  printf("%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
  strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tama�o
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tama�o de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}
/// DEFINICION FUNCIONES GLOBALES

void cargarCadena(char *pal, int tam){  /// CARGA CADENAS DE CARACTERES
  int i;
  fflush(stdin);
  for(i = 0; i < tam; i++){
      pal[i] = cin.get();
	  if(pal[i] == '\n') break;
        if (pal[i] == '�') pal[i] = char(164);
	  }
  pal[i] = '\0';
  fflush(stdin);
}
bool validarCadena(string x){
    int i;
    char c;
    for(i=0;i<x.size();i++){
        c=x[i];
        if(isalpha(c)==0){
            if(isspace(c)==0){
                return false;
            }
        }
    }
    return true;
}

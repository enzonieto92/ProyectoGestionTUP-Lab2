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

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}
/// DEFINICION FUNCIONES GLOBALES

bool cargarCadena(char *pal, int tam){  /// CARGA CADENAS DE CARACTERES
  int i = 0;
  char aux;
  bool control = true;
  fflush(stdin);
while (control){
        aux = getch();
        switch (aux){

    default:
        pal[i] = aux;
        cout <<aux;
        if (pal[i] == 'á') pal[i] = char(160);
        if (pal[i] == 'é') pal[i] = char(130);
        if (pal[i] == 'í') pal[i] = char(161);
        if (pal[i] == 'ó') pal[i] = char(162);
        if (pal[i] == 'ú') pal[i] = char(163);
        if (pal[i] == 'ñ') pal[i] = char(164);
        if (pal[i] == 'Ñ') pal[i] = char(165);
        i++;
        break;
    case '\033':
        i = 0;
        control = false;
        return false;
        break;
    case '\010':
        if (i < 1){
            i = 0;
        }
        else{
        cout << aux << " " << aux;
        i --;
        }
        break;
    case '\015':
        pal[i] = '\0';
        control = false;
        break;
    }

}
  fflush(stdin);
  return true;
}
bool validarCadena(string x){
   int tam = x.size();
    char c;
    if (x[0] == '\0'){
        return false;
    }
    for(int i = 0; i < tam; i++){
        c = x[i];
        if (c == char(160) || c == char(130) || c == char(161) || c == char(162) || c == char(163) || c == char(164) || c == char(165)){
        }
        else if(isalpha(c)==0){
            if(isspace(c)==0){
                return false;
            }
        }
    }
    return true;
}

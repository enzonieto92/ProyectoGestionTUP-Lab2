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


/// DEFINICION FUNCIONES GLOBALES

void cargarCadena(char *pal, int tam){  /// CARGA CADENAS DE CARACTERES
  int i;
  fflush(stdin);
  for(i = 0; i < tam; i++){
      pal[i] = cin.get();
	  if(pal[i] == '\n') break;
	  }
  pal[i] = '\0';
  fflush(stdin);
}

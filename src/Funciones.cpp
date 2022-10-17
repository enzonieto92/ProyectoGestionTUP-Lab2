#include <cstdio>
#include <ctime>
#include <windows.h>
#include <iostream>


void mostrar_fecha(){
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  printf("%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
  strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
}

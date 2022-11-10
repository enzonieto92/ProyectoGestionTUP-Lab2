#include "Servicio.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Servicio::Servicio(){
    precio = 1;
    strcpy(descripcion, "");
}

void Servicio::limpiarEspacios(int x, int y){
for (int i = x; i < 62; i++){
    for (int j = y; j < 20; j++){
        gotoxy(i, j);
        cout <<" ";
    }
}

}

void Servicio::cargar(int x, int y){

    limpiarEspacios(x, y);
    int _precio;
    gotoxy (x, y);
    cout << "DESCRIPCION: ";
    gotoxy (x+5, y+1);
    cout << "PRECIO: ";
    gotoxy(x+13,y);
    rlutil::showcursor();
    cargarCadena(descripcion, 29);
    gotoxy(x+13,y+1);
    cin >> _precio;

    precio = double(_precio);
    fflush(stdin);
    rlutil::hidecursor();
    }
bool Servicio::mostrar(){
        cout << descripcion << ": " << precio;
        return true;
}

/// SETS

bool Servicio::setPrecio(float var){
    if(var>0){
        precio = var;
        return true;
    }
    return false;
}
void Servicio::setDescripcion(const char *V){strcpy(descripcion,V);}
void Servicio::setServicio(Servicio aux){
*this = aux;
}
/// GETS

float Servicio::getPrecio(){return precio;}
const char *Servicio::getDescripcion(){return descripcion;}

void Servicio::operator = (Servicio aux){
setDescripcion(aux.getDescripcion());
setPrecio(aux.getPrecio());
}
bool Servicio::operator == (Servicio aux){
if (strcmp(descripcion, aux.getDescripcion()) == 0
&& precio == aux.getPrecio()){
return true;
}
else{
    return false;
}
}

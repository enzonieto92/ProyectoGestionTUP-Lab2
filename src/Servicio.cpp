#include "Servicio.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Servicio::Servicio(){
    precio = 0;
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
    char aux [30];
    limpiarEspacios(x, y);
    gotoxy (x, y);
    cout << "DESCRIPCION: ";
    gotoxy (x+5, y+1);
    cout << "PRECIO: ";
    gotoxy(x+13,y);
    rlutil::showcursor();
    if (cargarCadena(descripcion, 29)){

        if (validarCadena(descripcion) == true){
            gotoxy(x+13,y+1);
            if (cargarCadena(aux, 30)){

                if (isdigit(*aux)){
                setPrecio(aux);
                fflush(stdin);
                rlutil::hidecursor();
                }
                else{
                    cout <<"Ingrese un precio válido!";
                }
            }
            else{
                return;
            }
        }
        else{
            cout <<"Ingrese una descripción válida!";
        }
    }
    else{
        return;
    }

    }
bool Servicio::mostrar(int x, int y){
        gotoxy(x, y);
        cout << descripcion<<": ";
        gotoxy(x+28, y);
        cout <<"$" << precio;
        return true;
}

/// SETS
void Servicio::setPrecio(int aux){precio = aux;}
void Servicio::setPrecio(const char *P){
    int aux = atoi(P);
    precio = aux;}
void Servicio::setDescripcion(const char *D){strcpy(descripcion,D);}
void Servicio::setServicio(Servicio aux){
*this = aux;
}
/// GETS

int Servicio::getPrecio(){return precio;}
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

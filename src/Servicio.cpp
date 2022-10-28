#include "Servicio.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Servicio::Servicio(){
    codigo = 0;
    precio = 1;
    strcpy(descripcion, "SIN DATO");
    estado = false;
}

bool Servicio::cargar(int var){
    int pre;
    codigo = var;
    gotoxy (38, 18);
    cout << "DESCRIPCION: ";
    cargarCadena(descripcion,29);
    gotoxy (38, 20);
    cout << "PRECIO: ";
    cin >> pre;
    if(setPrecio(pre)==false){
        return false;
    }
    estado = true;
    return true;
}

bool Servicio::mostrar(){
    if(estado==true){
        cout << codigo << " " << descripcion << ": " << precio << endl;
        return true;
    }
    return false;
}

/// SETS

void Servicio::setCodigo(int var){codigo = var;}
bool Servicio::setPrecio(float var){
    if(var>0){
        precio = var;
        return true;
    }
    return false;
}
void Servicio::setDescripcion(const char *V){strcpy(descripcion,V);}
void Servicio::setEstado(bool ban){estado = ban;}

/// GETS

int Servicio::getCodigo(){return codigo;}
float Servicio::getPrecio(){return precio;}
const char *Servicio::getDescripcion(){return descripcion;}
bool Servicio::getEstado(){return estado;}

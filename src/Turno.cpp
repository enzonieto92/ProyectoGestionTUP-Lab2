#include "Turno.h"
#include <iostream>
#include "Funciones.h"
using namespace std;
Turno::Turno()
{
    //ctor
}

void Turno::Cargar(){

    cout << "NOMBRE: ";
    cargarCadena(nombre, 29);
    setNombre(nombre);

    cout << "APELLIDO: ";
    cargarCadena(apellido, 29);
    setApellido(apellido);

    _fecha.Cargar();


}

void Turno::Mostrar(){
        cout << nombre<<" ";
        cout << apellido <<"   ";
        _fecha.Mostrar();
}
void Turno::setNombre(const char *nom){strcpy(nombre, nom);}
void Turno::setApellido(const char *ape){strcpy(apellido, ape);}

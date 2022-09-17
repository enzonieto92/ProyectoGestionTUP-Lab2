#include "persona.h"

    persona::persona(){
    //ctor
    nombre = {};

    }
void persona::setNombre(){
    cout <<"Nombre: ";
    cin >>persona::nombre;

    }
string persona::getNombre(){
    return persona::nombre;
    }

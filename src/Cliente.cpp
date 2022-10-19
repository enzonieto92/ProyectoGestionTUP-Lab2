#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente()
{
    DNI = 0;
    strcpy(nombre, "SIN DATO");
    strcpy(apellido, "SIN DATO");
    strcpy(telefono, "SIN DATO");
    estado = false;
}

/// CARGAR
bool Cliente::Cargar(int nD){
    if(!setDNI(nD)){
        cout << "EL DNI DEBE SER UN VALOR POSITIVO" << endl;
        return false;
    }

    cout << "NOMBRE: ";
    cargarCadena(nombre, 29);
    setNombre(nombre);

    cout << "APELLIDO: ";
    cargarCadena(apellido, 29);
    setApellido(apellido);

    cout << "TELEFONO: ";
    cargarCadena(telefono, 39);
    setTelefono(telefono);
    estado = 1;
    setEstado(estado);
    return true;
}

void Cliente::Mostrar()
{
    //if(estado){
        cout << "DNI: " << DNI << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "APELLIDO: " << apellido << endl;
        cout << "TELEFONO: " << telefono << endl;
    //}
}

/// SETS
bool Cliente::setDNI(int nD)
{
    if(nD > 0){
        DNI = nD;
        return true;
    }
    return false;
}
void Cliente::setNombre(const char *nom){strcpy(nombre, nom);}
void Cliente::setApellido(const char *ape){strcpy(apellido, ape);}
void Cliente::setTelefono(const char *tel){strcpy(telefono, tel);}
void Cliente::setEstado(bool e){estado = e;}

/// GETS
int Cliente::getDNI(){return DNI;}
const char *Cliente::getNombre(){return nombre;}
const char *Cliente::getApellido(){return apellido;}
const char *Cliente::getTelefono(){return telefono;}
bool Cliente::getEstado(){return estado;}

/// DESTRUCTOR
Cliente::~Cliente()
{
    //dtor
}

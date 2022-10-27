#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente()
{
    DNI = 0;
    strcpy(nombre, "SIN DATO");
    strcpy(apellido, "SIN DATO");
    strcpy(telefono, "SIN DATO");
    strcpy(email, "SIN DATO");
    idCuenta = 0;
    estado = false;
}

/// CARGAR
bool Cliente::Cargar(int nD, int idC){
    if(!setDNI(nD)){
        gotoxy(42, 20);
        cout << "EL DNI DEBE SER UN VALOR POSITIVO" << endl;
        return false;
    }
    gotoxy(42, 20);
    cout << "NOMBRE: ";
    cargarCadena(nombre, 29);
    setNombre(nombre);
    gotoxy(42, 21);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 29);
    setApellido(apellido);
    gotoxy(42, 22);
    cout << "TELEFONO: ";
    cargarCadena(telefono, 39);
    setTelefono(telefono);
    gotoxy(42, 23);
    cout << "EMAIL: ";
    cargarCadena(email, 39);
    setEmail(email);

    setIdCuenta(idC);

    estado = 1;
    setEstado(estado);
    return true;
}

void Cliente::Mostrar()
{
    if(estado){
        gotoxy(34, 20);
        cout << "DNI: " << DNI;
        gotoxy(34, 21);
        cout << "NOMBRE: " << nombre;
        gotoxy(34, 22);
        cout << "APELLIDO: " << apellido;
        gotoxy(34, 23);
        cout << "TELEFONO: " << telefono;
        gotoxy(34, 24);
        cout << "EMAIL: " << email;
        gotoxy(34, 25);
        cout << "ID CUENTA: " << idCuenta;
    }
}

/// SETS
bool Cliente::setDNI(int nD){
    if(nD > 0){
        DNI = nD;
        return true;
    }
    return false;
}
void Cliente::setNombre(const char *nom){strcpy(nombre, nom);}
void Cliente::setApellido(const char *ape){strcpy(apellido, ape);}
void Cliente::setTelefono(const char *tel){strcpy(telefono, tel);}
void Cliente::setEmail(const char *e){strcpy(email, e);}
void Cliente::setIdCuenta(int idC){idCuenta = idC;}
void Cliente::setEstado(bool e){estado = e;}

/// GETS
int Cliente::getDNI(){return DNI;}
const char *Cliente::getNombre(){return nombre;}
const char *Cliente::getApellido(){return apellido;}
const char *Cliente::getTelefono(){return telefono;}
const char *Cliente::getEmail(){return email;}
int Cliente::getIdCuenta(){return idCuenta;}
bool Cliente::getEstado(){return estado;}

/// DESTRUCTOR
Cliente::~Cliente()
{
    //dtor
}

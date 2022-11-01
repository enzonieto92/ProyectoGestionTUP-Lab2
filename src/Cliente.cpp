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
        rlutil::hidecursor();
        gotoxy(42, 20);
        cout << "EL DNI DEBE SER UN VALOR POSITIVO" << endl;
        return false;
    }
    gotoxy(42, 20);
    cout << "NOMBRE: ";
    gotoxy(42, 21);
    cout << "APELLIDO: ";
    gotoxy(42, 22);
    cout << "TELEFONO: ";
    gotoxy(42, 23);
    cout << "EMAIL: ";
    gotoxy(50, 20);
    rlutil::showcursor();
    cargarCadena(nombre, 29);
    setNombre(nombre);
    gotoxy(52, 21);
    cargarCadena(apellido, 29);
    setApellido(apellido);
    gotoxy(52, 22);
    cargarCadena(telefono, 39);
    setTelefono(telefono);
    gotoxy(50, 23);
    cargarCadena(email, 39);
    setEmail(email);
    rlutil::hidecursor();
    setIdCuenta(idC);

    estado = 1;
    setEstado(estado);
    return true;
}

void Cliente::Cargar(){

    gotoxy(42, 23);
    cout << "NOMBRE: ";
    gotoxy(42, 24);
    cout << "APELLIDO: ";
    gotoxy(42, 25);
    cout << "TELEFONO: ";
    gotoxy(50, 23);
    rlutil::showcursor();
    cargarCadena(nombre, 29);
    setNombre(nombre);
    gotoxy(52, 24);
    cargarCadena(apellido, 29);
    setApellido(apellido);
    gotoxy(52, 25);
    cargarCadena(telefono, 39);
    setTelefono(telefono);
    rlutil::hidecursor();


    setEstado(true);
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

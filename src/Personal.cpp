#include "Personal.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Personal::Personal(){
    ID = 0;
    strcpy(nombre, "SIN DATO");
    strcpy(telefono, "SIN DATO");
    strcpy(apellido, "SIN DATO");
    sueldo = 0;
    estado = false;
}

/// CARGAR

bool Personal::cargar(int var){
    ID = var;
    gotoxy (41, 18);
    cout << "NONMBRE: ";
    cargarCadena(nombre,29);
    gotoxy (41, 20);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 39);
    gotoxy (41, 22);
    cout << "TELEFONO: ";
    cargarCadena(telefono, 29);
    gotoxy (41, 24);
    cout << "SUELDO: ";
    cin >> var;
    if(setSueldo(var)==false){
        return false;
    }
    estado = true;
    return true;
}

/// MOSTRAR

bool Personal::mostrar(){
    if(estado == true){
        cout << ID << " " << nombre << " " << apellido << ": " << telefono << " " << sueldo << endl;
        return true;
    }
    return false;
}

/// SETS

void Personal::setIDPersonal(int var){ID = var;}
void Personal::setNombre(const char *nom){strcpy(nombre, nom);}
void Personal::setApellido(const char *ape){strcpy(apellido, ape);}
void Personal::setTelefono(const char *tel){strcpy(telefono, tel);}
bool Personal::setSueldo(float var){
    if(var > 0){
        sueldo = var;
        return true;
    }
    return false;
}
void Personal::setEstado(bool e){estado = e;}

/// GETS

int Personal::getIDPersonal(){return ID;}
const char *Personal::getNombre(){return nombre;}
const char *Personal::getApellido(){return apellido;}
const char *Personal::getTelefono(){return telefono;}
float Personal::getSueldo(){return sueldo;}
bool Personal::getEstado(){return estado;}

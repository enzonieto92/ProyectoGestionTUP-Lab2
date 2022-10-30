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
    estado = false;
}

/// CARGAR

void Personal::cargar(int var){
    ID = var;
    gotoxy (42, 18);
    cout << "NONMBRE: ";
    cargarCadena(nombre,29);
    gotoxy (42, 20);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 39);
    gotoxy (42, 22);
    cout << "TELEFONO: ";
    cargarCadena(telefono, 29);
    estado = true;
}

/// MOSTRAR

void Personal::mostrar(){
    if(estado == true){
        cout << ID << " " << nombre << " " << apellido << ": "<< telefono;
    }
}

/// SETS

void Personal::setIDPersona(int var){ID = var;}
void Personal::setNombre(const char *nom){strcpy(nombre, nom);}
void Personal::setApellido(const char *ape){strcpy(apellido, ape);}
void Personal::setTelefono(const char *tel){strcpy(telefono, tel);}
void Personal::setEstado(bool e){estado = e;}

/// GETS

int Personal::getIDPersona(){return ID;}
const char *Personal::getNombre(){return nombre;}
const char *Personal::getApellido(){return apellido;}
const char *Personal::getTelefono(){return telefono;}
bool Personal::getEstado(){return estado;}

/// DESTRUCTOR
Personal::~Personal()
{

}


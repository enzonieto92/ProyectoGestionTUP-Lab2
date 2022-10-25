#include "Persona.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Persona::Persona(){
    ID = 0;
    strcpy(nombre, "SIN DATO");
    strcpy(telefono, "SIN DATO");
    strcpy(apellido, "SIN DATO");
    estado = false;
}

/// CARGAR

void Persona::cargar(int var){
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

void Persona::mostrar(){
    if(estado == true){
        cout << ID << " " << nombre << " " << apellido << ": "<< telefono;
    }
}

/// SETS

void Persona::setIDPersona(int var){ID = var;}
void Persona::setNombre(const char *nom){strcpy(nombre, nom);}
void Persona::setApellido(const char *ape){strcpy(apellido, ape);}
void Persona::setTelefono(const char *tel){strcpy(telefono, tel);}
void Persona::setEstado(bool e){estado = e;}

/// GETS

int Persona::getIDPersona(){return ID;}
const char *Persona::getNombre(){return nombre;}
const char *Persona::getApellido(){return apellido;}
const char *Persona::getTelefono(){return telefono;}
bool Persona::getEstado(){return estado;}

/// DESTRUCTOR
Persona::~Persona()
{

}


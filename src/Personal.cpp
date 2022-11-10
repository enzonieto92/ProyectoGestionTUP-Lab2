#include "Personal.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Personal::Personal(){
    ID = 0;
    strcpy(nombre, "SIN DATO");
    strcpy(apellido, "SIN DATO");
    sueldo = 0;
    estado = false;
}

/// CARGAR

bool Personal::cargar(int var){
    ID = var;
    gotoxy (41, 18);
    cout << "NONMBRE: ";
    gotoxy (41, 20);
    cout << "APELLIDO: ";
    gotoxy (41, 22);
    cout << "SUELDO: ";
    gotoxy(50,18);
    cargarCadena(nombre,29);
    gotoxy(51,20);
    cargarCadena(apellido, 39);
    gotoxy(49,22);
    cin >> var;
    rlutil::hidecursor();
    if(setSueldo(var)==false){
        return false;
    }
    estado = true;
    return true;
}

/// MOSTRAR

bool Personal::mostrar(int var){
    if(estado == true){
        gotoxy(31,20+var);
        cout << ID << endl;
        gotoxy(38,20+var);
        cout << nombre << endl;
        gotoxy(50,20+var);
        cout << apellido << endl;
        gotoxy(64,20+var);
        cout << sueldo << endl;
        return true;
    }
    return false;
}

/// SETS

void Personal::setIDPersonal(int var){ID = var;}
void Personal::setNombre(const char *nom){strcpy(nombre, nom);}
void Personal::setApellido(const char *ape){strcpy(apellido, ape);}
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
float Personal::getSueldo(){return sueldo;}
bool Personal::getEstado(){return estado;}

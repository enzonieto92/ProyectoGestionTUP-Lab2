#include "Cuentas.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Cuenta::Cuenta(){
    ID = 0;
    strcpy(nombre, "SIN DATO");
    strcpy(apellido, "SIN DATO");
    monto = 1;
    estado = false;
}

bool Cuenta::cargar(int var){
    int mon;
    Fecha fecha;
    ID = var;
    gotoxy (42, 18);
<<<<<<< HEAD
    cout << "NOMBRE: ";
=======
    cout << "NONMBRE: ";
>>>>>>> aab545b4c42a989b842ddf4279293dff3faa5b35
    cargarCadena(nombre,29);
    gotoxy (42, 20);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 39);
    gotoxy (42, 22);
    cout << "MONTO: ";
    cin >> mon;
    if(setMonto(mon)==false){
        return false;
    }
    estado = true;
    return true;
}

void Cuenta::mostrar(){
    if(estado == true){
        gotoxy(38,20);
        cout << ID << " " << nombre << " " << apellido << endl;
        gotoxy (38, 21);
        cout << "FECHA DE EMISION: ";
        gotoxy (56, 21);
        fechaEmision.Mostrar();
        gotoxy (38, 22);
        cout << "MONTO: " << monto << endl;
    }
}

/// SETS

void Cuenta::setID(int var){ID = var;}
void Cuenta::setFechaEmision(Fecha fecha){fechaEmision = fecha;}
void Cuenta::setNombre(const char *V){strcpy(nombre,V);}
void Cuenta::setApellido(const char *V){strcpy(apellido,V);}
bool Cuenta::setMonto(float var){
    if(var >0){
        monto = var;
        return true;
    }
    return false;
}
void Cuenta::setEstado(bool ban){estado = ban;}

/// GETS

int Cuenta::getID(){return ID;}
Fecha Cuenta::getFechaEmision(){return fechaEmision;}
const char *Cuenta::getNombre(){return nombre;}
const char *Cuenta::getApellido(){return apellido;}
float Cuenta::getMonto(){return monto;}
bool Cuenta::getEstado(){return estado;}

Cuenta::~Cuenta(){
    //dtor
}





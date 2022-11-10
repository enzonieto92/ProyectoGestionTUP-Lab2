#include "Cuentas.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

Cuenta::Cuenta(){
    ID = 0;
    monto = 0;
    estado = false;
}

bool Cuenta::mostrar(){
    if(estado == true){
        gotoxy(34, 20);
        cout << "FECHA DE EMISION: " << endl;
        gotoxy(44,21);
        cout << "NUMERO DE ID: " << ID << endl;
        gotoxy(46,22);
        cout << "MONTO: " << monto << endl;
        return true;
    }
    return false;
}

/// SETS

void Cuenta::setID(int var){ID = var;}
void Cuenta::setFechaEmision(Fecha fecha){fechaEmision = fecha;}
bool Cuenta::setMonto(float var){
    if(var >=0){
        monto = monto - var;
        return true;
    }
    return false;
}
void Cuenta::setEstado(bool ban){estado = ban;}

/// GETS

int Cuenta::getID(){return ID;}
Fecha Cuenta::getFechaEmision(){return fechaEmision;}
float Cuenta::getMonto(){return monto;}
bool Cuenta::getEstado(){return estado;}

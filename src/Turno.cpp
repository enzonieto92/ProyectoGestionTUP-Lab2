#include "Turno.h"
#include <iostream>
#include "Funciones.h"
using namespace std;

// CONSTRUCTOR
Turno::Turno(){
    idTurno = 0;
    DNI = 0;
    tipoServicio = 0;
    estado = false;
}

Turno::Turno(int id = 0, int d = 0, int ts = 0, bool e = false){
    idTurno = id;
    DNI = d;
    tipoServicio = ts;
    estado = e;
}

// DESTRUCTOR
Turno::~Turno(){
    // dtor
}

// METODOS
bool Turno::Cargar(int idT, Fecha _fecha, int nD, int ts){
    setIdTurno(idT);
    setFechaServicio(_fecha);
    setDNI(nD);
    setTipoServicio(ts);
    estado = 1;
    setEstado(estado);
    return true;
}

void Turno::Mostrar(){
    gotoxy(42, 20);
    cout << "ID TURNO: " << idTurno << endl;
    gotoxy(42, 21);
    cout << "FECHA DE TURNO: ";
    gotoxy(42, 22);
    fechaServicio.Mostrar();
    gotoxy(42, 23);
    cout << "DNI: " << DNI << endl;
    gotoxy(42, 24);
    cout << "TIPO DE SERVICIO: " << tipoServicio << endl;
}

// SETS
void Turno::setIdTurno(int t){idTurno = t;}
void Turno::setFechaServicio(Fecha f){fechaServicio = f;}
void Turno::setDNI(int d){DNI = d;}
void Turno::setTipoServicio(int s){tipoServicio = s;}
void Turno::setEstado(bool e){estado = e;}

// GETS
int Turno::getIdTurno(){return idTurno;}
Fecha Turno::getFechaServicio(){return fechaServicio;}
int Turno::getDNI(){return DNI;}
int Turno::getTipoServicio(){return tipoServicio;}
bool Turno::getEstado(){return estado;}

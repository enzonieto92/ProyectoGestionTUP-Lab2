#include "Turno.h"
#include <iostream>
#include "Funciones.h"
using namespace std;

// CONSTRUCTOR
Turno::Turno(){
    idTurno = 0;
    idCuenta = 0;
    tipoServicio = 0;
    iDpersonal = 0;
    estado = false;
}

Turno::Turno(int idC = 0, int d = 0, int ts = 0, int idP = 0, bool e = false){
    idTurno = idC;
    idCuenta = d;
    tipoServicio = ts;
    iDpersonal = idP;
    estado = e;
}

// DESTRUCTOR
Turno::~Turno(){
    // dtor
}

// METODOS
bool Turno::Cargar(int idT, Fecha _fecha, int idC, int ts, int idP){
    setIdTurno(idT);
    setFechaServicio(_fecha);
    setIdCuenta(idC);
    setTipoServicio(ts);
    setIdPersonal(idP);
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
    fechaServicio.MostrarHora();
    gotoxy(42, 23);
    cout << "ID CLIENTE: " << idCuenta << endl;
    gotoxy(42, 24);
    cout << "TIPO DE SERVICIO: " << tipoServicio << endl;
    gotoxy(42, 25);
    cout << "ID PERSONAL: " << iDpersonal << endl;
}

// SETS
void Turno::setIdTurno(int t){idTurno = t;}
void Turno::setFechaServicio(Fecha f){fechaServicio = f;}
void Turno::setIdCuenta(int d){idCuenta = d;}
void Turno::setTipoServicio(int s){tipoServicio = s;}
void Turno::setIdPersonal(int p){iDpersonal = p;}
void Turno::setEstado(bool e){estado = e;}

// GETS
int Turno::getIdTurno(){return idTurno;}
Fecha Turno::getFechaServicio(){return fechaServicio;}
int Turno::getIdCuenta(){return idCuenta;}
int Turno::getTipoServicio(){return tipoServicio;}
int Turno::getIdPersonal(){return iDpersonal;}
bool Turno::getEstado(){return estado;}

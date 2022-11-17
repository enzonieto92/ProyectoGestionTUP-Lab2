#include "Turno.h"
#include <iostream>
#include "Funciones.h"
using namespace std;

// CONSTRUCTOR
Turno::Turno() {

estado = true;
}

Turno::~Turno() {

}
void Turno::Mostrar(){
    gotoxy(42, 24);
    cout << "TIPO DE SERVICIO: ";
}

// SETS
void Turno::setFecha(Fecha& f){fechaServicio = f;}
void Turno::setEstado(bool e){estado = e;}
void Turno::setEstadoCliente(bool e){cliente.setEstado(e);}
void Turno::setCliente(Cliente aux){
cliente = aux;
}
void Turno::setServicio(Servicio aux){
servicio = aux;
}

// GETS
Fecha Turno::getFechaServicio(){return fechaServicio;}
bool Turno::getEstado(){return estado;}
Cliente Turno::getCliente(){return cliente;}
Servicio Turno::getServicio(){return servicio;}
bool Turno::operator ==(Turno aux){
if ((fechaServicio += aux.getFechaServicio())
    && cliente == aux.getCliente()
    && servicio == aux.getServicio()){
        return true;
    }
else{
    return false;
}

}

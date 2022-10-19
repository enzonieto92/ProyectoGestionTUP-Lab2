#include "Fecha.h"
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

Fecha::Fecha(){
    time_t tiempo;
    struct tm *hoy;
    tiempo = time(NULL);
    hoy = localtime(&tiempo);

    dia = hoy -> tm_mday;
    mes = hoy -> tm_mon + 1;
    anio = 1900 + hoy -> tm_year;

}

bool Fecha::Cargar(){
    cout << "DIA: ";
    cin >> dia;
    if(!setDia(dia)){
        cout << "EL DIA DEBE ESTAR ENTRE 1 Y 31" << endl;
        return false;
    }
    cout << "MES: ";
    cin >> mes;
    if(!setMes(mes)){
        cout << "EL MES DEBE ESTAR ENTRE 1 Y 12" << endl;
        return false;
    }
    cout << "ANIO: ";
    cin >> anio;
    if(!setAnio(anio)){
        cout << "EL AONIO DEBE SER POSTIVO" << endl;
        return false;
    }
    return true;
}

void Fecha::Mostrar(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}
void Fecha::Mostrar_hora(){

}

/// SETS
bool Fecha::setDia(int d){
    if (d >= 1 && d <= 31){
        dia = d;
        return true;
    }
    return false;
}
bool Fecha::setMes(int m){
    if (m >= 1 && m <= 12){
        mes = m;
        return true;
    }
    return false;
}
bool Fecha::setAnio(int a){
    if (a >= 0){
        anio = a;
        return true;
    }
    return false;
}

/// GETS
int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}

/// DESTRUCTOR
Fecha::~Fecha()
{
    //dtor
}

/// VALIDAR FECHA TURNO
bool Fecha::validarFechaTurno(Fecha f){
    time_t tiempo;
    struct tm *hoy;

    tiempo = time(NULL);
    hoy = localtime(&tiempo);
    if(f.getAnio() < (1900 + hoy -> tm_year)){
        cout << "EL ANIO DEBE SER MAYOR O IGUAL AL ACTUAL" << endl;
        return false;
    }
    else{
        if(f.getMes() < (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
        cout << "EL MES DEBE SER MAYOR O IGUAL AL DEL CORRIENTE ANIO" << endl;
        return false;
        }
        else{
            if(f.getDia() < hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                cout << "LA FECHA DEBE SER MAYOR O IGUAL A LA ACTUAL" << endl;
                return false;
            }
        }
    }
    return true;
}

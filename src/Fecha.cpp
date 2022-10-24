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
    hora = hoy -> tm_hour;
    minuto = hoy -> tm_min;
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
    cout << "HORA: ";
    cin >> hora;
    if(!setHora(hora)){
        cout << "LA HORA DEBE ESTAR ENTRE 0 - 23" << endl;
        return false;
    }
    cout << "MINUTO: ";
    cin >> minuto;
    if(!setAnio(anio)){
        cout << "EL MINUTO DEBE ESTAR ENTRE 0 - 59" << endl;
        return false;
    }
    return true;
}

void Fecha::Mostrar(){
    cout << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto << endl;
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
bool Fecha::setHora(int h){
    if (h >= 0 && h <= 23){
        hora = h;
        return true;
    }
    return false;
}
bool Fecha::setMinuto(int m){
    if (m >= 0 && m <= 59){
        minuto = m;
        return true;
    }
    return false;
}

/// GETS
int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}
int Fecha::getHora(){return hora;}
int Fecha::getMinuto(){return minuto;}

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
        cout << "EL ANIO DEBE SER MAYOR O IGUAL AL: " << (1900 + hoy -> tm_year) << endl;
        return false;
    }
    else{
        if(f.getMes() < (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
        cout << "EL MES DEBE SER MAYOR O IGUAL AL " << (hoy -> tm_mon + 1) << " DEL CORRIENTE ANIO " << (1900 + hoy -> tm_year)<< endl;
        return false;
        }
        else{
            if(f.getDia() < hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                cout << "EL DIA DEBE SER MAYOR O IGUAL A " << hoy -> tm_mday << " DEL MES ACTUAL " << (hoy -> tm_mon + 1) << endl;
                return false;
            }
            else{
                if(f.getHora() < hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                    cout << "LA HORA DEBE SER MAYOR O IGUAL A LA ACTUAL " << hoy -> tm_hour << endl;
                    return false;
                }
                else{
                    if(f.getMinuto() < hoy -> tm_min && f.getHora() == hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                        cout << "LA HORA DEBE SER MAYOR O IGUAL A LA ACTUAL ";
                        f.Mostrar();
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

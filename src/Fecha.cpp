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
    gotoxy(31, 21);
    cout << "DIA:";
    cin >> dia;
    if(!setDia(dia)){
        gotoxy(32, 23);
        cout << "EL DIA DEBE ESTAR ENTRE 1 Y 31" << endl;
        return false;
    }
    gotoxy(38, 21);
    cout << "MES:";
    cin >> mes;
    if(!setMes(mes)){
        gotoxy(32, 23);
        cout << "EL MES DEBE ESTAR ENTRE 1 Y 12" << endl;
        return false;
    }
    gotoxy(45, 21);
    cout << "ANIO:";
    cin >> anio;
    if(!setAnio(anio)){
        gotoxy(32, 23);
        cout << "EL AONIO DEBE SER POSTIVO" << endl;
        return false;
    }
    gotoxy(57, 21);
    cout << "HR:";
    cin >> hora;
    if(!setHora(hora)){
        gotoxy(32, 23);
        cout << "LA HORA DEBE ESTAR ENTRE 0 - 23" << endl;
        return false;
    }
    gotoxy(63, 21);
    cout << "MIN:";
    cin >> minuto;
    if(!setMinuto(minuto)){
        gotoxy(32, 23);
        cout << "EL MINUTO DEBE ESTAR ENTRE 0 - 59" << endl;
        return false;
    }
    return true;
}

void Fecha::Mostrar(){
    cout << dia << "/" << mes << "/" << anio << " ";
    if(hora < 10) cout << "0";
    cout << hora << ":";
    if(minuto < 10) cout << "0";
    cout << minuto;
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
        gotoxy(31, 23);
        cout << "EL ANIO DEBE SER MAYOR O IGUAL AL: " << (1900 + hoy -> tm_year);
        return false;
    }
    else{
        if(f.getMes() < (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
        gotoxy(31, 23);
        cout << "MES DEBE SER MAYOR/IGUAL AL " << (hoy -> tm_mon + 1) << " DEL " << (1900 + hoy -> tm_year);
        return false;
        }
        else{
            if(f.getDia() < hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                gotoxy(31, 23);
                cout << "EL DIA DEBE SER MAYOR/IGUAL A " << hoy -> tm_mday << " DEL " << (hoy -> tm_mon + 1);
                return false;
            }
            else{
                if(f.getHora() < hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                    gotoxy(31, 23);
                    cout << "LA HORA DEBE SER MAYOR/IGUAL A " << hoy -> tm_hour;
                    return false;
                }
                else{
                    if(f.getMinuto() < hoy -> tm_min && f.getHora() == hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                        gotoxy(31, 23);
                        cout << "LA HORA DEBE SER MAYOR/IGUAL A " << hoy -> tm_hour << ":" << hoy -> tm_min;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

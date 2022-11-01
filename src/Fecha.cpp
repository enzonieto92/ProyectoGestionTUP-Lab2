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

bool Fecha::esBisiesto(int a){
    bool bisiesto = false;
    if(a % 4 == 0){
        bisiesto = true;
    }
    if((a % 100 == 0) && (a % 400 != 0)){
        bisiesto = false;
    }
    return bisiesto;
}

bool Fecha::Cargar(){
    int diaFin;
    gotoxy(31, 21);
    cout << "ANIO:";
    cin >> anio;
    if(!setAnio(anio)){
        rlutil::hidecursor();
        gotoxy(32, 23);
        cout << "EL AONIO DEBE SER POSTIVO";
        return false;
    }
    gotoxy(41, 21);
    cout << "MES:";
    cin >> mes;
    if(!setMes(mes)){
        rlutil::hidecursor();
        gotoxy(32, 23);
        cout << "EL MES DEBE ESTAR ENTRE 1 Y 12";
        return false;
    }
    gotoxy(48, 21);
    cout << "DIA:";
    cin >> dia;
    if(!setDia(dia, diaFin)){
        rlutil::hidecursor();
        gotoxy(32, 23);
        cout << "EL DIA DEBE ESTAR ENTRE 1 Y " << diaFin;
        return false;
    }
    gotoxy(57, 21);
    cout << "HR:";
    cin >> hora;
    if(!setHora(hora)){
        rlutil::hidecursor();
        gotoxy(32, 23);
        cout << "LA HORA DEBE ESTAR ENTRE 0 - 23";
        return false;
    }
    gotoxy(63, 21);
    cout << "MIN:";
    cin >> minuto;
    if(!setMinuto(minuto)){
        rlutil::hidecursor();
        gotoxy(32, 23);
        cout << "EL MINUTO DEBE ESTAR ENTRE 0 - 59";
        return false;
    }
    return true;
}

void Fecha::MostrarHora(){
    cout << dia << "/" << mes << "/" << anio << " ";
    if(hora < 10) cout << "0";
    cout << hora << ":";
    if(minuto < 10) cout << "0";
    cout << minuto;
}

void Fecha::MostrarFecha(){
     cout << dia << "/" << mes << "/" << anio << " ";
}

/// SETS
bool Fecha::setDia(int d, int &diaFin){
    int vMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31};
    if(esBisiesto(anio)){
        vMes[1] = 29;
    }
    diaFin = vMes[mes - 1];
    if (d >= 1 && d <= diaFin){
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

/// SOBRECARGA OPERADOR FECHA < FECHA
bool Fecha::operator < (Fecha aux){
    if(anio < aux.getAnio()){
        return true;
    }
    else{
        if(mes < aux.getMes() && anio == aux.getAnio()){
        return true;
        }
        else{
            if(dia < aux.getDia() && mes == aux.getMes() && anio == aux.getAnio()){
                return true;
            }
            else{
                if(hora < aux.getHora() && dia == aux.getDia() && mes == aux.getMes() && anio == aux.getAnio()){
                    return true;
                }
                else{
                    if(minuto < aux.getMinuto() && hora == aux.getHora() && dia == aux.getDia() && mes == aux.getMes() && anio == aux.getAnio()){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

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

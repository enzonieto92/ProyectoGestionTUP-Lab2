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
    diaFin = vMes[mes - 1];
    }
Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
    hora = 0;
    minuto = 0;
    diaFin = vMes[mes - 1];
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

    Fecha Actual;
    gotoxy(32, 20);
    cout << "DIA:";
    gotoxy(39, 20);
    cout << "/";
    gotoxy(42, 20);
    cout << "/";
    gotoxy(58, 20);
    cout << "HR: ";
    gotoxy(64, 20);
    cout << ":";

    bool scroll_fecha = true, scroll_hora = true;
    minuto = minuto-(minuto%30);
    while(scroll_fecha){

    rlutil::hidecursor();
    if (dia < 10){
    gotoxy(37, 20);
    cout << "0";
    }
    else{
    gotoxy(37, 20);
    }
    cout << dia;
    if (mes < 10){
    gotoxy(40, 20);
    cout << "0";
    }
    else{
    gotoxy(40, 20);
    }
    cout << mes;
    gotoxy(43, 20);
    cout <<anio;
    gotoxy(62, 20);
    if (hora < 10){
        cout <<"0";
    }
    cout <<hora;
    gotoxy(65, 20);
    if (minuto == 0){
        cout <<"0";
    }
    cout <<minuto;
    gotoxy(47, 20);
    rlutil::showcursor();

        if(esBisiesto(anio)){
            vMes[1] = 29;
        }
        switch (rlutil::getkey()){
    case 14: //FLECHA HACIA ARRIBA
        dia ++;
        if (dia > diaFin){
            mes++;
            dia = 1;
        }
        if (mes > 12){
            anio++;
            mes = 1;
        }
    break;
    case 15: //FLECHA HACIA ABAJO
        if (dia <= Actual.getDia()){
            if (mes == Actual.getMes()){
                if (anio ==Actual.getAnio()){

                break;
                };
            }

        }
        dia --;
        if (dia < 1){
            mes --;
            if (mes < 1){
                anio--;
                mes = 12;
            }
            diaFin = vMes[mes-1];
            dia = diaFin;
            break;
        }
        break;
    case 1: //TECLA ENTER

        scroll_fecha = false;
        break;


        }

    diaFin = vMes[mes-1];
    }
    while(scroll_hora){
        rlutil::hidecursor();
        if (hora < 10){
            gotoxy(62, 20);
            cout <<"0" <<hora;
        }
        else{
            gotoxy(62, 20);
            cout <<hora;
        }
            gotoxy(65, 20);
            cout <<minuto;
            gotoxy(67, 20);
            rlutil::showcursor();
            switch (rlutil::getkey()){
                case 14:
                    minuto +=30;
                    if (minuto > 30){
                        minuto = 0;
                        hora++;
                        if (hora >23){
                            hora = 23;
                            minuto = 30;
                        }
                    }
                    break;
                case 15:
                    if (hora <= 0){
                        if (minuto == 0){
                            break;
                        }
                    }
                    minuto -=30;
                    if (minuto < 0){
                        hora --;
                        minuto = 30;
                    }

                    if (hora < 1){
                        hora = 0;
                        minuto = 0;
                    }
                    break;
                case 1:
                    scroll_hora = false;

            }

    }
        return true;
}

void Fecha::Mostrar(int x,int y){
    if (dia < 10){
        if (mes < 10){
        gotoxy(x, y);
        cout << dia << "/" << "0" << mes << "/" << anio;
        }
        else{
        gotoxy(x, y);
        cout << dia << "/" << mes << "/" << anio;
        }
    }
    else{
        if (mes < 10){
        gotoxy(x-1, y);
        cout << dia << "/" << "0" << mes << "/" << anio;
        }
        else{
        gotoxy(x-1, y);
        cout << dia << "/" << mes << "/" << anio;
        }
        }
}

/// SETS
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
void Fecha::setFecha(){

    Fecha Inicial(3, 11, 2022);
    gotoxy(30, 15);
    cout << "ELIJA LA FECHA:";
    bool scroll_fecha = true;

while(scroll_fecha){
    rlutil::hidecursor();
    if (dia < 10){
    gotoxy(46, 15);
    cout <<" ";
    }
    else{
    gotoxy(46, 15);
    }
    cout << dia;
    if (mes < 10){
    gotoxy(49, 15);
    cout << "0";
    }
    else{
    gotoxy(49, 15);
    }
    cout << mes;
    gotoxy(52, 15);
    cout <<anio;
    gotoxy(56, 15);
    rlutil::showcursor();
    switch (rlutil::getkey()){
    case 14: //FLECHA HACIA ARRIBA
        dia ++;
        if (dia > diaFin){
            mes++;
            dia = 1;
        }
        if (mes > 12){
            anio++;
            mes = 1;
        }
    break;
    case 15: //FLECHA HACIA ABAJO
        if (dia <= Inicial.getDia()){
            if (mes == Inicial.getMes()){
                if (anio == Inicial.getAnio()){

                break;
                };
            }

        }
        dia --;
        if (dia < 1){
            mes --;
            if (mes < 1){
                anio--;
                mes = 12;
            }
            diaFin = vMes[mes-1];
            dia = diaFin;
            break;
        }
        break;
    case 1: //TECLA ENTER
        scroll_fecha = false;
        rlutil::hidecursor();
        break;


        }

}

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
void Fecha::operator = (Fecha aux){
dia = aux.getDia();
mes = aux.getMes();
anio = aux.getAnio();
hora = aux.getHora();
minuto = aux.getMinuto();
}
bool Fecha::operator == (Fecha aux){
    if (anio == aux.getAnio() && mes == aux.getMes() && dia == aux.getDia()){
        return true;
    }
    else{
        return false;
    }

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

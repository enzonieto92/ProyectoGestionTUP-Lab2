#include "Texto.h"
#include <iostream>

using namespace std;

Texto::Texto(Origen &_coor){
    coor = _coor;
    opc = 1;
}

void Texto::mostrar_texto1(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+5, coor.y+1);
    cout <<"TURNOS";
    gotoxy(coor.x+4, coor.y+3);
    cout <<"CLIENTES";
    gotoxy(coor.x+4, coor.y+5);
    cout <<"PERSONAL";
    gotoxy(coor.x+4, coor.y+7);
    cout <<"SERVICIO";
    gotoxy(coor.x+5, coor.y+9);
    cout <<"CUENTA";
    gotoxy(coor.x+5, coor.y+11);
    cout <<"SALIR";
}

void Texto::mostrar_texto2(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+2, coor.y-5);
    cout << "MENU TURNOS";
    gotoxy(coor.x-3, coor.y+1);
    cout <<"AGREGAR";
    gotoxy(coor.x+8, coor.y+1);
    cout <<"MODIFICAR";
    gotoxy(coor.x-3, coor.y+3);
    cout <<"BUSCAR";
    gotoxy(coor.x+9, coor.y+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto3(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+2, coor.y-5);
    cout << "MENU CLIENTES";
    gotoxy(coor.x-7, coor.y+1);
    cout <<"AGREGAR";
    gotoxy(coor.x+5, coor.y+1);
    cout <<"MODIFICAR";
    gotoxy(coor.x+18, coor.y+1);
    cout <<"MOSTRAR";
    gotoxy(coor.x-7, coor.y+3);
    cout <<"ELIMINAR";
    gotoxy(coor.x+6, coor.y+3);
    cout <<"BUSCAR";
    gotoxy(coor.x+18, coor.y+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto4(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+2, coor.y-5);
    cout << "MENU PERSONAL";
    gotoxy(coor.x-7, coor.y+1);
    cout <<"AGREGAR";
    gotoxy(coor.x+5, coor.y+1);
    cout <<"MODIFICAR";
    gotoxy(coor.x+18, coor.y+1);
    cout <<"MOSTRAR";
    gotoxy(coor.x-7, coor.y+3);
    cout <<"ELIMINAR";
    gotoxy(coor.x+6, coor.y+3);
    cout <<"BUSCAR";
    gotoxy(coor.x+18, coor.y+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto5(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+2, coor.y-5);
    cout << "MENU SERVICIOS";
    gotoxy(coor.x-7, coor.y+1);
    cout <<"AGREGAR";
    gotoxy(coor.x+5, coor.y+1);
    cout <<"MODIFICAR";
    gotoxy(coor.x+18, coor.y+1);
    cout <<"MOSTRAR";
    gotoxy(coor.x-7, coor.y+3);
    cout <<"ELIMINAR";
    gotoxy(coor.x+6, coor.y+3);
    cout <<"BUSCAR";
    gotoxy(coor.x+18, coor.y+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto6(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+2, coor.y-5);
    cout << "MENU CUENTAS";
    gotoxy(coor.x-2, coor.y+1);
    cout <<"MODIFICAR";
    gotoxy(coor.x+11, coor.y+1);
    cout <<"MOSTRAR";
    gotoxy(coor.x-1, coor.y+3);
    cout <<"BUSCAR";
    gotoxy(coor.x+11, coor.y+3);
    cout <<"VOLVER";
}

void Texto::resaltar1(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x+5, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"TURNOS";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+4, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"CLIENTES";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x+4, coor.y+5);
            rlutil::setBackgroundColor(7);
            cout <<"PERSONAL";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x+4, coor.y+7);
            rlutil::setBackgroundColor(7);
            cout <<"SERVICIO";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.x+5, coor.y+9);
            rlutil::setBackgroundColor(7);
            cout <<"CUENTA";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.x+5, coor.y+11);
            rlutil::setBackgroundColor(7);
            cout <<"SALIR";
            rlutil::setBackgroundColor(0);
            break;
    }
}

void Texto::resaltar2(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x-3, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+8, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x-3, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x+9, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}

void Texto::resaltar3(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x-7, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+5, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x+18, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x-7, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.x+6, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.x+18, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar4(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x-7, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+5, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x+18, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x-7, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.x+6, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.x+18, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar5(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x-7, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+5, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x+18, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x-7, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.x+6, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.x+18, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar6(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x-2, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+11, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x-1, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x+11, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}

#include "Texto.h"
#include <iostream>
using namespace std;


Texto::Texto(origen _coor){
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
    cout <<"CONTACTO";
    gotoxy(coor.x+5, coor.y+7);
    cout <<"SALIR";
}
void Texto::mostrar_texto2(){
gotoxy(coor.x+8, coor.y-7);
cout <<"Peluqueria Erica Martinez";
gotoxy(coor.x+15, coor.y-5);
cout << "MENU TURNOS";
gotoxy(coor.x+5, coor.y+1);
cout <<"AGREGAR";
gotoxy(coor.x+17, coor.y+1);
cout <<"MODIFICAR";
gotoxy(coor.x+30, coor.y+1);
cout <<"MOSTRAR";
gotoxy(coor.x+5, coor.y+3);
cout <<"ELIMINAR";
gotoxy(coor.x+18, coor.y+3);
cout <<"BUSCAR";
gotoxy(coor.x+30, coor.y+3);
cout <<"VOLVER";
}

void Texto::mostrar_texto3(){
gotoxy(coor.x+8, coor.y-7);
cout <<"Peluqueria Erica Martinez";
gotoxy(coor.x+14, coor.y-5);
cout << "MENU CLIENTES";
gotoxy(coor.x+5, coor.y+1);
cout <<"AGREGAR";
gotoxy(coor.x+17, coor.y+1);
cout <<"MODIFICAR";
gotoxy(coor.x+30, coor.y+1);
cout <<"MOSTRAR";
gotoxy(coor.x+5, coor.y+3);
cout <<"ELIMINAR";
gotoxy(coor.x+18, coor.y+3);
cout <<"BUSCAR";
gotoxy(coor.x+30, coor.y+3);
cout <<"VOLVER";
}
void Texto::mostrar_texto4(){
gotoxy(coor.x+8, coor.y-7);
cout <<"Peluqueria Erica Martinez";
gotoxy(coor.x+14, coor.y-5);
cout << "MENU CONTACTOS";
gotoxy(coor.x+5, coor.y+1);
cout <<"AGREGAR";
gotoxy(coor.x+17, coor.y+1);
cout <<"MODIFICAR";
gotoxy(coor.x+30, coor.y+1);
cout <<"MOSTRAR";
gotoxy(coor.x+5, coor.y+3);
cout <<"ELIMINAR";
gotoxy(coor.x+18, coor.y+3);
cout <<"BUSCAR";
gotoxy(coor.x+30, coor.y+3);
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
            cout <<"CONTACTO";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x+5, coor.y+7);
            rlutil::setBackgroundColor(7);
            cout <<"SALIR";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar2(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.x+5, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+17, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x+30, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.x+5, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.x+18, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.x+30, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
